#include "minishell.h"

/// @brief Print an error message to the standard error
/// @param msg The main error message
/// @param more Additional error information
/// @return 1 indicating that an error occurred
int	ft_errorendl(char *msg, char *more)
{
	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd(msg, STDERR_FILENO);
	if (more)
	{
		ft_putstr_fd(": ", STDERR_FILENO);
		ft_putstr_fd(more, STDERR_FILENO);
	}
	ft_putchar_fd('\n', STDERR_FILENO);
	return (1);
}