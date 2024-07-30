/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/30 11:03:41 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/30 16:10:00 by jeshin           ###   ########.fr       */
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

int	check_validate(double y, double x, t_map_info *map_info)
{
	int	k;
	int	ny;
	int	nx;
	int	dy[4];
	int	dx[4];

	k = -1;
	init_dydx(dy, dx);
	while (++k < 4)
	{
		ny = (int)y + dy[k];
		nx = (int)x + dx[k];
		if (ny < 0 || nx < 0 || (map_info->map)[ny] == 0 || \
		ft_strlen((map_info->map)[ny]) < (size_t)nx)
			continue ;
		if ((map_info->map)[ny][nx] == '1')
		{
			if (k == 0 && (y - (ny + 1) <= 0.05))
				return (EXIT_FAILURE);
			else if (k == 1 && (nx - x <= 0.05))
				return (EXIT_FAILURE);
			else if (k == 2 && (ny - y <= 0.05))
				return (EXIT_FAILURE);
			else if (k == 3 && (x - (nx + 1) <= 0.05))
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
