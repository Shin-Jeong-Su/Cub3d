/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:35:31 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/28 19:06:30 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	key_press(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_image(data->mlx_info->mlx, data->img_info->img);
		mlx_destroy_window(data->mlx_info->mlx, data->mlx_info->win);
		exit(EXIT_SUCCESS);
	}
	if (key == LEFT)
		data->player->rotate -= 1;
	if (key == RIGHT)
		data->player->rotate += 1;
	if (key == W)
		data->player->move_y = 1;
	if (key == S)
		data->player->move_y = -1;
	if (key == A)
		data->player->move_x = -1;
	if (key == D)
		data->player->move_x = 1;
	return (0);
}

static int	key_release(int key, t_data *data)
{
	if (key == ESC)
	{
		mlx_destroy_image(data->mlx_info->mlx, data->img_info->img);
		mlx_destroy_window(data->mlx_info->mlx, data->mlx_info->win);
		exit(EXIT_SUCCESS);
	}
	if (key == W && data->player->move_y == 1)
		data->player->move_y = 0;
	if (key == S && data->player->move_y == -1)
		data->player->move_y = 0;
	if (key == A && data->player->move_x == -1)
		data->player->move_x = 0;
	if (key == D && data->player->move_x == 1)
		data->player->move_x = 0;
	if (key == LEFT && data->player->rotate <= 1)
		data->player->rotate = 0;
	if (key == RIGHT && data->player->rotate >= -1)
		data->player->rotate = 0;
	return (0);
}

void	display(t_data *data)
{
	data->buffer = init_int_tab(SCREENWIDTH, SCREENHEIGHT);
	init_img_info(data);
	init_ray(data);
	mlx_hook(data->mlx_info->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_info->win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx_info->mlx, rendering, data);
	mlx_loop(data->mlx_info->mlx);
}
