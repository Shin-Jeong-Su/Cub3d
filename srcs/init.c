/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:03:20 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/29 17:45:41 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_map_info(t_data *data)
{
	data->map_info = (t_map_info *)malloc(sizeof(t_map_info));
	if (data->map_info == 0)
		sys_err("Error: malloc: ");
	ft_bzero(data->map_info, sizeof(t_map_info));
	data->player = (t_player *)malloc(sizeof(t_player));
	if (data->player == 0)
		sys_err("Error: malloc: ");
	ft_bzero(data->player, sizeof(t_player));
	data->texture_info = (t_texture_info *)malloc(sizeof(t_texture_info));
	if (data->texture_info == 0)
		sys_err("Error: malloc: ");
	ft_bzero(data->texture_info, sizeof(t_texture_info));
	data->rgb = (t_rgb *)malloc(sizeof(t_rgb));
	if (data->rgb == 0)
		sys_err("Error: malloc: ");
	ft_bzero(data->rgb, sizeof(t_rgb));
}

void	init_mlx_info(t_data *data)
{
	data->mlx_info = (t_mlx_info *)malloc(sizeof(t_mlx_info));
	if (data->mlx_info == 0)
		sys_err("Error: malloc: ");
	data->mlx_info->mlx = mlx_init();
	data->mlx_info->win = mlx_new_window(data->mlx_info->mlx, \
										SCREENWIDTH, \
										SCREENHEIGHT, \
										"cub3D");
}

void	init_img_info(t_img_info *img_info, t_mlx_info *mlx_info)
{
	img_info->img = mlx_new_image(mlx_info->mlx, \
										SCREENWIDTH, \
										SCREENHEIGHT);
	if (img_info->img == 0)
		sys_err("Error: mlx new image: ");
	img_info->addr = mlx_get_data_addr(img_info->img, \
											&(img_info->bits_per_pixel), \
											&(img_info->line_length), \
											&(img_info->endian));
}

int	**init_int_tab(int width, int height)
{
	int	**tab;
	int	i;

	tab = (int **)malloc(sizeof (int *) * height);
	if (tab == 0)
		sys_err("Error: malloc: ");
	i = -1;
	while (++i < height)
	{
		tab[i] = malloc(sizeof(int) * width);
		if (tab[i] == 0)
			sys_err("Error: malloc: ");
		ft_bzero(tab[i], sizeof(int) * width);
	}
	return (tab);
}

void	init_ray(t_data *data)
{
	data->ray = (t_ray *)malloc(sizeof(t_ray));
	if (data->ray == 0)
		sys_err("Error: malloc: ");
	ft_bzero(data->ray, sizeof(t_ray));
}
