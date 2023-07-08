#include "../includes/Server.hpp"

extern bool g_shutdown;

// --------------------CONSTRUCTOR && DECONSTRUCTOR--------------------

Server::Server(int port, std::string password) : 
	_name("irc"),
	_port(port),
	_password(password),
	_operatorPassword(password),
	_epoll_fd(-1)
{
    openSocket();
    bindSocket();
    listenSocket();
    initCommands();
    std::cout << "Server created" << std::endl;
    startServer();
}

Server::~Server() 
{
    close(_socket_fd);
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
		delete *it;
	for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
		delete *it;
}

// --------------------SERVER--------------------

void Server::openSocket() {
    _socket_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (_socket_fd < 0)
		throw std::runtime_error("Error: Cannot open socket");
}

void Server::bindSocket() {
    _server_address.sin_family = AF_INET;
	_server_address.sin_addr.s_addr = INADDR_ANY;
    _server_address.sin_port = htons(_port);
    memset(_server_address.sin_zero, 0, sizeof(_server_address.sin_zero));

    if (bind(_socket_fd, reinterpret_cast<struct sockaddr *>(&_server_address),
				sizeof(struct sockaddr)) < 0)
		throw std::runtime_error("Error: Cannot bind socket");
}

void Server::listenSocket() {
    if (listen(_socket_fd, 5) < 0)
		throw std::runtime_error("Error: Cannot listen to socket");
}

// Function to set up the epoll instance and add the server socket to it
int Server::setupEpoll() {
    setEpollfd(epoll_create1(0));
    if (_epoll_fd == -1)
        throw std::runtime_error("Failed to create epoll file descriptor");

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = _socket_fd;
    if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _socket_fd, &event))
        throw std::runtime_error("Failed to add socket file descriptor to epoll");

    return _epoll_fd;
}

void Server::startServer() {
    // Will contain client information when new connection
    struct sockaddr_in client_address;
    // Calcule the len for accept()
    socklen_t client_len = sizeof(client_address);

    int _epoll_fd = setupEpoll();

    // Create array of epoll events that will be filled by epoll_wait()
    struct epoll_event events[MAX_EVENTS];
    while (!g_shutdown) {
        // Wait for an event, block until event and if no event after 100ms return 0
        int num_fds = epoll_wait(_epoll_fd, events, MAX_EVENTS, 100); // timeout of 100ms
        // Loop over all fd that had events
        for (int i = 0; i < num_fds; i++) {
            // Handle new connection // If event occured on server fd it means new connection
            if (events[i].data.fd == _socket_fd)
                handleNewConnection(_epoll_fd, client_address, client_len);
            // Handle data from a client // Else event occured on client fd
            else
                handleNewMessage(events[i].data.fd);
        }
    }
    close(_epoll_fd);
}

// Function to handle a new client connection
void Server::handleNewConnection(int _epoll_fd, struct sockaddr_in &client_address, socklen_t &client_len) {
    int client_fd = accept(_socket_fd, (struct sockaddr*)&client_address, &client_len);
    if (client_fd < 0) {
        std::cerr << "Failed to accept client: " << std::endl;
        return;
    }

    // Use getnameinfo to get the hostname of the client
    // NI_MAXHOST specify the max size of a hostname
    char host[NI_MAXHOST];
    if (getnameinfo((struct sockaddr*)&client_address, client_len, host, sizeof(host), NULL, 0, NI_NUMERICHOST) != 0) {
        std::cerr << "Failed to get hostname of client" << std::endl;
        return;
    }
    std::string hostname(host);

    // Create a new Client object for the new client.
    Client* newClient = new Client(client_fd, hostname);

    // Make user PASS and NICK and USER

    // If first client, put him server OP
    if (this->getClients().size() == 0)
        newClient->setOp(true);

    // Add it in the client vector 
    addClient(newClient);


    // Add the new client fd (socket) to the epoll instance
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = client_fd;
    if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, client_fd, &event))
        throw std::runtime_error("Failed to add client socket file descriptor to epoll");
    std::cout << "New client connected!" << std::endl;
    newClient->sendMessage("To be able to join the server, make sure to use the PASS command to authenticate yourself.\n");
}

// Function to handle data from a client
void Server::handleNewMessage(int client_fd) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        std::cerr << "Failed to read from client: " << std::endl;
        return;
    }

    // Get the client who sent the message
    Client *client = getClientByFd(client_fd);  // You would need to implement getClientByFileDescriptor()
    if (!client) {
        std::cerr << "Failed to find client for file descriptor: " << client_fd << std::endl;
        return;
    }

    // If the client CTRL+D
    if (bytes_read == 0) {
        client->setPartialInput(client->getPartialInput() + std::string(buffer));
        return;
    }

    // Append received buffer to client's partial command
    std::string partialInput = client->getPartialInput() + std::string(buffer);
    client->setPartialInput(partialInput);

    // Check if the last character in the partialCommand is a newline character ('\n')
    if (!partialInput.empty() && partialInput[partialInput.size() - 1] == '\n') {
        // Print received message for debugging purposes
        std::cout << "Received message from client: " << partialInput << std::endl;

        // Parse and execute command
        parseAndExecuteCommand(client, partialInput);

        // Clear the partial command after processing
        client->setPartialInput("");
    }
}

// Handle the data received from the client.
void Server::parseAndExecuteCommand(Client *client, const std::string &message){
    // Split the message into command and arguments.
    std::vector<std::string> tokens;
    std::stringstream ss(message);
    std::string token;
    
    // Split by spaces
    while (std::getline(ss, token, ' '))
        tokens.push_back(token);

    // Convert command to uppercase
    std::string command = tokens[0];
    std::transform(command.begin(), command.end(), command.begin(), ::toupper);

    // Erase the trailing newline character from the command if it exists
    size_t pos = command.find_last_not_of("\n");
    if (pos != std::string::npos)
        command.erase(pos + 1);
    else
        // If command only contain '\n' character
        command.clear();

    // Erase the trailing newline character from the last token if it exists
    if (!tokens.empty()) {
        std::string &lastToken = tokens.back();
        size_t pos = lastToken.find_last_not_of("\n");
        if (pos != std::string::npos)
            lastToken.erase(pos + 1);
        else
            // If token only contain '\n' character
            lastToken.clear();
    }

    // Look up the command in the map
    std::map<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>::iterator it = _commands.find(command);

    // If the command exists, call the corresponding function.
    if (it != _commands.end())
        it->second(*this, *client, tokens);
    else
    {
        client->sendMessage("Invalid command.\n");
        std::cout << "Invalid command received from client: " << command << std::endl;
    }
}


// --------------------CLIENT--------------------

void Server::addClient(Client *client)
{
	if (!client)
		return ;
	std::vector<Client*>::iterator it = std::find(_clients.begin(), _clients.end(), client);
	if (it != _clients.end())
		return ;
    _clients.push_back(client);
}

void Server::removeClient(Client *client)
{
	if (!client)
		return ;
	std::vector<Client*>::iterator it = std::find(_clients.begin(), _clients.end(), client);
    if (it == _clients.end())
        return ;
    _clients.erase(it);
}

Client *Server::getClientByNickname(std::string &nickname)
{
    for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
        if ((*it)->getNickname() == nickname)
            return *it;
    return (NULL);
}

Client *Server::getClientByUsername(std::string &username)
{
    for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
        if ((*it)->getUsername() == username)
            return *it;
    return (NULL);
}

Client *Server::getClientByFd(int fd)
{
    for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
        if ((*it)->getFd() == fd)
            return *it;
    return (NULL);
}

// --------------------CHANNEL--------------------


Channel *Server::createChannel(std::string name, Client *client)
{
	Channel *channel = new Channel(*this, client, name);
	return channel;
}

void Server::addChannel(Channel	*channel)
{
	if (!channel)
		return ;
	std::vector<Channel*>::iterator it = std::find(_channels.begin(), _channels.end(), channel);
	if (it != _channels.end())
		return ;
    _channels.push_back(channel);
}

void Server::removeChannel(Channel	*channel)
{
	if (!channel)
		return ;
	std::vector<Channel*>::iterator it = std::find(_channels.begin(), _channels.end(), channel);
    if (it == _channels.end())
        return ;
    _channels.erase(it);
}

Channel *Server::getChannelByName(std::string name)
{
    for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
        if ((*it)->getName() == name)
            return *it;
    return (NULL);

}

void	Server::broadcastMessage(const std::string &message) {
    for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
        (*it)->sendMessage(message);
}

void	Server::initCommands( void )
{
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("DIE", &die));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("INVITE", &invite));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("JOIN", &join));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("KICK", &kick));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("MODE", &mode));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("MSG", &msg));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("NAMES", &names));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("NICK", &nick));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("OPER", &oper));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("PART", &part));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("PASS", &pass));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("QUIT", &quit));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("TOPIC", &topic));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("USER", &user));
}

