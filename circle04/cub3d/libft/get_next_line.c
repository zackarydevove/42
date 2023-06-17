/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:35:07 by zdevove           #+#    #+#             */
/*   Updated: 2023/06/16 14:57:39 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_rd_to_buffer(int fd, char *buffer)
{
	int		rd;
	char	*str;
	char	*tmp;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	rd = read(fd, str, BUFFER_SIZE);
	while (!ftt_strchr(buffer, '\n') && rd != 0)
	{
		if (rd == -1 || (rd == 1 && !buffer[0]))
		{
			free(str);
			return (0);
		}
		str[rd] = '\0';
		tmp = buffer;
		buffer = ftt_strjoin(buffer, str);
		free(tmp);
		rd = read(fd, str, BUFFER_SIZE);
	}
	free(str);
	return (buffer);
}

char	*get_line(char *buffer)
{
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	return (ft_substr(buffer, 0, i));
}

char	*get_rest(char *buffer)
{
	int	i;

	if (ftt_strchr(buffer, '\n'))
	{
		i = ft_strlen(ftt_strchr(buffer, '\n')) + 1;
		ftt_strlcpy(buffer, ftt_strchr(buffer, '\n'), i);
	}
	else
	{
		free(buffer);
		buffer = NULL;
	}
	return (buffer);
}

char	*get_next_line(int fd, char **line, int freebuff)
{
	static char		*buffer;

	if (freebuff)
	{
		free(buffer);
		return (0);
	}
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = get_rd_to_buffer(fd, buffer);
	if (!buffer)
		return (0);
	*line = get_line(buffer);
	buffer = get_rest(buffer);
	return (*line);
}
