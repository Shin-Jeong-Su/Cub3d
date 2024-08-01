/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:03:41 by jeshin            #+#    #+#             */
/*   Updated: 2024/08/01 19:10:13 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_validate(double *n_y, double *n_x, char **map, t_player *player)
{
	double	x;
	double	y;
	double	cx;
	double	cy;

	x = player->pos_x;
	y = player->pos_y;
	if (map[(int)(*n_y)][(int)(*n_x)] == '1')
	{
		if (map[(int)(*n_y)][(int)x] == '1')
			*n_y = player->pos_y;
		if (map[(int)y][(int)(*n_x)] == '1')
			*n_x = player->pos_x;
	}
	else if (map[(int)(*n_y)][(int)(*n_x)] == ' ')
	{
		*n_y = player->pos_y;
		*n_x = player->pos_x;
	}
	else if (!map[(int)(*n_y)][(int)(*n_x)])
	{
		*n_y = player->pos_y;
		*n_x = player->pos_x;
	}
}
