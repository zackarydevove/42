#include "../../includes/commands.hpp"

// Command to quit the irc
// input[0] = quit command
// input[1] = message why quit (optional)
int quit(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }
    // If an argument was provided, it's used as the quit message.
    std::string quitMessage = "Client disconnected\n";
    if (input.size() >= 2)
    {
        quitMessage = input[1];
    }

	std::vector<Channel *>	channels = client.getChannels();

    // Notify other clients in the channels that this client is part of.
    for (std::vector<Channel *>::iterator channel = channels.begin(); channel != channels.end(); ++channel)
    {
        std::string message = "QUIT :Client " + client.getNickname() + " has disconnected: " + quitMessage + "\n";
        (*channel)->broadcastMessage(message);
    }

    std::cout << "Client " << client.getHostname() << " has left the server." << std::endl;

    std::string nickname = client.getNickname();

    // Disconnect the client.
    server.removeClient(server.getClientByNickname(nickname));

    return 1;
}
