/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 11:12:17 by zdevove           #+#    #+#             */
/*   Updated: 2023/01/29 17:36:30 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	set_enemy_img(t_data *data)
{
	data->img_enemy[0] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/enemy/enemy0.xpm" \
	, &data->width, &data->height);
	data->img_enemy[1] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/enemy/enemy1.xpm" \
	, &data->width, &data->height);
	data->img_enemy[2] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/enemy/enemy2.xpm" \
	, &data->width, &data->height);
	data->img_enemy[3] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/enemy/enemy3.xpm" \
	, &data->width, &data->height);
	data->img_enemy[4] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/enemy/enemy4.xpm" \
	, &data->width, &data->height);
	data->img_enemy[5] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/enemy/enemy5.xpm" \
	, &data->width, &data->height);
	data->img_enemy[6] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/enemy/enemy6.xpm" \
	, &data->width, &data->height);
	data->img_enemy[7] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/enemy/enemy7.xpm" \
	, &data->width, &data->height);
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
	data->img_player[0] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/player1.xpm" \
	, &data->width, &data->height);
	data->img_player[1] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/player2.xpm" \
	, &data->width, &data->height);
	data->img_player[2] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/player3.xpm" \
	, &data->width, &data->height);
	data->img_player[3] = mlx_xpm_file_to_image(data->mlx, \
	"/mnt/nfs/homes/zdevove/STUD/Exam03/so_long/images/player4.xpm" \
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
	data->counter = 0;
	data->idx_p = 0;
	data->idx_e = 0;
	get_max_column(data);
	img_init(data);
	player_data(data);
	set_enemy_img(data);
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
