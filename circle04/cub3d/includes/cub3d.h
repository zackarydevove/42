#ifndef CUB3D_H

# define CUB3D_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <fcntl.h>
# include <math.h>

# include <stdio.h> // a delete

# define ESC 65307
# define A 97
# define W 119
# define D 100
# define S 115
# define RIGHT 65361
# define LEFT 65363

# define WIN_WIDTH	1920
# define WIN_HEIGHT	1080

typedef struct	s_img 
{
	void		*img;
	char		*addr;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			height;
	int			width;
}				t_img;

typedef struct	s_ray
{	
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		raydirx;
	double		raydiry;
	double		camerax;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	int			stepx;
	int			stepy;
	int			texHeight;
	int			hit;
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	int			x;
	double		wallx;
	double		step;
	double		texpos;
	int			texx;
	int			texy;
}				t_ray;

typedef struct	s_data
{
	void		*mlx;
	void		*win;
	char		**map;
	char		*path;
	int			move_w;
	int			move_a;
	int			move_d;
	int			move_s;
	int			rot_right;
	int			rot_left;
	float		rot_speed;
	float		move_speed;
	int			color_floor[3];
	int			color_roof[3];
	t_ray		ray;
	t_img		img;
	t_img		n;
	t_img		s;
	t_img		e;
	t_img		w;
}				t_data;

// main.c
void			free_all(t_data *data);
void			free_split(char **split);

// parsing.c
int				parsing(t_data *data, char *path);

// parsing_utils.c
void			init_player_pos(t_data *data, int y, int x);
int				check_textures(t_data *data);
int				get_color(char *line, int *colors);
int				get_img(t_data *data, char *line, t_img *img);
void			*realloc_map(void *ptr, size_t ptrsize, size_t newsize);

// check_walls.c
int				check_walls(char **map, int x, int y);
char			**copy_map(char **map_src);
void			handle_blank_line(char *line, int *flag, int i);
int				handle_flagged_line(char *line, int fd);

// hooks.c
int				start_game(t_data *data);
int				end_game(t_data *data);
int				handle_keypress(int keycode, t_data *data);
int				handle_keyrelease(int keycode, t_data *data);

// background.c
void			my_mlx_pixel_put(t_img *img, int x, int y, int color);
void			draw_floor_and_roof(t_data *data, int x, int y);

// raycasting.c
void			raycasting(t_data *data);

// move_player.c
void			update_player_posx_posy(t_data *data);

// rotate_player.c
void			rotate_right(t_data *data);
void			rotate_left(t_data *data);

// draw_col.c
void			draw_textures(t_data *data);

# endif