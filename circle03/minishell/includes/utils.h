/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:46:24 by mnouchet          #+#    #+#             */
/*   Updated: 2023/05/21 17:22:21 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include "types.h"
# include <stddef.h>
# include <stdbool.h>

// utils/error.c
void	error(char *msg, char *more);
void	error_heredoc(char *delimiter);

// utils/signal.c
void	signal_handler(int signal);

// utils/str.c
bool	is_space(char c);
void	skip_spaces(char *line, size_t *i);
bool	handle_quotes(char *line, size_t *i);
void	increase_token_index(size_t *count, size_t *i);

// utils/pipes.c
bool	has_pipes(char *str);
bool	valid_last_command(char **tokens, size_t i);
void	cmds_has_pipes(t_cmd *cmds);

// utils/env.c
char	*trim_token_quote(char **token, char quote, int len, t_env *envs);

// utils/path.c
char	*join_path(char *s1, char *s2);
char	*resolve_path(char *file, t_env *envs);

// utils/exec/redirs.c
# define HEREDOC_FILE "/tmp/heredoc"

bool	init_redirs(char **tokens, size_t i, t_cmd *node);
void	redirs(t_cmd *cmd);
void	close_redirs(t_cmd *cmds);

// utils/exec/pipeline.c
void	wait_processes(t_cmd *cmds);
int		pipeline(t_cmd *cmds, t_env **envs);

// utils/exec/exec.c
# define BUILTIN_NOT_FOUND -1

int		exec_builtin(t_cmd *cmd, t_env **envs);
int		exec_relative(t_cmd *cmd, t_env **envs);
int		exec_cmds(t_cmd *cmds, t_env **envs);

#endif