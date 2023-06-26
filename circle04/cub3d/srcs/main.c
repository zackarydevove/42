/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:19:27 by zdevove           #+#    #+#             */
/*   Updated: 2023/06/26 15:33:12 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i++]);
	}
	if (split)
		free(split);
}

void	free_all(t_data *data)
{
	if (data->n.img != 0)
		mlx_destroy_image(data->mlx, data->n.img);
	if (data->s.img != 0)
		mlx_destroy_image(data->mlx, data->s.img);
	if (data->w.img != 0)
		mlx_destroy_image(data->mlx, data->w.img);
	if (data->e.img != 0)
		mlx_destroy_image(data->mlx, data->e.img);
	if (data->img.img != 0)
		mlx_destroy_image(data->mlx, data->img.img);
	mlx_clear_window(data->mlx, data->win);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	if (data->map)
		free_split(data->map);
	free(data->mlx);
}

static void	init_movement(t_data *data)
{
	data->move_w = 0;
	data->move_a = 0;
	data->move_d = 0;
	data->move_s = 0;
	data->rot_left = 0;
	data->rot_right = 0;
	data->rot_speed = 0.07;
	data->move_speed = 0.12;
	data->ray.diry = 0;
	data->ray.dirx = 0;
	data->ray.x = 0;
	data->ray.planex = 0;
	data->ray.planey = 0;
	data->ray.camerax = 0;
	data->ray.posx = 0;
	data->ray.posy = 0;
	data->ray.texheight = 64;
}

static int	init_data(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		return (0);
	data->win = mlx_new_window(data->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	data->map = 0;
	data->n.img = NULL;
	data->e.img = NULL;
	data->s.img = NULL;
	data->w.img = NULL;
	init_movement(data);
	data->color_roof[0] = -1;
	data->color_floor[0] = -1;
	data->img.img = mlx_new_image(data->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (!data->img.img)
		return (0);
	data->img.addr = mlx_get_data_addr(data->img.img, &data->img.bits_per_pixel,
			&data->img.line_length, &data->img.endian);
	if (!data->img.addr)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		return (1);
	if (!init_data(&data))
		return (free_all(&data), 1);
	if (!parsing(&data, av[1]))
		return (free_all(&data), 1);
	mlx_loop_hook(data.mlx, start_game, &data);
	mlx_hook(data.win, 2, 1L << 0, handle_keypress, &data);
	mlx_hook(data.win, 3, 1L << 1, handle_keyrelease, &data);
	mlx_hook(data.win, 17, 0, end_game, &data);
	mlx_loop(data.mlx);
	return (free_all(&data), 0);
}
