/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:04:55 by jeshin            #+#    #+#             */
/*   Updated: 2024/08/08 17:05:13 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	get_start_line(char **line, int fd)
{
	int		i;
	char	**tab;

	*line = get_next_line(fd);
	if (*line == 0)
		err("Error: map\n");
	tab = ft_split(*line, ' ');
	i = -1;
	if (tab[0] == 0)
		err("Error: map\n");
	if (!ft_strncmp(tab[0], "\n", 2))
	{
		free_tab(tab);
		free(*line);
		get_start_line(line, fd);
		return ;
	}
	free_tab(tab);
}

static void	check_lineflip_in_map(char *line)
{
	int	flg;
	int	i;

	flg = 0;
	i = -1;
	while (line[++i])
	{
		if (!flg && line[i] == '\n' && (line[i + 1] && line[i + 1] == '\n'))
			flg = 1;
		if (flg && (line[i] != '\n' && line[i] != ' '))
			err("Error: map\n");
	}
}

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
	check_lineflip_in_map(joined);
	map_info->map = ft_split(joined, '\n');
	free(joined);
}

void	get_map(t_data *data)
{
	char	*start;

	get_start_line(&start, data->map_info->fd);
	set_map(&start, data->map_info);
	check_map(data);
}
