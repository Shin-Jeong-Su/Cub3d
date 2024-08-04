/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:03:41 by jeshin            #+#    #+#             */
/*   Updated: 2024/08/04 19:44:08 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_wall_line(double *x_wl, double *y_wl, double y_d, double x_d)
{
	if (y_d < 0)
		*y_wl = -0.15;
	else if (y_d >= 0)
		*y_wl = 0.15;
	if (x_d < 0)
		*x_wl = -0.15;
	else if (x_d >= 0)
		*x_wl = 0.15;
}

static void	dont_go_further(double *n_y, double *n_x, t_player *player)
{
	*n_y = player->pos_y;
	*n_x = player->pos_x;
}

static void	x_collision(double *n_x, double x_wl, char **map, t_player *player)
{
	double	y;

	y = player->pos_y;
	if (map[(int)y][(int)((*n_x) + x_wl)] == '1')
		*n_x = player->pos_x;
}

static void	y_collision(double *n_y, double y_wl, char **map, t_player *player)
{
	double	x;

	x = player->pos_x;
	if (map[(int)((*n_y) + y_wl)][(int)x] == '1')
		*n_y = player->pos_y;
}

void	check_validate(double *n_y, double *n_x, char **map, t_player *player)
{
	double	x;
	double	y;
	double	x_wl;
	double	y_wl;

	x = player->pos_x;
	y = player->pos_y;
	get_wall_line(&x_wl, &y_wl, (*n_y) - y, (*n_x) - x);
	if (map[(int)((*n_y) + y_wl)][(int)((*n_x) + x_wl)] == ' ')
		dont_go_further(n_y, n_x, player);
	if (!map[(int)((*n_y) + y_wl)][(int)((*n_x) + x_wl)])
		dont_go_further(n_y, n_x, player);
	if (map[(int)((*n_y) + y_wl)][(int)x] == '1')
		y_collision(n_y, y_wl, map, player);
	if (map[(int)y][(int)((*n_x) + x_wl)] == '1')
		x_collision(n_x, x_wl, map, player);
}
