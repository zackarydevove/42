#ifndef COMMANDS_HPP

# define COMMANDS_HPP

# include "Client.hpp"
# include "Server.hpp"
# include "Channel.hpp"

class Server;
class Client;
class Channel;

// add all the commands here

int die(Server &server, Client &client, std::vector<std::string> &input);
int invite(Server &server, Client &client, std::vector<std::string> &input);
int join(Server &server, Client &client, std::vector<std::string> &input);
int kick(Server &server, Client &client, std::vector<std::string> &input);
int mode(Server &server, Client &client, std::vector<std::string> &input);
int msg(Server &server, Client &client, std::vector<std::string> &input);
int nick(Server &server, Client &client, std::vector<std::string> &input);
int oper(Server &server, Client &client, std::vector<std::string> &input);
int pass(Server &server, Client &client, std::vector<std::string> &input);
int quit(Server &server, Client &client, std::vector<std::string> &input);
int topic(Server &server, Client &client, std::vector<std::string> &input);
int user(Server &server, Client &client, std::vector<std::string> &input);


#endif