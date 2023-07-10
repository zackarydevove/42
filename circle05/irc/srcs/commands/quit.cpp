#include "../../includes/commands.hpp"

// Command to quit the irc
// input[0] = quit command
// input[1] = message why quit (optional)
int quit(Server &server, Client &client, std::vector<std::string> &input)
{
    (void)server;
	std::vector<Channel *> channels = client.getChannels();

    // Notify other clients in the channels that this client is part of.
    for (std::vector<Channel *>::iterator channel = channels.begin(); channel != channels.end(); ++channel)
    {
        std::string message = "Client " + client.getNickname() + " has disconnected.\n";
        if (input.size() > 1)
            message += "Reason: " + input[1] + ".\n";
        (*channel)->broadcastMessage(message);
        // Remove client from the channel.
        (*channel)->removeClient(&client);
    }

    std::cout << "Client " << client.getNickname() << " has left the server." << std::endl;
    client.sendMessage("You have successfully left the server.\n");

    // Disconnect the client.
    // server.removeClient(&client);
    client.setAuth(false);

    return 1;
}
