#include "../../includes/commands.hpp"

// input[0] = part command
// input[1] = channel
// input[2] = message (optional)
int part(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth() && !client.getRegistered())
    {
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }

    if (input.size() >= 2)
    {
        Channel *channel = server.getChannelByName(input[1]);
        if (channel)
        {
            // Check if the client is a member of this channel.
            if (!channel->isClient(&client))
            {
                // The client is not a member of the channel.
                client.sendMessage("ERROR: You are not a member of the channel " + input[1] + "\n");
                return 0;
            }

            // if message;
            std::string message;
            if(input.size() >= 3)
                message = input[2];

            // Client leaves the channel
            client.leaveChannel(channel);

            // Broadcast the part message
            channel->broadcastMessage(client.getNickname() + " has left the channel. " + message + "\n");
            client.sendMessage("You have left channel " + channel->getName() + " successfully.\n");
            return 1;
        }
        else 
        {
            // The channel does not exist.
            client.sendMessage("ERROR: Channel " + input[1] + " does not exist.\n");
            return 0;
        }
    }
    else
    {
        // The client didn't provide the channel name.
        client.sendMessage("ERROR: No channel name provided.\n");
        return 0;
    }
}