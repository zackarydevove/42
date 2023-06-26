/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:21:34 by zdevove           #+#    #+#             */
/*   Updated: 2023/06/26 15:21:35 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	start_game(t_data *data)
{
	update_player_posx_posy(data);
	draw_floor_and_roof(data, -1, -1);
	raycasting(data);
	mlx_put_image_to_window(data->mlx, data->win, data->img.img, 0, 0);
	return (0);
}

int	end_game(t_data *data)
{
	free_all(data);
	exit(0);
	return (0);
}

int	handle_keypress(int keycode, t_data *data)
{
	if (keycode == ESC)
		end_game(data);
	if (keycode == W)
		data->move_w = 1;
	if (keycode == A)
		data->move_a = 1;
	if (keycode == D)
		data->move_d = 1;
	if (keycode == S)
		data->move_s = 1;
	if (keycode == RIGHT)
		data->rot_right = 1;
	if (keycode == LEFT)
		data->rot_left = 1;
	return (0);
}

int	handle_keyrelease(int keycode, t_data *data)
{
	if (keycode == W)
		data->move_w = 0;
	if (keycode == A)
		data->move_a = 0;
	if (keycode == D)
		data->move_d = 0;
	if (keycode == S)
		data->move_s = 0;
	if (keycode == RIGHT)
		data->rot_right = 0;
	if (keycode == LEFT)
		data->rot_left = 0;
	return (0);
}
