/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:35:07 by zdevove           #+#    #+#             */
/*   Updated: 2022/11/29 09:41:49 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_rd_to_buffer(int fd, char *buffer)
{
	int		rd;
	char	*str;
	char	*tmp;

	str = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!str)
		return (0);
	rd = 1;
	while (!ft_strchr(buffer, '\n') && rd != 0)
	{
		rd = read(fd, str, BUFFER_SIZE);
		if (rd == -1)
		{
			free(str);
			return (0);
		}
		str[rd] = '\0';
		tmp = buffer;
		buffer = ft_strjoin(buffer, str);
		free(tmp);
	}
	free(str);
	return (buffer);
}

char	*get_line(char *buffer)
{
	char	*str;
	int		i;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
	{
		str = ft_substr(buffer, 0, i + 1);
		return (str);
	}
	str = ft_substr(buffer, 0, i);
	return (str);
}

char	*get_rest(char *buffer)
{
	int	i;

	if (ft_strchr(buffer, '\n'))
	{
		i = ft_strlen(ft_strchr(buffer, '\n')) + 1;
		ft_strlcpy(buffer, ft_strchr(buffer, '\n'), i);
		return (buffer);
	}
	free(buffer);
	return (0);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buffer = get_rd_to_buffer(fd, buffer);
	if (!buffer)
		return (0);
	line = get_line(buffer);
	buffer = get_rest(buffer);
	if (!*line)
	{
		free(line);
		return (0);
	}
	return (line);
}
