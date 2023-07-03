#include "../includes/Server.hpp"

extern bool g_shutdown;

// --------------------CONSTRUCTOR && DECONSTRUCTOR--------------------

Server::Server(int port, std::string password) : 
	_name("irc"),
	_port(port),
	_password(password),
	_operatorPassword(password)
{
    std::cout << "Server created" << std::endl;
}

Server::~Server() 
{
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
		delete *it;
}



// --------------------SERVER--------------------




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
