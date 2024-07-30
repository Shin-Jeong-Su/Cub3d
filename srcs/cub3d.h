/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:40:00 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/30 18:59:04 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# define SCREENWIDTH 640
# define SCREENHEIGHT 480
# define MOVESPEED 0.04
# define ROTSPEED 0.04

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include <math.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"

enum e_tex_index
{
	NO = 0,
	SO = 1,
	WE = 2,
	EA = 3
};

enum e_key
{
	W = 13,
	S = 1,
	A = 0,
	D = 2,
	LEFT = 123,
	RIGHT = 124,
	ESC = 53
};

typedef struct s_rgb
{
	int	f;
	int	c;
}	t_rgb;

typedef struct s_texture
{
	int		**pixel;
	int		width;
	int		height;
}	t_texture;

typedef struct s_texture_info
{
	t_texture	tex_tab[4];	
	int			index;
	int			tex_x;
	int			tex_y;
	double		step;
	double		pos;
}	t_texture_info;

typedef struct s_player
{
	double	pos_y;
	double	pos_x;
	double	dir_y;
	double	dir_x;
	double	plane_y;
	double	plane_x;
	int		move_y;
	int		move_x;
	int		rotate;
}	t_player;

typedef struct s_ray
{
	int		map_y;
	int		map_x;
	double	dir_y;
	double	dir_x;
	double	camera_x;
	double	sidedist_y;
	double	sidedist_x;
	double	deltadist_y;
	double	deltadist_x;
	double	perp_wall_dist;
	int		hit;
	int		side;
	int		step_y;
	int		step_x;
	int		line_height;
	int		draw_start;
	int		draw_end;
	double	wall_x;
}	t_ray;

typedef struct s_map_info
{
	int			fd;
	int			elem;
	char		**map;
	int			width;
	int			height;
}	t_map_info;

typedef struct s_mlx_info
{
	void	*mlx;
	void	*win;
}	t_mlx_info;

typedef struct s_img_info
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_info;

typedef struct s_data
{
	t_map_info		*map_info;
	t_mlx_info		*mlx_info;
	t_player		*player;
	t_texture_info	*texture_info;
	t_rgb			*rgb;
	t_ray			*ray;
	int				**buffer;
}	t_data;

//err.c
int		err(char *s);
int		sys_err(char *s);
//init.c
void	init_map_info(t_data *data);
void	init_mlx_info(t_data *data);
int		**init_int_tab(int width, int height);
void	init_ray(t_data *data);
void	init_img_info(t_img_info *img_info, t_mlx_info *mlx_info);
//parse.c
void	parse(int ac, char **av, t_data *data);
//free.c
void	free_tab(char **tab);
//elements.c
void	get_elements(t_data *data);
//texture.c
void	check_texture(char *path, t_data *data, int where);
//rgb.c
void	check_rgb(char *path, t_data *data, int where);
//free.c
void	free_tab(char **tab);
//map.c
void	get_map(t_data *data);
void	check_map(t_data *data);
//player.c
void	save_player_info(int i, int j, t_data *data);
//display.c
void	display(t_data *data);
//raycasting.c
void	raycasting(t_data *data);
//buffer.c
void	set_img_buffer(int x, t_data *data);
//rendering.c
int		rendering(t_data *data);
//hook.c
int		exit_cub(t_data *data);
int		key_press(int key, t_data *data);
int		key_release(int key, t_data *data);
//move.c
int		move_forward(t_data *data);
int		move_backward(t_data *data);
int		move_left(t_data *data);
int		move_right(t_data *data);
//rotate.c
void	rotate(t_data *data, double dir);
//validate.c
void	check_validate(double *y, double *x, char **map, t_player *player);
#endif