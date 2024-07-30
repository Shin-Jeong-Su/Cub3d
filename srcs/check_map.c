/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:02:58 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/30 16:12:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	init_dydx(int *dy, int *dx)
{
	dy[0] = -1;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = 0;
	dx[0] = 0;
	dx[1] = 1;
	dx[2] = 0;
	dx[3] = -1;
}

static void	check_here(int i, int j, char **map)
{
	if (i == 0 || j == 0 || map[i + 1] == 0)
		err("Error: map: not surrounded by wall\n");
	while (map[i][++j])
	{
		if (map[i][j] != ' ')
			break ;
	}
	if (map[i][j] == 0)
		err("Error: map: not surrounded by wall\n");
}

static void	check_surrounded_by_wall(int i, int j, char **map)
{
	int	k;
	int	ny;
	int	nx;
	int	dy[4];
	int	dx[4];

	check_here(i, j, map);
	k = -1;
	init_dydx(dy, dx);
	while (++k < 4)
	{
		ny = i + dy[k];
		nx = j + dx[k];
		// if (ny < 0 || nx < 0 || map[ny] == 0 || \
		// ft_strlen(map[ny]) < (size_t)nx)
		// 	continue ;
		if (map[ny][nx] == ' ')
			err("Error: map: not surrounded by wall\n");
	}
}

static void	try_case(int i, int j, t_data *data)
{
	char	**map;

	map = data->map_info->map;
	if (map[i][j] == ' ' || map[i][j] == '1')
		return ;
	else if (map[i][j] == 'N' || map[i][j] == 'S' || \
	map[i][j] == 'W' || map[i][j] == 'E')
	{
		check_surrounded_by_wall(i, j, map);
		save_player_info(i, j, data);
	}
	else if (map[i][j] == '0')
		check_surrounded_by_wall(i, j, data->map_info->map);
	else
		err("Error: map\n");
}

void	check_map(t_data *data)
{
	int		i;
	int		j;

	i = -1;
	while ((data->map_info->map)[++i])
	{
		j = -1;
		while ((data->map_info->map)[i][++j])
			try_case(i, j, data);
		if (data->map_info->width < j)
			data->map_info->width = j;
	}
	data->map_info->height = i;
	if (!data->player->pos_y && !data->player->pos_x)
		err("Error: map: player\n");
}
