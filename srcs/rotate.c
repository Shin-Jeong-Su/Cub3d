/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 19:20:29 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/29 17:00:36 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	rotate(t_data *data, double dir)
{
	t_player	*player;
	double		rot_dir;
	double		tmp_x;

	player = data->player;
	rot_dir = ROTSPEED * dir;
	tmp_x = player->dir_x;
	player->dir_x = player->dir_x * cos(rot_dir) - player->dir_y * sin(rot_dir);
	player->dir_y = tmp_x * sin(rot_dir) + player->dir_y * cos(rot_dir);
	tmp_x = player->plane_x;
	player->plane_x = player->plane_x * cos(rot_dir) \
					- player->plane_y * sin(rot_dir);
	player->plane_y = tmp_x * sin(rot_dir) + player->plane_y * cos(rot_dir);
}
