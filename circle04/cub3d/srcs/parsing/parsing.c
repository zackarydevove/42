#include "../../includes/cub3d.h"

static int  check_name(char *path)
{
	char	*str;

	if (ft_strlen(path) >= 4)
		str = ft_substr(path, ft_strlen(path) - 4, 4);
	else
		return (ft_putendl_fd("Error\nNot valid file", 2), 0);
	if (ft_strncmp(str, ".cub", 4) != 0)
		return (free(str), ft_putendl_fd("Error\nNot .cub file", 2), 0);
	free(str);
	return (1);
}

static int  get_textures(t_data *data, char *line, int fd)
{
    while (!check_textures(data) && get_next_line(fd, &line, 0))
    {
		if ((size_t)ft_skip_spaces(line) == ft_strlen(line) || line[0] == '\n')
            free(line);
        else if ((!ft_strncmp(line, "C ", 2) && get_color(line + 2, data->color_roof))
            || (!ft_strncmp(line, "F ", 2) && get_color(line + 2, data->color_floor))
            || (!ft_strncmp(line, "NO ", 3) && get_img(data, line, &data->n))
            || (!ft_strncmp(line, "SO ", 3) && get_img(data, line, &data->s))
            || (!ft_strncmp(line, "WE ", 3) && get_img(data, line, &data->w))
            || (!ft_strncmp(line, "EA ", 3) && get_img(data, line, &data->e)))
            free(line);
        else
            return (free(line), get_next_line(fd, &line, 1), 
                ft_putendl_fd("Error\nMissing colors or textures or invalid arguments", 2), 0);
    }
    if (!check_textures(data) && !line)
            return (free(line), ft_putendl_fd("Error\nMissing colors or textures or invalid arguments", 2), 0);
    return (1);
}

static int  get_map(t_data *data, char *line, int fd, int i)
{
    int	flag;

    flag = 0;
	while (get_next_line(fd, &line, 0))
    {
		if ((size_t)ft_skip_spaces(line) == ft_strlen(line))
			handle_blank_line(line, &flag, i);
		else if (flag)
			return (handle_flagged_line(line, fd));
        else
        {
            data->map = realloc_map(data->map, sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
            if (!data->map)
                    return (0);
            line[ft_strlen(line)] = '\0';
            data->map[i++] = line;
            data->map[i] = NULL;
        }
    }
	if (i == 0)
		return (ft_putendl_fd("Error\nNot valid map", 2), 0);
    return (1);
}

static int  check_map(t_data *data, int i, int j, int player_count)
{
	while (data->map[++i])
	{
		j = -1;
		while (data->map[i][++j] && data->map[i][j] != '\n')
        {
            if (data->map[i][j] == 'N' || data->map[i][j] == 'S' 
                || data->map[i][j] == 'E' || data->map[i][j] == 'W')
            {
                init_player_pos(data, i, j);
                player_count++;
            }
			else if (ft_isspace(data->map[i][j]))
				data->map[i][j] = '0';
            else if (data->map[i][j] != '1' && data->map[i][j] != '0')
                return (ft_putendl_fd("Error\nNot valid map", 2), 0);
        }
	}
    if (player_count != 1)
		return (ft_putendl_fd("Error\nNeed only 1 player", 2), 0);
	return (1);
}

int parsing(t_data *data, char *path)
{
    int fd;
	char **map_cpy;


    fd = open(path, O_RDONLY);
    if (fd < 0)
        return (ft_putendl_fd("Error\nWrong file", 2), 0);
    if (!check_name(path))
        return (0);
    if (!get_textures(data, NULL, fd))
        return (0);
    if (!get_map(data, NULL, fd, 0))
        return (0);
    if (!check_map(data, -1, -1, 0))
		return (0);

	map_cpy = copy_map(data->map);
	if (!map_cpy)
		return (0);
	if (!check_walls(map_cpy, data->ray.posx - 0.5, data->ray.posy - 0.5))
		return (free_split(map_cpy), ft_putendl_fd("Error\nMap not surrounded by walls", 2), 0);
	free_split(map_cpy);

    return (1);
}
