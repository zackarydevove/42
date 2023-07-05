#ifndef CLIENT_HPP

# define CLIENT_HPP

# include <iostream>
# include <string>
# include <sys/socket.h>
# include <algorithm>

# include "Channel.hpp"
# include "Server.hpp"

class Channel;
class Server;

class Client {
    private:
		int						_fd;
        std::string				_hostname; // Name of the computer client is connecting from
        std::string				_username; // Name used for authentication purposes (unique)
        std::string				_nickname; // Name used to identify user in chat
		std::vector<Channel *>	_channels;
		bool					_isAuth;
		bool					_isOp;

    public:
        Client(int fd, const std::string name);
        ~Client();
		
		// Getters
		int			getFd() { return _fd; };
		std::string getHostname() { return _hostname; };
		std::string getUsername() { return _username; };
		std::string getNickname() { return _nickname; };
		std::vector<Channel *> getChannels() { return _channels; };
		bool 		getAuth() { return _isAuth; };
		bool 		getOp() { return _isOp; };

		// Setters
		void 		setFd(int &fd ) { _fd = fd; };
		void 		setHostname(std::string const &hostname ) { _hostname = hostname; };
		void 		setUsername(std::string const &username ) { _username = username; };
		void 		setNickname(std::string const &nickname ) { _nickname = nickname; };
		void 		setOp(bool isOp) { _isOp = isOp; };
		void 		setAuth(bool isAuth) { _isAuth = isAuth; };

		Channel*	getChannel(const std::string channelName);
		void		joinChannel(Channel *channel);
		void		leaveChannel(Channel *channel);
		void		leaveAllChannels();
		void		sendMessage(const std::string &message);
};

#endif