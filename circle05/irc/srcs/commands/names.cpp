#include "../../includes/commands.hpp"

// montre les nicks d’un channel sans channel, montre tous les nicks du serveur
// input[0] = names command
// input[1] = channel (optional)
int names(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }

    // If input[1]
    if (input.size() >= 2)
    {
        Channel *channel = server.getChannelByName(input[1]);
        if (channel)
        {
            // Make sure the client is a member of this channel.
            if (!channel->isClient(&client))
            {
                // The client is not a member of the channel.
                client.sendMessage("ERROR: You are not a member of the channel " + channel->getName() + "\n");
                return 0;
            }

            // Show all the members of that channel
            std::vector<Client *> clients = channel->getClients();
            for (std::vector<Client *>::iterator it = clients.begin(); it != clients.end(); ++it)
                client.sendMessage((*it)->getNickname() + "\n");
            return 1;
        }
    }

    // Show all the members of that channel
    std::vector<Client *> clients = server.getClients();
    for (std::vector<Client *>::iterator it = clients.begin(); it != clients.end(); ++it)
        client.sendMessage((*it)->getNickname() + "\n");

    return 1;
}
