/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:35:31 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/26 18:45:49 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void	draw(t_data *data)
// {
// 	data->texture->tex_num = data->map_info->map
// }

void	rendering(t_data *data)
{
	data->img_info->img = mlx_new_image(data->mlx_info->mlx, SCREENWIDTH, SCREENHEIGHT);
	data->img_info->addr = mlx_get_data_addr(data->img_info->img, &(data->img_info->bits_per_pixel), &(data->img_info->line_length), &(data->img_info->endian));
	raycasting(data);
	// draw(data);
	mlx_put_image_to_window(data->mlx_info->mlx, data->mlx_info->win, data->img_info->img ,0, 0);
}

void	display(t_data *data)
{
	data->mlx_info->mlx = mlx_init();
	data->mlx_info->win = mlx_new_window(data->mlx_info->mlx, SCREENWIDTH, SCREENHEIGHT, "cub3D");
	rendering(data);
	mlx_loop_hook(data->mlx_info->mlx, rendering, data);
	mlx_loop(data->mlx_info->mlx);
}