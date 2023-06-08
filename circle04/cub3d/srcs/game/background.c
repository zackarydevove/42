#include "../../includes/cub3d.h"

void	my_mlx_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static int	get_rgb(int r, int g, int b)
{
	return (0 << 24 | r << 16 | g << 8 | b);
}

void	draw_floor_and_roof(t_data *data, int x, int y)
{
	while (++x < WIN_WIDTH)
	{
		y = -1;
		while (++y < WIN_HEIGHT)
		{
			if (y < WIN_HEIGHT / 2)
				my_mlx_pixel_put(&data->img, x, y,
					get_rgb(data->color_roof[0],
						data->color_roof[1], data->color_roof[2]));
			else
				my_mlx_pixel_put(&data->img, x, y,
					get_rgb(data->color_floor[0],
						data->color_floor[1], data->color_floor[2]));
		}
	}
}