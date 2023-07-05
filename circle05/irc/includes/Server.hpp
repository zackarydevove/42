#ifndef SERVER_HPP

# define SERVER_HPP

# include <iostream>
# include <string>
# include <map>
# include <vector>
# include <algorithm>
# include <sys/socket.h>
# include <sys/epoll.h>
# include <netinet/in.h>
# include <cstring>
# include <unistd.h>


# include "Channel.hpp"
# include "commands.hpp"

# define MAX_EVENTS 10

class Channel;
class Client;

class Server {
    private:
        std::string    			_name;
        int             		_port;
        std::string				_password;
		std::string				_operatorPassword;

        int             		_socket_fd;
        struct sockaddr_in		_server_address; 
		int						_epoll_fd;

        std::vector<Client *>	_clients;
        std::vector<Channel *>	_channels;
        std::map<std::string, int (*)(Server &, Client &, std::vector<std::string> & )>	_commands;

    public:
        Server(int port, std::string password);
        ~Server();

        void		openSocket();
        void		bindSocket();
        void		listenSocket();
		int			setupEpoll();
		void		startServer();

		void		handleNewConnection(int epoll_fd, struct sockaddr_in &client_address, socklen_t &client_len);
		void		handleClientData(int client_fd);
        void		parseAndExecuteCommand(Client *client, const std::string &message);

        void		broadcastMessage(const std::string &message);

        std::string getName() { return _name; };
        std::string getPassword() { return _password; };
        std::string getOperatorPassword() { return _operatorPassword; };
    	int	getEpollfd() { return _epoll_fd; };

		void setEpollfd(int epoll_fd) { _epoll_fd = epoll_fd; };

        void 		addClient(Client *client);
        void 		removeClient(Client *client);
        Client 		*getClientByNickname(std::string &nickname);
        Client 		*getClientByUsername(std::string &username);

        Channel 	*createChannel(std::string name, Client *client);
        void		addChannel(Channel	*channel);
        void 		removeChannel(Channel	*channel);
        Channel  	*getChannelByName(std::string name);

        void	initCommands( void );
};

#endif