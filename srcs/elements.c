/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   elements.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 13:30:51 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/26 18:31:23 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tab(char **line, char ***tab, t_map_info *map_info)
{
	int		size;
	char	*lf_ptr;

	(*line) = get_next_line(map_info->fd);
	if (*line == 0)
		return (err("Error: elements\n"));
	lf_ptr = ft_strrchr(*line, '\n');
	if (lf_ptr == 0)
		return (err("Error: elements\n"));
	*lf_ptr = 0;
	(*tab) = ft_split(*line, ' ');
	if ((*tab)[0] != 0 && !ft_strncmp((*tab)[0], "\n", 2))
	{
		free_tab((*tab));
		free(*line);
		return (EXIT_FAILURE);
	}
	size = -1;
	while ((*tab)[++size])
		;
	if (size != 2)
		return (err("Error: elements\n"));
	return (EXIT_SUCCESS);
}

static void	check_elements(char **tab, t_data *data)
{
	if (!ft_strncmp(tab[0], "NO", 3))
		check_texture(tab[1], data, 0);
	else if (!ft_strncmp(tab[0], "SO", 3))
		check_texture(tab[1], data, 1);
	else if (!ft_strncmp(tab[0], "WE", 3))
		check_texture(tab[1], data, 2);
	else if (!ft_strncmp(tab[0], "EA", 3))
		check_texture(tab[1], data, 3);
	else if (!ft_strncmp(tab[0], "F", 2))
		check_rgb(tab[1], data, 0);
	else if (!ft_strncmp(tab[0], "C", 2))
		check_rgb(tab[1], data, 1);
	else
		err("Error: elements\n");
}

void	get_elements(t_data *data)
{
	char	*line;
	char	**tab;

	if (data->map_info->elem == 63)
		return ;
	if (get_tab(&line, &tab, data->map_info))
	{
		get_elements(data);
		return ;
	}
	check_elements(tab, data);
	free(line);
	free_tab(tab);
	get_elements(data);
}
