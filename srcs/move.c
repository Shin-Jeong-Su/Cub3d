/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:08:40 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/28 19:25:23 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
static bool	is_valid_pos_wall_collision(t_data *data, double x, double y)
{
	if (data->map[(int)y][(int)x] == '0')
		return (true);
	return (false);
}

static bool	is_valid_pos_in_map(t_data *data, double x, double y)
{
	if (x < 0.25 || x >= data->mapinfo.width - 1.25)
		return (false);
	if (y < 0.25 || y >= data->mapinfo.height -0.25)
		return (false);
	return (true);
}

static bool	is_valid_pos(t_data *data, double x, double y)
{
	if (!BONUS && is_valid_pos_in_map(data, x, y))
		return (true);
	if (BONUS && is_valid_pos_wall_collision(data, x, y))
		return (true);
	return (false);
}

int	validate_move(t_data *data, double new_x, double new_y)
{
	int	moved;

	moved = 0;
	if (is_valid_pos(data, new_x, data->player.pos_y))
	{
		data->player.pos_x = new_x;
		moved = 1;
	}
	if (is_valid_pos(data, data->player.pos_x, new_y))
	{
		data->player.pos_y = new_y;
		moved = 1;
	}
	return (moved);
}

static int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x + data->player->dir_x * MOVESPEED;
	new_y = data->player->pos_y + data->player->dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_backward(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x - data->player->dir_x * MOVESPEED;
	new_y = data->player->pos_y - data->player->dir_y * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_left(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x + data->player->dir_y * MOVESPEED;
	new_y = data->player->pos_y - data->player->dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}

static int	move_right(t_data *data)
{
	double	new_x;
	double	new_y;

	new_x = data->player->pos_x - data->player->dir_y * MOVESPEED;
	new_y = data->player->pos_y + data->player->dir_x * MOVESPEED;
	return (validate_move(data, new_x, new_y));
}


int	move_player(t_data *data)
{
	int	moved;

	moved = 0;
	if (data->player->move_y == 1)
		moved += move_forward(data);
	if (data->player->move_y == -1)
		moved += move_backward(data);
	if (data->player->move_x == -1)
		moved += move_left(data);
	if (data->player->move_x == 1)
		moved += move_right(data);
	if (data->player->rotate != 0)
		moved += rotate_player(data, data->player->rotate);
	return (moved);
}