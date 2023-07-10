#include "../../includes/commands.hpp"

// input[0] = mode command
// input[1] = channel name
// input[2] = -i +i etc.
// input[3] = password / nickname (optional)
int mode(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth())
    {
        // Client already authenticate
        client.sendMessage("ERROR: You are are not authenticated.\nYou need to use the PASS command.\n");
        return 0;
    }
    if (input.size() < 3)
    {
        client.sendMessage("ERROR: You must provide the name of a channel and a mode.\n");
        return 0;
    }

    std::string channelName = input[1];
    Channel *channel = server.getChannelByName(channelName);

    if (!channel)
    {
        client.sendMessage("ERROR: The specified channel does not exist.\n");
        return 0;
    }

    if (!channel->isOperator(&client))
    {
        client.sendMessage("ERROR: You are not an operator of the specified channel.\n");
        return 0;
    }

    bool add = (input[2][0] == '+') ; // + = true - = false
    char mode = input[2][1]; // i t k o l

    Client *op = NULL;

    switch (mode)
    {
        case 'i':
            // Set or remove Invite-only channel
            channel->setInviteOnly(add);
            break;
        case 't':
            // Set or remove the restrictions of the TOPIC command to channel operators
            channel->setTopicRestricted(add);
            break;
        case 'k':
            // Set or remove the channel key (password)
            if (add)
            {
                if (input.size() < 4)
                {
                    client.sendMessage("ERROR: You must provide a password.\n");
                    return 0;
                }
                channel->setPassword(input[3]);
            }
            else
                channel->setPassword("");
            break;
        case 'o':
            // Give/take channel operator privilege
            if (input.size() < 4)
            {
                client.sendMessage("ERROR: You must provide the nickname of a client.\n");
                return 0;
            }
            op = channel->getClientByNickname(input[3]);
            if (!op)
            {
                client.sendMessage("ERROR: The specified client does not exist.\n");
                return 0;
            }
            if (add)
                channel->addOperator(op);
            else
                channel->removeOperator(op);
            break;
        case 'l':
            // Set/remove the user limit to channel
            if (add)
            {
                if (input.size() < 4)
                {
                    client.sendMessage("ERROR: You must provide a user limit.\n");
                    return 0;
                }
                int limit = std::atoi(input[3].c_str());  // Use atoi instead of stoi
                channel->setLimit(limit);
            }
            else
                channel->setLimit(0);
            break;
        default:
            client.sendMessage("ERROR: Invalid mode.\n");
            return 0;
    }

    client.sendMessage("The mode for " + channelName + " has been changed successfully.\n");
    return 1;
}