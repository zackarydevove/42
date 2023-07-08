#include "../../includes/commands.hpp"

// input[0] = invite command
// input[1] = channel name
// input[2] = nickname of user to invite
int invite(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }
    if (input.size() < 3)
    {
        // The client didn't provide enough arguments.
        client.sendMessage("ERROR: You must provide the name of a channel and the nickname of the user to invite.\n");
        return (0);
    }

    std::string channelName = input[1];
    Channel *channel = server.getChannelByName(channelName);
    if (!channel)
    {
        // The channel doesn't exist.
        client.sendMessage("ERROR: The specified channel does not exist.\n");
        return (0);
    }

    // Check if client is part of the channel.
    if (!channel->isClient(&client))
    {
        // The client is not part of the specified channel.
        client.sendMessage("ERROR: You are not part of the specified channel.\n");
        return (0);
    }

    std::string clientToInviteNickname = input[2];
    Client *clientToInvite = server.getClientByNickname(clientToInviteNickname);
    if (!clientToInvite)
    {
        // The user to invite doesn't exist.
        client.sendMessage("ERROR: The specified user does not exist.\n");
        return (0);
    }

    // Invite the user to the channel.
    channel->addInvited(clientToInvite);

    // Send a message to the invited client.
    clientToInvite->sendMessage("You have been invited to join the channel " + channelName + " by " + client.getNickname() + "\n");

    return (1);
}