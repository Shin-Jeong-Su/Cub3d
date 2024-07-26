/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:13:06 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/26 18:29:01 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_path_extension(char *path)
{
	char	*extension_ptr;

	extension_ptr = ft_strrchr(path, '.');
	if (extension_ptr == 0)
		err("Error: elements\n");
	if (!ft_strncmp(extension_ptr, ".xpm", 5) || \
	!ft_strncmp(extension_ptr, ".png", 5))
		;
	else
		err("Error: elements: texture path\n");
}

void	check_texture(char *path, t_data *data, int where)
{
	check_path_extension(path);
	if (where == 0 && !(data->map_info->elem & (1 << 0)))
	{
		data->map_info->elem |= (1 << 0);
		data->texture->no = ft_strdup(path);
	}
	else if (where == 1 && !(data->map_info->elem & (1 << 1)))
	{
		data->map_info->elem |= (1 << 1);
		data->texture->so = ft_strdup(path);
	}
	else if (where == 2 && !(data->map_info->elem & (1 << 2)))
	{
		data->map_info->elem |= (1 << 2);
		data->texture->we = ft_strdup(path);
	}
	else if (where == 3 && !(data->map_info->elem & (1 << 3)))
	{
		data->map_info->elem |= (1 << 3);
		data->texture->ea = ft_strdup(path);
	}
	else
		err("Error: elements\n");
}
