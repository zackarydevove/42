#include "../../includes/commands.hpp"

// input[0] = join command
// input[1] = channel
// input[2] = password (optional)
int join(Server &server, Client &client, std::vector<std::string> &input)
{
    // Check that we have at least one argument (channel)
    if (input.size() < 2)
    {
        // The client didn't provide a channel name to join.
        client.sendMessage("ERROR: You must provide the name of a channel.");
        return (0);
    }

    std::string channelName = input[1];
    Channel *channel = server.getChannelByName(channelName);
    // If the channel doesn't exist, so create a new one.
    if (!channel)
        channel = server.createChannel(channelName, &client);

    if (channel->getPassword().length() > 0)
    {
        if (input.size() < 3 || channel->getPassword() != input[2])
        {
            // Incorrect or missing password for this channel.
            client.sendMessage("ERROR: Incorrect password for this channel.");
            return (0);
        }
    }

    // Add the client to the channel.
    channel->addClient(&client);

    // Send a message to the channel that the client has joined.
    std::string joinMessage = client.getNickname() + " has joined " + channelName;
    channel->broadcastMessage(joinMessage);

    return (1);
}