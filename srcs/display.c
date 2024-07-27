/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 12:35:31 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/27 18:14:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	display(t_data *data)
{
	rendering(data);
	// mlx_loop_hook(data->mlx_info->mlx, rendering, data);
	// mlx_loop(data->mlx_info->mlx);
}