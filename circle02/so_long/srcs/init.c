/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:12:17 by zdevove           #+#    #+#             */
/*   Updated: 2023/01/29 15:18:35 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_data(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->steps_count = 0;
	while (i < data->nb_line)
	{
		j = 0;
		while (data->matrix[i][j] && data->matrix[i][j] != '\n')
		{
			if (data->matrix[i][j] == 'P')
			{
				data->p_j = j;
				data->p_i = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	img_init(t_data *data)
{
	data->img_floor = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/floor.xpm" \
	, &data->width, &data->height);
	data->img_wall = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/wall.xpm" \
	, &data->width, &data->height);
	data->img_consumable = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/consumable.xpm" \
	, &data->width, &data->height);
	data->img_player = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/player1.xpm" \
	, &data->width, &data->height);
	data->img_exit = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/exit.xpm" \
	, &data->width, &data->height);
}

int	put_value_in_data(t_data *data, char *map_path)
{
	data->matrix = ft_create_matrix(data, map_path);
	if (data->matrix == 0)
		return (ft_putendl_fd("Error\nNot valid file", 2), 0);
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, 32 * 32, 32 * 32, "SO_LONG");
	data->height = 0;
	data->width = 0;
	data->c = 0;
	data->e = 0;
	data->p = 0;
	data->flag_e = 0;
	get_max_column(data);
	img_init(data);
	player_data(data);
	return (1);
}

int	malloc_data_center(t_data **data)
{
	(*data) = malloc(sizeof(t_data));
	if (!(*data))
		return (0);
	(*data)->center = malloc(sizeof(t_center));
	if (!(*data)->center)
		return (free((*data)), 0);
	(*data)->center->idx_down = 0;
	(*data)->center->idx_up = 0;
	(*data)->center->idx_left = 0;
	(*data)->center->idx_right = 0;
	return (1);
}

void	*ft_create_img(t_data *data, char c)
{
	if (c == '0' || c == 'P')
		return (data->img_floor);
	else if (c == '1')
		return (data->img_wall);
	else if (c == 'C')
		return (data->img_consumable);
	else if (c == 'E')
		return (data->img_exit);
	ft_putendl_fd("Error\nNot a 0 1 C P or E", 2);
	return (NULL);
}
