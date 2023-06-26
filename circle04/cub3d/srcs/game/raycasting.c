/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zdevove <zdevove@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/26 15:21:42 by zdevove           #+#    #+#             */
/*   Updated: 2023/06/26 15:21:49 by zdevove          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

static void	init_step(t_data *data)
{
	if (data->ray.raydirx < 0)
	{
		data->ray.stepx = -1;
		data->ray.sidedistx = (data->ray.posx - data->ray.mapx)
			* data->ray.deltadistx;
	}
	else
	{
		data->ray.stepx = 1;
		data->ray.sidedistx = (data->ray.mapx + 1.0 - data->ray.posx)
			* data->ray.deltadistx;
	}
	if (data->ray.raydiry < 0)
	{
		data->ray.stepy = -1;
		data->ray.sidedisty = (data->ray.posy - data->ray.mapy)
			* data->ray.deltadisty;
	}
	else
	{
		data->ray.stepy = 1;
		data->ray.sidedisty = (data->ray.mapy + 1.0 - data->ray.posy)
			* data->ray.deltadisty;
	}
}

static void	init_raycasting(t_data *data)
{
	data->ray.camerax = 2 * data->ray.x / (double)WIN_WIDTH - 1;
	data->ray.raydirx = data->ray.dirx + data->ray.planex * data->ray.camerax;
	data->ray.raydiry = data->ray.diry + data->ray.planey * data->ray.camerax;
	data->ray.mapx = (int)data->ray.posx;
	data->ray.mapy = (int)data->ray.posy;
	if (data->ray.raydirx == 0)
		data->ray.deltadistx = 2147483647;
	else
		data->ray.deltadistx = fabs(1 / data->ray.raydirx);
	if (data->ray.raydiry == 0)
		data->ray.deltadisty = 2147483647;
	else
		data->ray.deltadisty = fabs(1 / data->ray.raydiry);
	init_step(data);
}

void	init_dda(t_data *data)
{
	data->ray.hit = 0;
	while (data->ray.hit == 0)
	{
		if (data->ray.sidedistx < data->ray.sidedisty)
		{
			data->ray.sidedistx += data->ray.deltadistx;
			data->ray.mapx += data->ray.stepx;
			data->ray.side = 0;
		}
		else
		{
			data->ray.sidedisty += data->ray.deltadisty;
			data->ray.mapy += data->ray.stepy;
			data->ray.side = 1;
		}
		if (data->map[data->ray.mapy][data->ray.mapx] == '1')
			data->ray.hit = 1;
	}
}

static void	init_perp_wall_dist(t_data *data)
{
	if (data->ray.side == 0)
		data->ray.perpwalldist = (data->ray.sidedistx - data->ray.deltadistx);
	else
		data->ray.perpwalldist = (data->ray.sidedisty - data->ray.deltadisty);
}

void	raycasting(t_data *data)
{
	data->ray.x = 0;
	while (data->ray.x < WIN_WIDTH)
	{
		init_raycasting(data);
		init_dda(data);
		init_perp_wall_dist(data);
		draw_textures(data);
		data->ray.x++;
	}
}
