/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:50:49 by mnouchet          #+#    #+#             */
/*   Updated: 2023/05/29 17:56:52 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/// @brief Check if a command token string contains any special characters.
/// @param c The character to check.
/// @return 1 if the character is special, 0 otherwise.
bool	special_char(char c)
{
	return (!((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9') || (c == '_')));
}

char	**token_split(char **tokens, size_t *i, bool *split_token, int k)
{
	char	**new_tokens;
	size_t	j;

	new_tokens = (char **)malloc(sizeof(char *) * (k + 2));
	if (!new_tokens)
		return (0);
	j = 0;
	while (j < (*i) - 1)
	{
		new_tokens[j] = tokens[j];
		j++;
	}
	k = 0;
	while (tokens[(*i) - 1][k] != ' ')
		k++;
	new_tokens[j++] = ft_substr(tokens[(*i) - 1], 0, k);
	new_tokens[j] = ft_strdup(tokens[(*i) - 1] + k + 1);
	free(tokens[(*i) - 1]);
	free(tokens);
	(*i)++;
	*split_token = false;
	return (new_tokens);
}

int	check_end_by_quote(char *line, int i)
{
	i--;
	while (i > 0 && is_space(line[i]))
		i--;
	if (line[i] == '"' || line[i] == '\'')
		return (1);
	return (0);
}

int	isinquote(char *token, size_t *i)
{
	size_t	j;

	j = 0;
	while (j < (*i))
	{
		if (token[j] == '"')
		{
			handle_quotes(token, &j);
			if (j > (*i))
				return (1);
		}
		j++;
	}
	return (0);
}
