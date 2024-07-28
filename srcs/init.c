/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:03:20 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/28 17:57:56 by jeshin           ###   ########.fr       */
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

void	init_img_info(t_data *data)
{
	data->img_info = (t_img_info *)malloc(sizeof(t_img_info));
	if (data->img_info == 0)
		sys_err("Error: malloc: ");
	data->img_info->img = mlx_new_image(data->mlx_info->mlx, \
										SCREENWIDTH, \
										SCREENHEIGHT);
	if (data->img_info->img == 0)
		sys_err("Error: mlx new image: ");
	data->img_info->addr = mlx_get_data_addr(data->img_info->img, \
											&(data->img_info->bits_per_pixel), \
											&(data->img_info->line_length), \
											&(data->img_info->endian));
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
