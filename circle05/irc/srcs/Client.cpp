#include "../includes/Client.hpp"

Client::Client(int fd, std::string hostname) : 
	_fd(fd),
    _hostname(hostname),
    _isAuth(false)
    { }

Client::~Client() {
	leaveAllChannels();
}

Channel*	Client::getChannel(const std::string channelName)
{
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
		if ((*it)->getName() == channelName)
            return (*it);
	return NULL;
}

void	Client::joinChannel(Channel *channel)
{
	channel->addClient(this);
	_channels.push_back(channel);
}

void	Client::leaveChannel(Channel *channel)
{
	if (!channel)
		return ;
	std::vector<Channel*>::iterator it = std::find(_channels.begin(), _channels.end(), channel);
	if (it != _channels.end())
	{
    	(*it)->removeClient(this);
		_channels.erase(it);
	}
}

void	Client::leaveAllChannels() {
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
        this->leaveChannel((*it));

}

void	Client::sendMessage(const std::string &message) {
    if (_fd)
	    send(_fd, message.c_str(), message.size(), 0);
}