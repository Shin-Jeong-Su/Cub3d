/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:04:15 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/28 18:03:23 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_dir(t_player *player, int where)
{
	if (where == NO)
	{
		player->dir_y = 1;
		player->dir_x = 0;
	}
	else if (where == SO)
	{
		player->dir_y = -1;
		player->dir_x = 0;
	}
	else if (where == WE)
	{
		player->dir_y = 0;
		player->dir_x = -1;
	}
	else if (where == EA)
	{
		player->dir_y = 0;
		player->dir_x = 1;
	}
}

void	set_plane(t_player *player, int where)
{
	if (where == NO)
	{
		player->plane_y = 0;
		player->plane_x = 0.66;
	}
	else if (where == SO)
	{
		player->plane_y = 0;
		player->plane_x = -0.66;
	}
	else if (where == WE)
	{
		player->plane_y = 0.66;
		player->plane_x = 0;
	}
	else if (where == EA)
	{
		player->plane_y = -0.66;
		player->plane_x = 0;
	}
}

void	save_player_info(int i, int j, t_data *data)
{
	if (data->player->pos_y && data->player->pos_x)
		err("Error: map: player\n");
	data->player->pos_y = i;
	data->player->pos_x = j;
	if ((data->map_info->map)[i][j] == 'N')
	{
		set_dir(data->player, NO);
		set_plane(data->player, NO);
	}
	if ((data->map_info->map)[i][j] == 'S')
	{
		set_dir(data->player, SO);
		set_plane(data->player, SO);
	}
	if ((data->map_info->map)[i][j] == 'W')
	{
		set_dir(data->player, WE);
		set_plane(data->player, WE);
	}
	if ((data->map_info->map)[i][j] == 'E')
	{
		set_dir(data->player, EA);
		set_plane(data->player, EA);
	}
}
