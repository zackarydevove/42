#include "../../includes/commands.hpp"

std::vector<std::string> spliit(const std::string &s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}

// input[0] = part command
// input[1] = channel
// input[2] = message (optional)
int part(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth() && !client.getRegistered())
    {
        client.sendMessage(ERR_NOTREGISTERED(client.getNickname(), "PART"));
        return 0;
    }

    if (input.size() >= 2)
    {
	    std::vector<std::string> channels = spliit(input[1], ',');
	    for (std::vector<std::string>::iterator it = channels.begin(); it != channels.end(); it++)
        {
            std::cout << (*it) << std::endl;
            Channel *channel = server.getChannelByName((*it).substr(1));
            std::cout << (*it).substr(1) << std::endl;
            if (channel)
            {
                std::cout << "test1" << std::endl;
                // Check if the client is a member of this channel.
                if (!channel->isClient(&client))
                {
                    std::cout << "test2" << std::endl;
                    // The client is not a member of the channel.
                    client.sendMessage(ERR_NOTONCHANNEL(client.getNickname(), (*it)));
                    return 0;
                }

                // if message;
                std::string message = "";
                if (input.size() >= 3)
                    message = input[2];

                std::cout << "test4" << std::endl;

                // Broadcast the part message
                channel->broadcastMessage(PART(client.getNickname(), client.getUsername(), channel->getName(), message), NULL);
                // Client leaves the channel
                client.leaveChannel(channel);
                std::cout << "test5" << std::endl;
            }
            else
            {
                    // The channel does not exist.
                    client.sendMessage(ERR_NOSUCHCHANNEL(client.getNickname(), (*it)));
                    return 0;

            }
        }

    }
    else
    {
        // The client didn't provide the channel name.
        client.sendMessage(ERR_NEEDMOREPARAMS(client.getNickname(), "PART"));
        return 0;
    }
    return (1);
}