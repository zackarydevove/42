#include "../../includes/commands.hpp"

// La commande /oper permet de t'authentificier au près du serveur
// afin que ce dernier te donne le status de IRCOperator.
// input[0] = oper command
// input[1] = name
// input[2] = password
int oper(Server &server, Client &client, std::vector<std::string> &input)
{
    if (input.size() < 3)
    {
        // Not enough parameters were provided.
        client.sendMessage("ERROR: Not enough parameters. Syntax: OPER <name> <password>\n");
        return 0;
    }

    std::string name = input[1];
    std::string password = input[2];

    Client *clientToSetOp = server.getClientByNickname(name);
    if (!clientToSetOp)
    {
        // Client not found.
        client.sendMessage("ERROR: Client not found\n");
        return 0;
    }

    // Check if the name and password combination is valid.
    if (server.getPassword() != password)
    {
        // The credentials are not valid.
        client.sendMessage("ERROR: Invalid operator credentials.\n");
        return (0);
    }
    // The credentials are valid. Give the client operator privileges.
    clientToSetOp->setOp(true);
    clientToSetOp->sendMessage("You are now an IRC operator.\n");

    return 1;
}
