/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:13:06 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/28 17:43:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	check_path_extension(char *path)
{
	char	*extension_ptr;

	extension_ptr = ft_strrchr(path, '.');
	if (extension_ptr == 0)
		err("Error: elements\n");
	if (!ft_strncmp(extension_ptr, ".xpm", 5))
		return ;
	else
		err("Error: elements: texture path\n");
}

void	convert_to_img(t_img_info *img, char *path, void *mlx, t_texture *tex)
{
	img->img = mlx_xpm_file_to_image(mlx, path, &(tex->width), &(tex->height));
	if (img->img == 0)
		sys_err("Error: mlx xpm file to image: ");
	img->addr = mlx_get_data_addr(img->img, \
									&(img->bits_per_pixel), \
									&(img->line_length), \
									&(img->endian));
}

void	get_texture_image(char *path, t_data *data, int where)
{
	int			y;
	int			x;
	t_img_info	img_info;
	t_texture	*texture;

	check_path_extension(path);
	texture = &(data->texture_info->tex_tab[where]);
	convert_to_img(&img_info, path, data->mlx_info->mlx, texture);
	texture->pixel = init_int_tab(texture->width, texture->height);
	y = -1;
	while (++y < texture->height)
	{
		x = -1;
		while (++x < texture->width)
			(texture->pixel)[y][x] = *(unsigned int *)(img_info.addr \
									+ (y * img_info.line_length) \
									+ (x * img_info.bits_per_pixel / 8));
	}
}

void	check_texture(char *path, t_data *data, int where)
{
	if (where == NO && !(data->map_info->elem & (1 << 0)))
	{
		data->map_info->elem |= (1 << 0);
		get_texture_image(path, data, where);
	}
	else if (where == SO && !(data->map_info->elem & (1 << 1)))
	{
		data->map_info->elem |= (1 << 1);
		get_texture_image(path, data, where);
	}
	else if (where == WE && !(data->map_info->elem & (1 << 2)))
	{
		data->map_info->elem |= (1 << 2);
		get_texture_image(path, data, where);
	}
	else if (where == EA && !(data->map_info->elem & (1 << 3)))
	{
		data->map_info->elem |= (1 << 3);
		get_texture_image(path, data, where);
	}
	else
		err("Error: elements\n");
}
