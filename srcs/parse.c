/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:55:56 by jeshin            #+#    #+#             */
/*   Updated: 2024/08/05 11:57:47 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_file_name(char *file)
{
	char	*dot;

	dot = ft_strrchr(file, '.');
	if (dot == 0)
		err("Error: argument\n");
	if (ft_strncmp(dot, ".cub", 5) != EXIT_SUCCESS)
		err("Error: argument\n");
}

static void	open_file(char *file, t_data *data)
{
	data->map_info->fd = open(file, O_RDONLY);
	if (data->map_info->fd < 0)
		sys_err("Error: open: ");
}

void	parse(int ac, char **av, t_data *data)
{
	if (ac != 2)
		err("Error: argument\n");
	check_file_name(av[1]);
	init_map_info(data);
	init_mlx_info(data);
	open_file(av[1], data);
	get_elements(data);
	get_map(data);
	close(data->map_info->fd);
}
