/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:04:15 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/26 18:34:19 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	save_player_info(int i, int j, t_data *data)
{
	if (data->player->pos_y && data->player->pos_x)
		err("Error: map: player\n");
	data->player->pos_y = i;
	data->player->pos_x = j;
	if ((data->map_info->map)[i][j] == 'N')
	{
		data->player->dir_y = 1;
		data->player->dir_x = 0;
		data->player->plane_y = 0;
		data->player->plane_x = 0.66;
	}
	if ((data->map_info->map)[i][j] == 'S')
	{
		data->player->dir_y = -1;
		data->player->dir_x = 0;
		data->player->plane_y = 0;
		data->player->plane_x = -0.66;
	}
	if ((data->map_info->map)[i][j] == 'W')
	{
		data->player->dir_y = 0;
		data->player->dir_x = -1;
		data->player->plane_y = 0.66;
		data->player->plane_x = 0;
	}
	if ((data->map_info->map)[i][j] == 'E')
	{
		data->player->dir_y = 0;
		data->player->dir_x = 1;
		data->player->plane_y = -0.66;
		data->player->plane_x = 0;
	}
}
