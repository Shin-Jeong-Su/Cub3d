/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:03:41 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/30 11:17:15 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_validate(double y, double x, t_map_info *map_info)
{
	char		**map;
	int			ny;
	int			nx;

	map = map_info->map;
	ny = (int)round(y);
	nx = (int)round(x);
	if (ny <= 0 || nx <= 0)
		return (EXIT_FAILURE);
	if (nx -1 <= 0)
		return (EXIT_FAILURE);
	if (map[ny][nx] == '1')
	{
		return (EXIT_FAILURE);
	}
	// if (map[ny][nx] == '1' && (fabs(y - ny) < 0.2 || fabs(x - nx) < 0.2))
	// {
	// 	return (EXIT_FAILURE);
	// }
	return (EXIT_SUCCESS);
}
