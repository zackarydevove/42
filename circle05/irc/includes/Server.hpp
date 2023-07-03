#ifndef SERVER_HPP

# define SERVER_HPP

# include <iostream>
# include <string>
# include <map>
# include <algorithm>

# include "Channel.hpp"
# include "commands.hpp"

class Channel;
class Client;

class Server {
    private:
        std::string    			_name;
        int             		_port;
        std::string				_password;
		std::string				_operatorPassword;

        int             		_socket_fd;
        int						_epoll_fd;

        std::vector<Client *>	_clients;
        std::vector<Channel *>	_channels;
        std::map<std::string, int (*)(Server &, Client &, std::vector<std::string> & )>	_commands;

    public:
        Server(int port, std::string password);
        ~Server();

		void 		start_server();

        void		broadcastMessage(const std::string &message);

        std::string getName() { return _name; };
        std::string getPassword() { return _password; };
        std::string getOperatorPassword() { return _operatorPassword; };

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