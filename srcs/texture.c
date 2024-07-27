/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 14:13:06 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/27 16:47:28 by jeshin           ###   ########.fr       */
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

void	get_texture_image(char *path, t_data *data, int where)
{
	int			y;
	int			x;
	int			i;
	t_img_info	img;
	t_texture	*tex;

	check_path_extension(path);
	tex = &(data->texture_info->tex_tab[where]);
	img.img = mlx_xpm_file_to_image(data->mlx_info->mlx, path, &(tex->width), &(tex->height));
	if (img.img == 0)
		sys_err("Error: mlx xpm file to image: ");
	img.addr = mlx_get_data_addr(img.img, &(img.bits_per_pixel), &(img.line_length), &(img.endian));
	y = -1;
	tex->texture = (int **)malloc(sizeof (int *) * tex->height);
	if (tex->texture == 0)
		sys_err("Error: malloc: ");
	i = -1;
	while (++i < tex->width)
	{
		(tex->texture)[i] = malloc(sizeof(int) * tex->width);
		if (tex->texture[i] == 0)
			sys_err("Error: malloc: ");
	}
	while (++y < tex->height)
	{
		x = -1;
		while (++x < tex->width)
			(tex->texture)[y][x] = img.addr[y * (img.line_length / 4) + x];
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

