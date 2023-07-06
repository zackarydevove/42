#include "../includes/Channel.hpp"

Channel::Channel(Server &server, Client *client, std::string name) : 
	_server(server),
	_creator(client),
	_name(name),
	_limit(0),
	_inviteOnly(false),
	_topicRestricted(false)
	{ }

Channel::~Channel() {
	for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
		(*it)->leaveChannel(this);
}

void	Channel::broadcastMessage(const std::string &message) {
	for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
		(*it)->sendMessage(message);
}

// --------------------CLIENT--------------------

void Channel::addClient(Client *client)
{
	(void)_server;
	if (!client)
		return ;
    if (_limit > 0 && _clients.size() >= _limit)
    {
        client->sendMessage("ERROR: The specified channel is full.\n");
        return ;
    }
	std::vector<Client *>::iterator it = std::find(_clients.begin(), _clients.end(), client);
	if (it != _clients.end())
		return ;
    _clients.push_back(client);
}

void Channel::removeClient(Client *client)
{
	if (!client)
		return ;
	std::vector<Client*>::iterator it = std::find(_clients.begin(), _clients.end(), client);
    if (it == _clients.end())
        return ;
    _clients.erase(it);
}

Client *Channel::getClientByNickname(std::string &nickname)
{
	for (std::vector<Client*>::iterator it = _clients.begin(); it != _clients.end(); ++it)
        if ((*it)->getNickname() == nickname)
			return (*it);
    return (0);
}

int Channel::isClient(Client *client)
{
	if (!client)
		return (0);
	std::vector<Client*>::iterator it = std::find(_clients.begin(), _clients.end(), client);
    if (it != _clients.end())
        return (1);
    return (0);
}

// --------------------OPERATOR--------------------

void Channel::addOperator(Client *client)
{
	if (!client)
		return ;
	std::vector<Client*>::iterator it = std::find(_operators.begin(), _operators.end(), client);
	if (it != _operators.end())
		return ;
    _operators.push_back(client);
}

void Channel::removeOperator(Client *client)
{
	if (!client)
		return ;
	std::vector<Client*>::iterator it = std::find(_operators.begin(), _operators.end(), client);
    if (it == _operators.end())
        return ;
    _operators.erase(it);
}

int Channel::isOperator(Client *client)
{
	if (!client)
		return (0);
	std::vector<Client*>::iterator it = std::find(_operators.begin(), _operators.end(), client);
    if (it != _operators.end())
        return (1);
    return (0);
}

// --------------------INVITED--------------------

void Channel::addInvited(Client *client)
{
	if (!client)
		return ;
	std::vector<Client*>::iterator it = std::find(_invited.begin(), _invited.end(), client);
	if (it != _invited.end())
		return ;
    _invited.push_back(client);
}

void Channel::removeInvited(Client *client)
{
	if (!client)
		return ;
	std::vector<Client*>::iterator it = std::find(_invited.begin(), _invited.end(), client);
    if (it == _invited.end())
        return ;
    _invited.erase(it);
}

int Channel::isInvited(Client *client)
{
	if (!client)
		return (0);
	std::vector<Client*>::iterator it = std::find(_invited.begin(), _invited.end(), client);
    if (it != _invited.end())
        return (1);
    return (0);
}