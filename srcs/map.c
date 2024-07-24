/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 20:34:45 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/25 21:57:34 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_map(char **start, t_map_info *map_info)
{
	char	*joined;
	char	*line;
	char	*tmp;

	line = *start;
	while (1)
	{
		tmp = get_next_line(map_info->fd);
		if (tmp == 0)
			break ;
		joined = ft_strjoin(line, tmp);
		free(line);
		free(tmp);
		line = joined;
	}
	map_info->map = ft_split(joined, '\n');
}

static void	init_dydx(int *dy,int *dx)
{
	dy[0] = -1;
	dy[1] = -1;
	dy[2] = 0;
	dy[3] = 1;
	dy[4] = 1;
	dy[5] = 1;
	dy[6] = 0;
	dy[7] = -1;
	dx[0] = 0;
	dx[1] = 1;
	dx[2] = 1;
	dx[3] = 1;
	dx[4] = 0;
	dx[5] = -1;
	dx[6] = -1;
	dx[7] = -1;
}

static void	init_visited(int ***visited, int width, int height)
{
	int	**tab;
	int	i;
	int	j;

	tab = (int **)malloc(sizeof(int *) * height);
	if (tab == 0)
		sys_err();
	i = -1;
	while (i < height)
	{
		tab[i] = (int *)malloc(sizeof(int) * width);
		if (tab[i] == 0)
			sys_err();
		j = -1;
		while (++j < width)
			tab[i][j] = 0;
	}
	*visited = tab;
}

void	go(int i, int j, char ***map, int ***visited)
{
	int		dy[8];
	int		dx[8];
	int		ny;
	int		nx;
	int		k;

	if ((*map)[i][j] != '1')
		return ;
	if ((*visited)[i][j] == 1)
		return ;
	k = -1;
	while (++k < 8)
	{
		ny = i + dy[k];
		nx = j + dx[k];
		if (ny < 0 || nx < 0 || ny >= map_info->height || nx >= map_info->width)
			continue ;
		if (map[ny][nx] == 1)
	}

}

static void	check_surrounded_by_wall(t_map_info *map_info)
{
	char	**map;
	int		**visited;
	int	i;
	int	j;

	map = map_info->map;
	init_visited(&visited, map_info->width, map_info->height);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[++j])
			go(i, j, &map, &visited);
	}
}

void	save_player_info(int i, int j, t_map_info *map_info)
{
	if (map_info->player->pos_y)
		err("Error: map: player");
	map_info->player->pos_y = i;
	map_info->player->pos_x = j;
	if ((map_info->map)[i][j] == 'N')
	{
		map_info->player->dir_y = 1;
		map_info->player->dir_x = 0;
	}
	if ((map_info->map)[i][j] == 'S')
	{
		map_info->player->dir_y = -1;
		map_info->player->dir_x = 0;
	}
	if ((map_info->map)[i][j] == 'W')
	{
		map_info->player->dir_y = 0;
		map_info->player->dir_x = -1;
	}
	if ((map_info->map)[i][j] == 'E')
	{
		map_info->player->dir_y = 0;
		map_info->player->dir_x = 1;
	}
}

static void	check_map(t_map_info *map_info)
{
	char	**map;
	int		i;
	int		j;
	// int		**visited;

	map = map_info->map;
	// init_visited(&visited, map_info->width, map_info->height);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[++j])
		{
			if (map[i][j] == ' ' || map[i][j] == '1')
				continue ;
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				check_surrounded_by_wall();
				save_player_info(i, j, map_info);
			}
			else if (map[i][j] == '0')
				check_surrounded_by_wall();
			else
				err("Error: map\n");
		}
		if (map_info->width < j)
			map_info->width = j;
	}
	map_info->height = i;
}

void	get_map(t_map_info *map_info)
{
	char	*start;

	if (get_start_line(&start, map_info->fd))
	{
		get_map(map_info);
		return ;
	}
	set_map(&start, map_info);
	check_map(map_info);
}
