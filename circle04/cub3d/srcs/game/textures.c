
#include "../../includes/cub3d.h"

static void	init_texture_pixel(t_data *data)
{
	data->ray.lineheight = (int)(WIN_HEIGHT / data->ray.perpwalldist);
	data->ray.drawstart = -data->ray.lineheight / 2 + (int)WIN_HEIGHT / 2;
	if (data->ray.drawstart < 0)
		data->ray.drawstart = 0;
	data->ray.drawend = data->ray.lineheight / 2 + (int)WIN_HEIGHT / 2;
	if (data->ray.drawend >= WIN_HEIGHT)
		data->ray.drawend = WIN_HEIGHT - 1;
	if (data->ray.side == 0)
	{
		data->ray.wallx = data->ray.posy
			+ data->ray.perpwalldist * data->ray.raydiry;
	}
	else
		data->ray.wallx = data->ray.posx
			+ data->ray.perpwalldist * data->ray.raydirx;
	data->ray.wallx -= floor(data->ray.wallx);
	data->ray.texx = (int)(data->ray.wallx * (double)(data->ray.texHeight));
	if (data->ray.side == 0 && data->ray.raydirx > 0)
		data->ray.texx = data->ray.texHeight - data->ray.texx - 1;
	if (data->ray.side == 1 && data->ray.raydiry < 0)
		data->ray.texx = data->ray.texHeight - data->ray.texx - 1;
	data->ray.step = 1.0 * data->ray.texHeight / data->ray.lineheight;
	data->ray.texpos = (data->ray.drawstart - (double)WIN_HEIGHT / 2
			+ (double)data->ray.lineheight / 2) * data->ray.step;
}

static void	put_pixel(t_data *data, t_img *img)
{
	t_img			tmp;
	char			*pos;

	tmp.addr = mlx_get_data_addr(img->img, &tmp.bits_per_pixel, &tmp.line_length,
			&tmp.endian);
	pos = tmp.addr + (data->ray.texy * tmp.line_length + data->ray.texx *
		(tmp.bits_per_pixel / 8));
	my_mlx_pixel_put(&data->img, data->ray.x, data->ray.drawstart,
		*(unsigned int *)pos);
}

void	draw_textures(t_data *data)
{
	init_texture_pixel(data);
	while (data->ray.drawstart < data->ray.drawend)
	{
		data->ray.texy = (int)data->ray.texpos & (data->ray.texHeight - 1);
		data->ray.texpos += data->ray.step;
		if (data->ray.side == 1 && data->ray.raydiry > 0)
			put_pixel(data, &data->n);
		else if (data->ray.side == 1 && data->ray.raydiry < 0)
			put_pixel(data, &data->s);
		else if (data->ray.side == 0 && data->ray.raydirx < 0)
			put_pixel(data, &data->w);
		else if (data->ray.side == 0 && data->ray.raydirx > 0)
			put_pixel(data, &data->e);
		data->ray.drawstart++;
	}
}
