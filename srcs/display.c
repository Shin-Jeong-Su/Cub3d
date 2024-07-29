/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:35:31 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/29 17:42:09 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display(t_data *data)
{
	data->buffer = init_int_tab(SCREENWIDTH, SCREENHEIGHT);
	init_ray(data);
	mlx_hook(data->mlx_info->win, 17, 0L, exit_cub, data);
	mlx_hook(data->mlx_info->win, 2, 1L << 0, key_press, data);
	mlx_hook(data->mlx_info->win, 3, 1L << 1, key_release, data);
	mlx_loop_hook(data->mlx_info->mlx, rendering, data);
	mlx_loop(data->mlx_info->mlx);
}
