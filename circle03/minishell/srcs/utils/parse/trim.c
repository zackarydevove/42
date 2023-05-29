/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trim.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 16:00:24 by mnouchet          #+#    #+#             */
/*   Updated: 2023/05/29 17:48:08 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Perform the second part of environment variable
/// replacement in a token string.
/// @param token The token string.
/// @param key_len The length of the key of the environment variable.
/// @param head A pointer to the environment variable list.
/// @param i The index in the token string where the replacement starts.
/// @return The updated token string after environment variable replacement.
static char	*replace_env_var2(char *token, int key_len, t_env *head, int i)
{
	char	*before;
	char	*after;
	char	*temp;

	before = ft_substr(token, 0, i);
	after = ft_strdup(token + i + key_len);
	temp = token;
	if (head)
	{
		token = ft_strjoin(before, head->value);
		free(before);
	}
	else
		token = before;
	free(temp);
	temp = token;
	token = ft_strjoin(token, after);
	free(temp);
	free(after);
	return (token);
}

static char	*replace_env_var_ext(char *token, int i,
	t_env *envs, bool *split_token)
{
	char	*key;
	size_t	key_len;
	size_t y;

	y = 0;
	key_len = 1;
	while (token[i + key_len] && !special_char(token[i + key_len]))
		key_len++;
	if ((token[i + 1] >= '0' && token[i + 1] <= '9')
		|| token[i + 1] == '"' || token[i + 1] == '\'')
		key_len = 2;
	key = ft_substr(token, i + 1, key_len - 1);
	token = replace_env_var2(token, key_len, get_env(envs, key), i);
	free(key);
	while (token[y] && !isspace(token[y]))
		y++;
	if (token[y] && isspace(token[y]))
	{
		while (token[++y])
			if (!isspace(token[y]))
				*split_token = true;
	}
	return (token);
}

static int	replace_env_var_ext2(char **token, size_t *i,
	t_env *envs, bool *split_token)
{
	if ((*token)[(*i)] == '$' && (*token)[(*i) + 1]
		&& ((*token)[(*i) + 1] == '?'))
		(*token) = replace_env_var2((*token), 2, get_env(envs, "?"), *i);
	else if ((*token)[(*i)] == '$' && isinquote(*token, i) 
				&& (*token)[(*i) + 1] && ((*token)[(*i) + 1] == '"'
				|| (*token)[(*i) + 1] == '\''))
	{
		(*i)++;
		return (0);
	}
	else if ((*token)[(*i) + 1] && (!special_char((*token)[(*i) + 1])
			|| (*token)[(*i) + 1] == '"' || (*token)[(*i) + 1] == '\''))
		(*token) = replace_env_var_ext((*token), (*i), envs, split_token);
	else
	{
		(*i)++;
		return (0);
	}
	(*i) = 0;
	return (1);
}

/// @brief Replace environment variables in a token string.
/// @param envs The environment variable list.
/// @param token The token string.
/// @return The updated token string after environment variable replacement.
char	*replace_env_var(t_env *envs, char *token, bool *split_token)
{
	size_t	i;
	char	quote;

	i = 0;
	quote = 0;
	while (token[i])
	{
		if (!quote && (token[i] == '\'' || token[i] == '"'))
			quote = token[i++];
		else if (token[i] == quote)
		{
			quote = 0;
			i++;
		}
		else if (token[i] == '$' && quote != '\'')
		{
			if (!replace_env_var_ext2(&token, &i, envs, split_token))
				continue ;
		}
		else
			i++;
	}
	return (token);
}

/// @brief Trim the quote characters from a token string
/// @param token The pointer to the token string.
/// @param quote The quote character to be trimmed.
/// @param len The length of the token string.
/// @param envs The environment variable list.
/// @return The updated token string after trimming and environment
/// variable replacement.
char	*trim_token_quote(char **token)
{
	char	quote;
	char	*str;
	size_t	i;
	size_t	str_index;

	str = (char *)malloc(sizeof(char) * strlen((*token)) + 1);
	if (!str)
		return (NULL);
	i = 0;
	str_index = 0;
	quote = '\0';
	while (i < ft_strlen((*token)))
	{
		if (!quote && ((*token)[i] == '\'' || (*token)[i] == '\"'))
			quote = (*token)[i++];
		else if (quote && (*token)[i] == quote)
		{
			quote = '\0';
			i++;
		}
		else
			str[str_index++] = (*token)[i++];
	}
	str[str_index] = '\0';
	return (free(*token), str);
}
