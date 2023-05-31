/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:58:49 by mnouchet          #+#    #+#             */
/*   Updated: 2023/05/29 18:57:33 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	error_invalid(char *path)
{
	struct stat	sb;

	ft_putstr_fd("minishell: ", STDERR_FILENO);
	ft_putstr_fd("cd: ", STDERR_FILENO);
	ft_putstr_fd(path, STDERR_FILENO);
	if (stat(path, &sb) == -1)
		ft_putstr_fd(": No such file or directory\n", STDERR_FILENO);
	else if (!S_ISDIR(sb.st_mode))
		ft_putstr_fd(": Not a directory\n", STDERR_FILENO);
	else
		ft_putstr_fd(": Unknown error\n", STDERR_FILENO);
}

static char	*home_path(t_env **envs)
{
	t_env	*env;

	env = get_env(*envs, "HOME");
	if (!env)
		return (error("cd", "HOME not set"), NULL);
	return (env->value);
}

static char	*get_path(t_cmd *cmd, t_env **envs)
{
	size_t	i;
	char	*path;
	char	*home;

	i = 1;
	path = NULL;
	while (cmd->args[i])
	{
		if (cmd->args[i][0])
		{
			if (path)
				return (error("cd", "too many arguments"), NULL);
			path = cmd->args[i];
		}
		i++;
	}
	if (!path)
	{
		home = home_path(envs);
		if (home)
			return (ft_strdup(home));
		return (NULL);
	}
	return (ft_strdup(path));
}

static void	tilted_path(t_env **envs, char **path)
{
	char	*home;
	char	*tmp;

	home = home_path(envs);
	if (home)
	{
		tmp = ft_strjoin(home, *path + 1);
		free(*path);
		*path = tmp;
	}
}

/// @brief Execute the cd builtin command
/// @param cmd The command data structure
/// @param envs The environment variables
/// @return EXIT_SUCCESS or EXIT_FAILURE if an error occured
int	builtin_cd(t_cmd *cmd, t_env **envs)
{
	char		*path;
	char		current[1024];

	path = get_path(cmd, envs);
	if (path && path[0] == '~')
		tilted_path(envs, &path);
	if (!path)
		return (EXIT_FAILURE);
	if (path[0])
	{
		if (chdir(path) == -1)
		{
			error_invalid(path);
			return (free(path), EXIT_FAILURE);
		}
		if (getcwd(current, 1024))
			set_env(envs, "PWD", ft_strdup(current));
	}
	free(path);
	return (EXIT_SUCCESS);
}
