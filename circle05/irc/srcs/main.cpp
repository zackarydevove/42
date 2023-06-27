#include "Client.hpp"
#include "Server.hpp"
#include "Channel.hpp"

int	main(int ac, char **av)
{
	if (ac != 3)
		return (std::cerr << "Error: Usage: ./ircserv <port> <password>" << std::endl, 0);
}