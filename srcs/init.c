/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:03:20 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/26 18:26:21 by jeshin           ###   ########.fr       */
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
		sys_err();
}

void	init_map_info(t_data *data)
{
	data->map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (data->map_info == 0)
		sys_err();
	data->map_info->elem = 0;
	data->player = (t_player *)malloc(sizeof(t_player));
	data->player->pos_y = 0;
	data->player->pos_x = 0;
	data->texture = (t_texture *)malloc(sizeof(t_texture));
	data->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	data->rgb->f = 0;
	data->rgb->c = 0;
}

void	init(int ac, char **av, t_data *data)
{
	if (ac != 2)
		err("Error: argument\n");
	check_file_name(av[1]);
	init_map_info(data);
	open_file(av[1], data);
}
