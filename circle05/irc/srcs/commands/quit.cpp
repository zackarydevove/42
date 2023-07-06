#include "../../includes/commands.hpp"

// Command to quit the irc
// input[0] = quit command
// input[1] = message why quit (optional)
int quit(Server &server, Client &client, std::vector<std::string> &input)
{
    // If an argument was provided, it's used as the quit message.
    std::string quitMessage = "Client disconnected\n";
    if (input.size() >= 2)
    {
        quitMessage = input[1];
    }

	std::vector<Channel *>	channels = client.getChannels();

    // Notify other clients in the channels that this client is part of.
    for (std::vector<Channel *>::iterator it = channels.begin(); it != channels.end(); ++it)
    {
        Channel *channel = *it;
        std::string message = "QUIT :Client " + client.getNickname() + " has disconnected: " + quitMessage + "\n";
        channel->broadcastMessage(message);
    }

    std::cout << "Client " << client.getHostname() << " has left the server." << std::endl;

    // Disconnect the client.
    server.removeClient(&client);
    return 1;  // This will probably not be reached as the client is disconnected.
}
