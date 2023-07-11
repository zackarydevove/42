#include "../../includes/commands.hpp"

// input[0] = join command
// input[1] = channel
// input[2] = password (optional)
int join(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth() && !client.getRegistered())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }
    // Check that we have at least one argument (channel)
    if (input.size() < 2)
    {
        // The client didn't provide a channel name to join.
        client.sendMessage("ERROR: You must provide the name of a channel.\n");
        return (0);
    }

    std::string channelName = input[1];
    Channel *channel = server.getChannelByName(channelName);
    // If the channel doesn't exist, create a new one.
    if (!channel)
    {
        channel = new Channel(server, &client, channelName);
        server.addChannel(channel);
    }
    // Else, check password, mode, etc.
    else
    {
        if (channel->getPassword().size() > 0)
        {
            if (input.size() < 2 || channel->getPassword() != input[2])
            {
                // Password is missing or wrong.
                client.sendMessage("ERROR: The password provided is wrong.\n");
                return (0);
            }
        }
        if (channel->getInviteOnly() && !channel->isInvited(&client))
        {
            // Client is not on the invite list.
            client.sendMessage("ERROR: You have not been invited to this channel.\n");
            return (0);
        }
        if (channel->getLimit() && channel->getClients().size() >= channel->getLimit())
        {
            // Client is not on the invite list.
            client.sendMessage("ERROR: This channel is full.\n");
            return (0);
        }
    }
    // Add the client to the channel.
    channel->addClient(&client);
    // Send a message to the channel that the client has joined.
    std::string joinMessage = client.getNickname() + " has joined " + channelName + "\n";
    channel->broadcastMessage(joinMessage);

    return (1);
}