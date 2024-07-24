/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:40:00 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/25 21:19:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <sys/time.h>
# include "../libft/libft.h"

typedef struct s_rgb
{
	int	f;
	int	c;
}	t_rgb;

typedef struct s_texture
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
}	t_texture;

typedef struct s_player
{
	double	pos_y;
	double	pos_x;
	int		dir_y;
	int		dir_x;
}	t_player;

typedef struct s_map_info
{
	int			fd;
	int			elem;
	char		**map;
	int			width;
	int			height;
	t_player	*player;
	t_texture	*texture;
	t_rgb		*rgb;
}	t_map_info;

typedef struct s_ray
{
	int		dir_y;
	int		dir_x;
}	t_ray;

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
	t_map_info	*map_info;
	t_mlx_info	*mlx_info;
	t_img_info	*img_info;
}	t_data;

//err.c
int		err(char *s);
int		sys_err(void);
//init.c
void	init(int ac, char **av, t_data *data);
//parse.c
void	parse(t_data *data);
//free.c
void	free_tab(char **tab);
//elements.c
void	get_elements(t_map_info *map_info);
//texture.c
void	check_texture(char *path, t_map_info *map_info, int where);
//rgb.c
void	check_rgb(char *path, t_map_info *map_info, int where);
//free.c
void	free_tab(char **tab);
//map.c
void	get_map(t_map_info *map_info)
#endif