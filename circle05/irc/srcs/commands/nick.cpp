#include "../../includes/commands.hpp"

// Command to change nickname
// input[0] = nick command
// input[1] = new nickname
int nick(Server &server, Client &client, std::vector<std::string> &input)
{
    // Check if the necessary arguments are provided
    if (input.size() < 2)
    {
        client.sendMessage("ERROR: You must provide a new nickname.\n");
        return 0;
    }

    std::string newNickname = input[1];

    // Check if the new nickname is already in use
    while (server.getClientByNickname(newNickname))
        newNickname += "_";

    // Update the client's nickname
    client.setNickname(newNickname);

    // Notify the client that the nickname change was successful
    client.sendMessage("Your nickname has been changed to '" + newNickname + "'.\n");

    if (!client.getNickname().empty() && !client.getUsername().empty() && !client.getHostname().empty())
    {
        client.setRegistered(true);
    }
    if (client.getRegistered() && client.getAuth())
        client.sendMessage(RPL_WELCOME(client.getNickname()));

    return 1;
}