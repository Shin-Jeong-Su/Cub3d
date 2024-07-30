/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:08:40 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/30 16:42:02 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	move_forward(t_data *data)
{
	double	new_x;
	double	new_y;
	new_x = data->player->pos_x + data->player->dir_x * MOVESPEED;
	new_y = data->player->pos_y + data->player->dir_y * MOVESPEED;
	if (check_validate(new_y, new_x, data->map_info))
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
	if (check_validate(new_y, new_x, data->map_info))
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
	if (check_validate(new_y, new_x, data->map_info))
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
	if (check_validate(new_y, new_x, data->map_info))
		return (EXIT_FAILURE);
	data->player->pos_x = new_x;
	data->player->pos_y = new_y;
	return (EXIT_SUCCESS);
}
