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
    while (!check_textures(data) && get_next_line(fd, &line))
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
            return (free(line), ft_putendl_fd("Error\nMissing colors or textures or invalid arguments", 2), 0);
    }
    if (!check_textures(data) && !line)
            return (free(line), ft_putendl_fd("Error\nMissing colors or textures or invalid arguments", 2), 0);
    return (1);
}

static int  get_map(t_data *data, char *line, int fd, int i)
{
	while (get_next_line(fd, &line))
    {
		if ((size_t)ft_skip_spaces(line) == ft_strlen(line))
        {
            free(line);
            if (i != 0)
                return (ft_putendl_fd("Error\nInvalid map", 2), 0);
        }
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
		return (ft_putendl_fd("Error\nInvalid map", 2), 0);
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
    return (1);
}
