#include "../../includes/commands.hpp"

// input[0] = PING command
// input[1] = Server name
int ping(Server &server, Client &client, std::vector<std::string> &input)
{
    (void)server;
    if (!client.getAuth() && !client.getRegistered())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }
	if (input.size() < 2)
    {
		client.sendMessage("ERROR: Not enough arguments.\n");
		return false;
	}
	if (input[1] != SERVER_NAME) {
		client.sendMessage("ERROR: Wrong server name.\n");
		return false;
	}
	client.sendMessage(PONG(client.getNickname()));
	return true;

}