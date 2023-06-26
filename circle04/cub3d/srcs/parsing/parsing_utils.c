#include "../../includes/cub3d.h"

void	init_player_pos(t_data *data, int y, int x)
{
	data->ray.posx = x + 0.5;
	data->ray.posy = y + 0.5;
	data->ray.mapx = x;
	data->ray.mapy = y;
	if (data->map[y][x] == 'N')
		data->ray.diry = -1;
	else if (data->map[y][x] == 'S')
		data->ray.diry = 1;
	else if (data->map[y][x] == 'W')
		data->ray.dirx = -1;
	else if (data->map[y][x] == 'E')
		data->ray.dirx = 1;
	if (data->ray.diry == -1)
		data->ray.planex = 0.66;
	else if (data->ray.diry == 1)
		data->ray.planex = -0.66;
	else if (data->ray.dirx == -1)
		data->ray.planey = -0.66;
	else if (data->ray.dirx == 1)
		data->ray.planey = 0.66;
    data->map[data->ray.mapy][data->ray.mapx] = '0';
}

int	check_textures(t_data *data)
{
	if (!data->n.img 
		|| !data->s.img
		|| !data->w.img 
		|| !data->e.img
		|| data->color_roof[0] == -1
		|| data->color_floor[0] == -1)
		return (0);
	return (1);
}

int	get_color(char *line, int *colors)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_split(line, ',');
	if (!split)
		return (0);
	while (split[i])
		i++;
	if (i != 3)
		return (ft_putendl_fd("Error\nRGB values not valid", 2),
                free_split(split), 0);
	while (i--)
	{
		colors[i] = ft_atoi(split[i]);
		if (colors[i] < 0 || colors[i] > 255 || !ft_isdigit(split[i][0]))
			return (ft_putendl_fd("Error\nRGB values not valid", 2),
                free_split(split), 0);
	}
	free_split(split);
	return (1);
}

int	get_img(t_data *data, char *line, t_img *img)
{
	int		height;
	int		width;

    img->img = mlx_xpm_file_to_image(data->mlx,
			line + 3 + ft_skip_spaces(line + 3), &width, &height);
	if (!img->img)
        return (ft_putendl_fd("Error\nImage not valid", 2), 0);
    return (1);
}

void	*realloc_map(void *ptr, size_t ptrsize, size_t newsize)
{
	void	*newptr;

	if (ptr == NULL)
		return (ft_calloc(newsize, 1));
	if (newsize == 0)
		return (free(ptr), NULL);
	if (newsize <= ptrsize)
		return (ptr);
	newptr = ft_calloc(newsize, 1);
	if (!newptr)
		return (NULL);
	ft_memcpy(newptr, ptr, ptrsize);
	free(ptr);
	return (newptr);
}