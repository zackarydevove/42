#include "../../includes/commands.hpp"

extern bool g_shutdown;

// turn off the server
int die(Server &server, Client &client, std::vector<std::string> &input)
{
    (void)server;
    (void)input;

    // Only allow IRC operators to use this command.
    if (!client.getOp()) 
    {
        client.sendMessage("ERROR: You do not have permission to use this command.\n");
        return 0;
    }

    // Notify all clients that the server is shutting down.
    std::string message = "Server is shutting down.\n";
    server.broadcastMessage(message);

    g_shutdown = true;

    return 1;
}
