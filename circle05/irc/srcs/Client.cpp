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
    channel->removeClient(this);
}

void	Client::leaveAllChannels() {
	for (std::vector<Channel*>::iterator it = _channels.begin(); it != _channels.end(); ++it)
	{
		std::cout << "Leaving channel: " << (*it)->getName() << std::endl;    
        this->leaveChannel((*it));
	}
}

void	Client::sendMessage(const std::string &message) {
    if (_fd)
	    send(_fd, message.c_str(), message.size(), 0);
}