/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onechar.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 19:20:53 by zdevove           #+#    #+#             */
/*   Updated: 2023/04/14 19:29:21 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	readonechar(char *map_path)
{
	int		fd;
	char	*str;

	str = malloc(2 * sizeof(char));
	if (!str)
		return (0);
	str[0] = 0;
	str[1] = 0;
	fd = open(map_path, O_RDONLY);
	read(fd, str, 2);
	close(fd);
	if (str[1] == '\0')
		return (free(str), 0);
	return (free(str), 1);
}
