/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   onechar_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:35:50 by zdevove           #+#    #+#             */
/*   Updated: 2023/04/21 16:35:52 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_init_data(t_data *data)
{
	data->height = 0;
	data->width = 0;
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->flag_e = 0;
	data->counter = 0;
	data->idx_p = 0;
	data->idx_e = 0;
}

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
