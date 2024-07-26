/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:55:56 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/26 18:26:40 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	parse(t_data *data)
{
	get_elements(data);
	get_map(data);
    // printf("no : %s\n",data->map_info->texture->no);
    // printf("so : %s\n",data->map_info->texture->so);
    // printf("we : %s\n",data->map_info->texture->we);
    // printf("ea : %s\n",data->map_info->texture->ea);
    // printf("f : %d\n",data->map_info->rgb->f);
    // printf("c : %d\n",data->map_info->rgb->c);
	// for(int i=0;data->map_info->map[i]!=0;i++)
	// 	printf("%s\n",data->map_info->map[i]);
	close(data->map_info->fd);
}
