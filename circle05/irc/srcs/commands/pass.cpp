#include "../../includes/commands.hpp"

// input[0] = command
// input[1] = password
int pass(Server &server, Client &client, std::vector<std::string> &input)
{
    if (input.size() < 2)
    {
        // Not enough parameters were provided.
        client.sendMessage("ERROR: Not enough parameters. Syntax: PASS <password>\n");
        return 0;
    }

    if (client.getAuth())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are already authenticated.\n");
        return 0;
    }

    std::string password = input[1];

    if (server.getPassword() == password)
        client.setAuth(true);
    else
    {
        // Not enough parameters were provided.
        client.sendMessage("ERROR: Wrong password.\n");
        return 0;
    }

    client.sendMessage("You have been authenticated!\nNow, use the NICK and USER command to choose a nickname and username.\n");
    return 1;
}