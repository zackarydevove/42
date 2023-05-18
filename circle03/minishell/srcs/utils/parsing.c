/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnouchet <mnouchet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 16:34:15 by mnouchet          #+#    #+#             */
/*   Updated: 2023/05/05 14:30:29 by mnouchet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Check if the character is a space
/// @param c The character to check
/// @return 1 if the character is a space, 0 otherwise
int	is_space(char c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

void	skip_spaces(char *line, size_t *i)
{
    while (is_space(line[(*i)]))
        (*i)++;
}

int	skip_quotes(char *line)
{
	int		i;
	char	quote;

	i = 1;
	quote = line[0];
	while (line[i] && line[i] != quote)
			i++;
	if (line[i] == quote)
		return (i + 1);
	return (-1);
}

int handle_quotes(char *line, size_t *i)
{
    int skip;

    skip = skip_quotes(line + (*i));
    if (skip == -1)
        return (0);
    (*i) += skip;
    return (1);
}

int special_char(char c)
{
    return !((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || 
             (c >= '0' && c <= '9') || (c == '_'));

//     char *special_chars = "!@#$%^&*()\\+=-~{}[]:;'<>,.?/|";
//     int i;

//     i = 0;
//     while (special_chars[i])
//     {
//         if (c == special_chars[i])
//             return 1;
//         i++;
//     }
//     return 0;
}

static char    *replace_env_var2(char *token, int key_len, t_env *head, int i)
{
	char    *before;
    char    *after;
    char    *temp;

    before = ft_substr(token, 0, i);
    after = ft_strdup(token + i + key_len);
	printf("\nbefore: %s\nafter; %s\n", before, after);
    temp = token;
	if (head)
            token = ft_strjoin(before, head->value);
	else
			token = before;
	free(temp);
	temp = token;
    token = ft_strjoin(token, after);
    free(temp);
    free(before);
    free(after);
	return (token);
}

char    *replace_env_var(t_env *envs, char *token)
{
    t_env   *head;
    size_t  i;
    size_t  key_len;
    char    *key;

    i = 0;
    while (token[++i])
    {
        if (token[i] == '$')
        {
            key_len = 1;
            while (!special_char(token[i + key_len]))
                key_len++;
            key = ft_substr(token, i + 1, key_len - 1);
            head = envs;
            while (head && ft_strncmp(key, head->key, ft_strlen(key)) != 0)
            	head = head->next;
			token = replace_env_var2(token, key_len, head, i);
            free(key);
        }
    }
    return (token);
}

char 	*trim_token_quote(char **token, char quote, int len, t_env *envs)
{
	int i;
	int j;
	char *src;
	char *dst;

	i = 0;
	j = 0;
	src = *token;
	while (src[i])
		if (src[i++] == quote)
			j++;
	dst = malloc((len - j + 3) * sizeof(char));
	if (!dst)
		return (0);
	i = -1;
	j = 1;
	dst[0] = quote;
	while (++i < len)
		if (src[i] != quote)
			dst[j++] = src[i];
	dst[j++] = quote;
	dst[j] = '\0';
	free(*token);
	if (quote == '"' && ft_strchr(dst, '$'))
		return (replace_env_var(envs, dst));
	return (dst);
}

void    increase_token_index(size_t *count, size_t *i)
{
    (*count)++;
    (*i)++;
}

/// @brief Check if the line contains pipes
/// @param str The line to check
/// @return 1 if the line contains pipes, 0 otherwise
int	has_pipes(char *str)
{
    int	i;

	i = 0;
	if (str[i] == '\'' || str[i] == '"')
		return (0);
	while (str[i])
	{
		if (str[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

int valid_last_command(char **tokens, int i)
{
    if (tokens[i][0] == '|' && tokens[i + 1][0] == '>' && !tokens[i + 3])
        return (0);
    return (1);
}

void	cmds_has_pipes(t_cmd *cmds)
{
	t_cmd *head;

	head = cmds;
	while (head)
	{
		head->has_pipe = 1;
		head = head->next;
	}
}