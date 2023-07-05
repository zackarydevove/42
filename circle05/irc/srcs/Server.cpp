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
    std::cout << "Server created" << std::endl;
	openSocket();
	bindSocket();
	listenSocket();
	startServer();
}

Server::~Server() 
{
    close(_socket_fd);
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
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
    if (_epoll_fd == -1) {
        throw std::runtime_error("Failed to create epoll file descriptor");
    }

    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = _socket_fd;
    if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _socket_fd, &event)) {
        throw std::runtime_error("Failed to add socket file descriptor to epoll");
    }

    return _epoll_fd;
}

void Server::startServer() {
    struct sockaddr_in client_address;
    socklen_t client_len = sizeof(client_address);

    int _epoll_fd = setupEpoll();

    struct epoll_event events[MAX_EVENTS];
    while (!g_shutdown) {
        int num_fds = epoll_wait(_epoll_fd, events, MAX_EVENTS, 100); // timeout of 100ms
        for (int i = 0; i < num_fds; i++) {
            if (events[i].data.fd == _socket_fd) {
                // Handle new connection
                handleNewConnection(_epoll_fd, client_address, client_len);
            } else {
                // Handle data from a client
                handleClientData(events[i].data.fd);
            }
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

    // Add the new socket to the epoll instance
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = client_fd;
    if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, client_fd, &event)) {
        throw std::runtime_error("Failed to add client socket file descriptor to epoll");
    }
}

// Function to handle data from a client
void Server::handleClientData(int client_fd) {
    char buffer[1024];
    memset(buffer, 0, sizeof(buffer));

    ssize_t bytes_read = read(client_fd, buffer, sizeof(buffer) - 1);
    if (bytes_read < 0) {
        std::cerr << "Failed to read from client: " << std::endl;
        return;
    }
    else if (bytes_read == 0) {
        // The client has closed the connection, so we should remove it from epoll and close the socket
        if (epoll_ctl(_epoll_fd, EPOLL_CTL_DEL, client_fd, NULL) == -1) {
            throw std::runtime_error("Failed to delete client file descriptor from epoll");
        }
        close(client_fd);
        return;
    }

    // Handle the data received from the client. This would typically involve parsing it,
    // executing some commands based on the input, and possibly sending a response back to the client.
    // For now, we'll just print the data we received.
    std::cout << "Received data from client: " << buffer << std::endl;

    // To send a response, use the write() function. For example, to send the client's message back to them:
    if (write(client_fd, buffer, bytes_read) < 0) {
        std::cerr << "Failed to write to client: " << std::endl;
        return;
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
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("NICK", &nick));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("OPER", &oper));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("QUIT", &quit));
	_commands.insert(std::pair<std::string, int (*)(Server&, Client&, std::vector<std::string>&)>("TOPIC", &topic));
}
