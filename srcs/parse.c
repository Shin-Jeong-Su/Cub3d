/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:55:56 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/25 20:35:01 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	get_start_line(char **line, int fd)
{
	int		i;
	char	**tab;

	*line = get_next_line(fd);
	if (*line == 0)
		err("Error: map");
	tab = ft_split(*line, ' ');
	i = -1;
	if (tab[0] == 0)
		err("Error: map");
	if (!ft_strncmp(tab[0], "\n", 2))
	{
		free_tab(tab);
		free(*line);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	parse(t_data *data)
{
    get_elements(data->map_info);
	get_map(data->map_info);
	check_map(data->map_info);
    printf("no : %s\n",data->map_info->texture->no);
    printf("so : %s\n",data->map_info->texture->so);
    printf("we : %s\n",data->map_info->texture->we);
    printf("ea : %s\n",data->map_info->texture->ea);
    printf("f : %d\n",data->map_info->rgb->f);
    printf("c : %d\n",data->map_info->rgb->c);
	for(int i=0;data->map_info->map[i]!=0;i++)
		printf("%s\n",data->map_info->map[i]);
	close(data->map_info->fd);
}
