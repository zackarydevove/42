#include "../../includes/commands.hpp"

int modeClient(Server &server, Client &client, std::vector<std::string> &input)
{
    (void)server;
    bool add = (input[2][0] == '+') ; // + true - false
    char mode = input[2][1]; // i t k o l

    switch (mode)
    {
        case 'i':
            client.setInvisible(add);
            break;
        case 'w':
            client.setWallops(add);
            break;
        case 'o':
            client.setOp(add);
            break;
        default:
            client.sendMessage(ERR_UMODEUNKNOWNFLAG(client.getNickname()));
            return 0;
    }

    return (1);
}

int modeChannel(Server &server, Client &client, std::vector<std::string> &input, Channel *channel)
{
    (void)server;
    std::string channelName = input[1];
    bool add = (input[2][0] == '+') ; // + true - false
    char mode = input[2][1]; // i t k o l

    Client *op = NULL;

    if (mode != 't' && !channel->isOperator(&client))
    {
        client.sendMessage(ERR_CHANOPRIVSNEEDED(channel->getName(), client.getNickname()));
        return (0);
    }

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
                    client.sendMessage(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"));
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
                client.sendMessage(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"));
                return 0;
            }
            op = channel->getClientByNickname(input[3]);
            if (!op)
            {
                client.sendMessage(ERR_USERNOTINCHANNEL(client.getNickname(), channel->getName(), input[3]));
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
                    client.sendMessage(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"));
                    return 0;
                }
                int limit = std::atoi(input[3].c_str());  // Use atoi instead of stoi
                channel->setLimit(limit);
            }
            else
                channel->setLimit(0);
            break;
        default:
            client.sendMessage(ERR_UMODEUNKNOWNFLAG(client.getNickname()));
            return 0;
    }

    return 1;
}

// input[0] = mode command
// input[1] = channel name
// input[2] = -i +i etc.
// input[3] = password / nickname / limit (optional)
int mode(Server &server, Client &client, std::vector<std::string> &input)
{
    if (!client.getAuth() && !client.getRegistered())
    {
        // Client already authenticate
        client.sendMessage(ERR_NOTREGISTERED(client.getNickname(), "MODE"));
        return 0;
    }
    if (input.size() < 3)
    {
        client.sendMessage(ERR_NEEDMOREPARAMS(client.getNickname(), "MODE"));
        return 0;
    }

    // mode channel
    if (input[1][0] == '#')
    {
        std::string channelName = input[1];
        Channel *channel = server.getChannelByName(channelName);

        if (!channel)
        {
            client.sendMessage(ERR_NOSUCHCHANNEL(client.getNickname(), input[1]));
            return 0;
        }

        return (modeChannel(server, client, input, channel));
    }
    else if (input[1] == client.getNickname())
        return (modeClient(server, client, input));
    else
        client.sendMessage(ERR_USERSDONTMATCH(client.getNickname()));
    return (0);
}