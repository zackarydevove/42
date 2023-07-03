#include "../includes/Server.hpp"

extern bool g_shutdown;

// --------------------CONSTRUCTOR && DECONSTRUCTOR--------------------

Server::Server(int port, std::string password) : 
	_name("irc"),
	_port(port),
	_password(password),
	_operatorPassword(password)
{
    // createSocket();
    // bindSocket();
	// createPoll();
	// initCommands();
    std::cout << "Server created" << std::endl;
}

Server::~Server() 
{
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
		delete *it;
}



// --------------------SERVER--------------------


// // Create new socket for the server
// void Server::createSocket()
// {
//     // Create socket
//     // Creates a TCP socket using IPv4 and return a socket fd that will be used to refer to this socket
//     // AF_INET specifies to use IPv4 address, which is used for creating internet-based sockets
//     // SOCK_STREAM is the type of socket, this type is a two-way connection-based byte streams
//     // 0 protocol to use, 0 indicate that the OS will choose the according one to the sock_stream (so TCP)
// 	_socket_fd = socket(AF_INET, SOCK_STREAM, 0);
//     if (_socket_fd == -1)
//         throw std::runtime_error("error: cannot create socket");
// 	// This is to set some options for the socket
// 	// SOL_SOCKET
// 	// REUSEADDR allow server to reuse the address directly after server socket is closed
// 	// enable
// 	// size of enable
// 	int enable = 1;
// 	if (setsockopt(_socket_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(enable)) < 0)
// 		throw std::runtime_error("error: cannot set socket");

// 	if (fcntl(_socket_fd, F_SETFL, O_NONBLOCK) < 0)
// 		exit(error("fcntl", 1));
// }

// // This function will bind the socket to a specific port and address
// // it set address to INADDR_ANY which tells the socket to listen on all network interfaces on the machine
// // set port to _port (the port we gave in the terminal)
// // we need to use struct because
// // we listen because
// void Server::bindSocket()
// {
//     // bind socket
// 	struct sockaddr_in	addr;
// 	addr.sin_family = AF_INET;
// 	addr.sin_addr.s_addr = INADDR_ANY;
// 	addr.sin_port = htons(_port);

// 	if (bind(_socket_fd, (struct sockaddr *)&addr, sizeof(addr)) < 0)
// 		throw std::runtime_error("error: cannot bind");

// 	if (listen(_socket_fd, addr.sin_port) < 0)
// 		throw std::runtime_error("error: cannot listen");
// }

// // Setup the epoll interface for managing client connections
// // epoll_create create epoll instance
// // backlog
// // 
// void Server::createPoll()
// {
// 	if ((_epoll_fd = epoll_create(BACKLOG)) < 0)
// 		throw std::runtime_error("error: cannot create epoll");
// 	_epoll_event.data.fd = _socket_fd;
// 	_epoll_event.events = EPOLLIN;
// 	if (epoll_ctl(_epoll_fd, EPOLL_CTL_ADD, _socket_fd, &_epoll_event) < 0)
// 		throw std::runtime_error("error: cannot control epoll");
// }

// void Server::startServer()
// {
//     while (!g_shutdown)
//     {
//         // listen to new clients, or clients leaving
// 		// listen to commands
//     }
// }


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
