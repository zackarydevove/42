#include "../../includes/cub3d.h"

void	rotate_left(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dirx;
	old_plane_x = data->ray.planex;
	data->ray.dirx = data->ray.dirx * cos(data->rot_speed)
		- data->ray.diry * sin(data->rot_speed);
	data->ray.diry = old_dir_x * sin(data->rot_speed)
		+ data->ray.diry * cos(data->rot_speed);
	data->ray.planex = data->ray.planex * cos(data->rot_speed)
		- data->ray.planey * sin(data->rot_speed);
	data->ray.planey = old_plane_x * sin(data->rot_speed)
		+ data->ray.planey * cos(data->rot_speed);
}

void	rotate_right(t_data *data)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = data->ray.dirx;
	old_plane_x = data->ray.planex;
	data->ray.dirx = data->ray.dirx * cos(-data->rot_speed)
		- data->ray.diry * sin(-data->rot_speed);
	data->ray.diry = old_dir_x * sin(-data->rot_speed)
		+ data->ray.diry * cos(-data->rot_speed);
	data->ray.planex = data->ray.planex * cos(-data->rot_speed)
		- data->ray.planey * sin(-data->rot_speed);
	data->ray.planey = old_plane_x * sin(-data->rot_speed)
		+ data->ray.planey * cos(-data->rot_speed);
}
