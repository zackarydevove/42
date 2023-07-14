#include "../../includes/commands.hpp"

// input[0] = PING command
// input[1] = Server name
int ping(Server &server, Client &client, std::vector<std::string> &input)
{
    (void)server;
    if (!client.getAuth() && !client.getRegistered())
    {
        // Client already authenticate
        client.sendMessage(ERR_NOTREGISTERED(client.getNickname(), "PING"));
        return 0;
    }
	if (input.size() < 2)
    {
		client.sendMessage(ERR_NOORIGIN(client.getNickname()));
		return false;
	}
	if (input[1] != SERVER_NAME) {
		client.sendMessage(ERR_NOSUCHSERVER(client.getNickname()));
		return false;
	}
	client.sendMessage(PONG(client.getNickname()));
	return true;

}