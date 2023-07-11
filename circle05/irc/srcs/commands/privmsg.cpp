#include "../../includes/commands.hpp"

// input[0] = msg command
// input[1] = receiver (client / channel)
// input[2] = message to send
int privmsg(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth() && !client.getRegistered())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }
    if (input.size() < 3)
    {
        // Not enough parameters were provided.
        client.sendMessage("ERROR: Not enough parameters. Syntax: MSG <receiver> <text>\n");
        return 0;
    }

    std::string receiver = input[1];
    std::string message = input[2];

    if (message[0] == ':')
        message = message.substr(1);

    // Check if the receiver is a channel.
    Channel *channel = server.getChannelByName(receiver);
    if (channel)
    {
        // The receiver is a channel.
        // Make sure the client is a member of this channel.
        if (!channel->isClient(&client))
        {
            // The client is not a member of the channel.
            client.sendMessage("ERROR: You are not a member of the channel " + receiver + "\n");
            return 0;
        }

        // Send the message to all members of the channel.
        std::vector<Client *> clients = channel->getClients();
        for (std::vector<Client *>::iterator it = clients.begin(); it != clients.end(); ++it)
        {
            Client *receiverClient = *it;
            receiverClient->sendMessage(client.getNickname() + ": " + message + "\n");
        }
        return 1;
    }

    // If the receiver is not a channel, assume it is a client.
    Client *receiverClient = server.getClientByNickname(receiver);
    if (receiverClient)
    {
        // Send the message to the other client.
        receiverClient->sendMessage(client.getNickname() + ": " + message + "\n");
        return 1;
    }

    // The receiver does not exist.
    client.sendMessage("ERROR: The receiver " + receiver + " does not exist.\n");
    return 0;
}
