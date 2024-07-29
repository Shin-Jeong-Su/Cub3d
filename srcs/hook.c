/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 12:44:59 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/29 18:02:58 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	exit_cub(t_data *data)
{
	mlx_destroy_window(data->mlx_info->mlx, data->mlx_info->win);
	exit(EXIT_SUCCESS);
}

int	key_press(int key, t_data *data)
{
	if (key == ESC)
		exit_cub(data);
	if (key == LEFT)
		data->player->rotate = 1;
	if (key == RIGHT)
		data->player->rotate = -1;
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

int	key_release(int key, t_data *data)
{
	if (key == ESC)
		exit_cub(data);
	if (key == LEFT && data->player->rotate <= 1)
		data->player->rotate = 0;
	if (key == RIGHT && data->player->rotate >= -1)
		data->player->rotate = 0;
	if (key == W && data->player->move_y == 1)
		data->player->move_y = 0;
	if (key == S && data->player->move_y == -1)
		data->player->move_y = 0;
	if (key == A && data->player->move_x == -1)
		data->player->move_x = 0;
	if (key == D && data->player->move_x == 1)
		data->player->move_x = 0;
	return (0);
}
