#include "../../includes/commands.hpp"

// Commad to change nickname
// input[0] = nick msg
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
    if (server.getClientByNickname(newNickname))
    {
        client.sendMessage("ERROR: The nickname '" + newNickname + "' is already in use.\n");
        return 0;
    }

    // Update the client's nickname
    client.setNickname(newNickname);

    // Notify the client that the nickname change was successful
    client.sendMessage("Your nickname has been changed to '" + newNickname + "'.\n");

    return 1;
}