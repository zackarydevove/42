/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:21:57 by zdevove           #+#    #+#             */
/*   Updated: 2023/06/26 15:22:45 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	move_forward(t_data *data)
{
	if (data->map[(int)(data->ray.posy + data->ray.diry
			* data->move_speed)][(int)data->ray.posx] == '0')
		data->ray.posy += data->ray.diry * data->move_speed;
	if (data->map[(int)data->ray.posy][(int)(data->ray.posx + data->ray.dirx
		* data->move_speed)] == '0')
		data->ray.posx += data->ray.dirx * data->move_speed;
}

static void	move_backward(t_data *data)
{
	if (data->map[(int)(data->ray.posy - data->ray.diry
			* data->move_speed)][(int)data->ray.posx] == '0')
		data->ray.posy -= data->ray.diry * data->move_speed;
	if (data->map[(int)data->ray.posy][(int)(data->ray.posx - data->ray.dirx
		* data->move_speed)] == '0')
		data->ray.posx -= data->ray.dirx * data->move_speed;
}

static void	move_left(t_data *data)
{
	if (data->map[(int)(data->ray.posy - data->ray.planey
			* data->move_speed)][(int)data->ray.posx] == '0')
		data->ray.posy -= data->ray.planey * data->move_speed;
	if (data->map[(int)data->ray.posy][(int)(data->ray.posx - data->ray.planex
		* data->move_speed)] == '0')
		data->ray.posx -= data->ray.planex * data->move_speed;
}

static void	move_right(t_data *data)
{
	if (data->map[(int)(data->ray.posy + data->ray.planey
			* data->move_speed)][(int)data->ray.posx] == '0')
		data->ray.posy += data->ray.planey * data->move_speed;
	if (data->map[(int)data->ray.posy][(int)(data->ray.posx + data->ray.planex
		* data->move_speed)] == '0')
		data->ray.posx += data->ray.planex * data->move_speed;
}

void	update_player_posx_posy(t_data *data)
{
	if (data->move_w)
		move_forward(data);
	if (data->move_s)
		move_backward(data);
	if (data->move_a)
		move_left(data);
	if (data->move_d)
		move_right(data);
	if (data->rot_left)
		rotate_left(data);
	if (data->rot_right)
		rotate_right(data);
}
