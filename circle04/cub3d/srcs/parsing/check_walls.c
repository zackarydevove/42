#include "../../includes/cub3d.h"

char **copy_map(char **map_src)
{
	char **map_dst;
	int i;

	i = 0;
	while (map_src[i])
		i++;
	map_dst = malloc(sizeof(char *) * (i + 1));
	if (!map_dst)
		return (0);
	i = 0;
	while (map_src[i])
	{
		map_dst[i] = ft_strdup(map_src[i]);
		if (!map_dst[i])
			return (0);
		i++;
	}
	map_dst[i] = NULL;
	return (map_dst);
}

int	check_walls(char **map, int x, int y)
{
	if (map[y][x] == '1')
		return (1);
	map[y][x] = '1';
	if (x == 0 || y == 0 || map[y + 1] == NULL || map[y][x + 1] == '\0')
		return (0);
	if (!check_walls(map, x + 1, y))
		return (0);
	if (!check_walls(map, x - 1, y))
		return (0);
	if (!check_walls(map, x, y + 1))
		return (0);
	if (!check_walls(map, x, y - 1))
		return (0);
	if (!check_walls(map, x + 1, y + 1))
		return (0);
	if (!check_walls(map, x - 1, y - 1))
		return (0);
	if (!check_walls(map, x + 1, y - 1))
		return (0);
	if (!check_walls(map, x - 1, y + 1))
		return (0);
	return (1);
}

void	handle_blank_line(char *line, int *flag, int i)
{
	free(line);
	line = NULL;
	if (i != 0)
		*flag = 1;
}

int  handle_flagged_line(char *line, int fd)
{
    free(line);
	get_next_line(fd, &line, 1);
    ft_putendl_fd("Error\nInvalid map", 2);
    return 0;
}