#include "../../includes/commands.hpp"

// La commande /msg te permet d'envoyer un message en privé à un utilisateur 
// ou un message normal sur un channel sur lequel tu  es présent ou pas 
// (dernier cas possible uniquement si le channel n'est pas en mode +n, pas de messages extérieures).
// input[0] = msg command
// input[1] = client / channel receive
// input[2] = client who send msg
int msg(Server &server, Client &client, std::vector<std::string> &input)
{
    if (input.size() < 3)
    {
        // Not enough parameters were provided.
        client.sendMessage("ERROR: Not enough parameters. Syntax: MSG <receiver> <text>");
        return 0;
    }

    std::string receiver = input[1];
    std::string message = input[2];

    // Check if the receiver is a channel.
    Channel *channel = server.getChannelByName(receiver);
    if (channel)
    {
        // The receiver is a channel.
        // Make sure the client is a member of this channel.
        if (!channel->isClient(&client))
        {
            // The client is not a member of the channel.
            client.sendMessage("ERROR: You are not a member of the channel " + receiver);
            return 0;
        }

        // Send the message to all members of the channel.
        std::vector<Client *> clients = channel->getClients();
        for (std::vector<Client *>::iterator it = clients.begin(); it != clients.end(); ++it)
        {
            Client *otherClient = *it;
            if (otherClient != &client)  // Do not send the message to the client who sent it.
                otherClient->sendMessage(client.getNickname() + ": " + message);
        }
        return 1;
    }

    // If the receiver is not a channel, assume it is a client.
    Client *otherClient = server.getClientByNickname(receiver);
    if (otherClient)
    {
        // Send the message to the other client.
        otherClient->sendMessage(client.getNickname() + ": " + message);
        return 1;
    }

    // The receiver does not exist.
    client.sendMessage("ERROR: The receiver " + receiver + " does not exist.");
    return 0;
}
