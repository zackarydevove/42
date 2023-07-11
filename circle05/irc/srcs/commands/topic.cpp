#include "../../includes/commands.hpp"

// Command to setup a topic for the channel
// input[0] = topic
// input[1] = channel
// input[2] = message
int topic(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth() && !client.getRegistered())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }
    if (input.size() < 2)
	{
        // The client didn't provide enough arguments.
        // Send a message back to the client to let them know.
        client.sendMessage("ERROR: You must provide the name of a channel.\n");
        return (0);
    }

    std::string channelName = input[1];
    Channel *channel = server.getChannelByName(channelName);
    if (!channel)
	{
        // The specified channel does not exist.
        // Send a message back to the client to let them know.
        client.sendMessage("ERROR: The specified channel does not exist.\n");
        return (0);
    }

    // Check if client is part of the channel.
    if (!channel->isClient(&client))
    {
        // The client is not part of the specified channel.
        // Send a message back to the client to let them know.
        client.sendMessage("ERROR: You are not part of the specified channel.\n");
        return (0);
    }
    
    // If no topic was provided, return the current topic.
    if (input.size() == 2)
    {
        std::string currentTopic = channel->getTopic();
        client.sendMessage("The topic for " + channelName + " is '" + currentTopic + "'.\n");
    }
    else // A new topic was provided. Set the new topic.
    {
        // if topicRestricted, then Only operator can change topic.
        if (channel->getTopicRestricted() && !channel->isOperator(&client))
        {
            client.sendMessage("ERROR: You are not an operator of the specified channel.\n");
            return (0);
        }
        
        // Set the new topic.
        std::string newTopic = input[2];
        channel->setTopic(newTopic);

        // Notify the client that the topic was successfully changed.
        client.sendMessage("The topic for " + channelName + " has been set to '" + newTopic + "'.\n");
	}
	return (1);
}