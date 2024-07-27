/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:03:20 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/27 17:16:17 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file_name(char *file)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (ft_strncmp(dot, ".cub", 5) != EXIT_SUCCESS)
		err("Error: argument\n");
}

void	open_file(char *file, t_data *data)
{
	data->map_info->fd = open(file, O_RDONLY);
	if (data->map_info->fd < 0)
		sys_err("Error: open: ");
}

void	init_map_info(t_data *data)
{
	data->map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (data->map_info == 0)
		sys_err("Error: malloc: ");
	data->map_info->elem = 0;
	data->player = (t_player *)malloc(sizeof(t_player));
	if (data->player == 0)
		sys_err("Error: malloc: ");
	data->player->pos_y = 0;
	data->player->pos_x = 0;
	data->texture_info = (t_texture_info *)malloc(sizeof(t_texture_info));
	if (data->texture_info == 0)
		sys_err("Error: malloc: ");
	data->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (data->rgb == 0)
		sys_err("Error: malloc: ");
	data->rgb->f = 0;
	data->rgb->c = 0;
}

void	init_mlx_info(t_data *data)
{
	data->mlx_info = (t_mlx_info *)malloc(sizeof(t_mlx_info));
	if (data->mlx_info == 0)
		sys_err("Error: malloc: ");
	data->mlx_info->mlx = mlx_init();
	data->mlx_info->win = mlx_new_window(data->mlx_info->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
}

void	init(int ac, char **av, t_data *data)
{
	if (ac != 2)
		err("Error: argument\n");
	check_file_name(av[1]);
	init_map_info(data);
	init_mlx_info(data);
	open_file(av[1], data);
}
