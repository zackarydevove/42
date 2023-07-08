#include "../../includes/commands.hpp"

// Command to change username
// input[0] = USER command
// input[1] = new username
int user(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }
    // Check if the necessary arguments are provided
    if (input.size() < 2)
    {
        client.sendMessage("ERROR: You must provide a new username.\n");
        return 0;
    }

    std::string newUsername = input[1];

    // Check if the new username is already in use
    if (server.getClientByUsername(newUsername))
    {
        client.sendMessage("ERROR: The username '" + newUsername + "' is already in use.\n");
        return 0;
    }

    // Update the client's username
    client.setUsername(newUsername);

    // Notify the client that the username change was successful
    client.sendMessage("Your username has been changed to '" + newUsername + "'.\n");

    return 1;
}