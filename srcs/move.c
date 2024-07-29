/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:08:40 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/29 18:04:00 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_validate(double y, double x, t_player *player, t_map_info *map_info)
{
	char		**map;
	int			ny;
	int			nx;

	map = map_info->map;
	if (y < 0 || x < 0 || y >= map_info->height || x >= map_info->width)
		return (EXIT_FAILURE);
	ny = (int)round(y);
	nx = (int)round(x);
	if (map[ny][nx] == '1' && (fabs(y - ny) < 1 || fabs(x - nx) < 1))
		return (EXIT_FAILURE);
	if ((map[ny] && ft_strlen(map[ny]) > (size_t)nx))
		return (EXIT_FAILURE);
	t_player *p = player;
	if (p->dir_x)
		;
	return (EXIT_SUCCESS);
}

int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x + data->player->dir_x * MOVESPEED;
	new_y = data->player->pos_y + data->player->dir_y * MOVESPEED;
	if (!check_validate(new_y, new_x, data->player, data->map_info))
		return (EXIT_FAILURE);
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
	return (EXIT_SUCCESS);
}

int	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x - data->player->dir_x * MOVESPEED;
	new_y = data->player->pos_y - data->player->dir_y * MOVESPEED;
	if (!check_validate(new_y, new_x, data->player, data->map_info))
		return (EXIT_FAILURE);
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
	return (EXIT_SUCCESS);
}

int	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x - data->player->dir_y * MOVESPEED;
	new_y = data->player->pos_y + data->player->dir_x * MOVESPEED;
	if (!check_validate(new_y, new_x, data->player, data->map_info))
		return (EXIT_FAILURE);
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
	return (EXIT_SUCCESS);
}

int	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x + data->player->dir_y * MOVESPEED;
	new_y = data->player->pos_y - data->player->dir_x * MOVESPEED;
	if (!check_validate(new_y, new_x, data->player, data->map_info))
		return (EXIT_FAILURE);
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
	return (EXIT_SUCCESS);
}
