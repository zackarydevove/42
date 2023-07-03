#include "../../includes/commands.hpp"

// input[0] = kick command
// input[1] = Channel name
// input[2] = nickname of user kicekd
// input[3] = message / reason for the kick (optional)
int kick(Server &server, Client &client, std::vector<std::string> &input)
{
    // Check that we have at least channel name and nickname of user
    if (input.size() < 3)
    {
        // The client didn't provide enough arguments.
        client.sendMessage("ERROR: You must provide the name of a channel and the nickname of the user to kick.");
        return (0);
    }

    std::string channelName = input[1];
    Channel *channel = server.getChannelByName(channelName);
    if (!channel)
    {
        // The channel doesn't exist.
        client.sendMessage("ERROR: The specified channel does not exist.");
        return (0);
    }

    // Check if client is an operator in the channel.
    if (!channel->isOperator(&client))
    {
        // The client is not an operator in the specified channel.
        client.sendMessage("ERROR: You are not an operator of the specified channel.");
        return (0);
    }

    std::string clientToKickNickname = input[2];
    Client *clientToKick = channel->getClientByNickname(clientToKickNickname);
    if (!clientToKick)
    {
        // The user to kick doesn't exist.
        client.sendMessage("ERROR: The specified user does not exist.");
        return (0);
    }

    // If the user is client of that channel
    if (!channel->isClient(clientToKick))
    {
        // The user to kick doesn't exist.
        client.sendMessage("ERROR: You are not part of the specified channel.");
        return (0);

    }

    // Kick the user from the channel.
    channel->removeClient(clientToKick);

    // Send a message to the channel that the user has been kicked.
    std::string kickMessage = clientToKickNickname + " has been kicked from " + channelName + " by " + client.getNickname();
    channel->broadcastMessage(kickMessage);

    // Notify the kicked client.
    clientToKick->sendMessage("You have been kicked from " + channelName + " by " + client.getNickname());

    return (1);
}