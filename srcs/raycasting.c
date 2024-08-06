/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:19:44 by jeshin            #+#    #+#             */
/*   Updated: 2024/08/06 19:17:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	calc_step_n_sidedist(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->sidedist_x = (player->pos_x - ray->map_x) * ray->deltadist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->sidedist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltadist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->sidedist_y = (player->pos_y - ray->map_y) * ray->deltadist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->sidedist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltadist_y;
	}
}

static void	set_ray(int x, t_ray *ray, t_player *player)
{
	ray->camera_x = 2 * x / (double)SCREENWIDTH - 1;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->map_y = (int)player->pos_y;
	ray->map_x = (int)player->pos_x;
	ray->deltadist_y = fabs(1 / ray->dir_y);
	ray->deltadist_x = fabs(1 / ray->dir_x);
	ray->hit = 0;
	calc_step_n_sidedist(ray, player);
}

static void	dda(t_ray *ray, char **map)
{
	while (ray->hit == 0)
	{
		if (ray->sidedist_x < ray->sidedist_y)
		{
			ray->sidedist_x += ray->deltadist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->sidedist_y += ray->deltadist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_y][ray->map_x] && map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

static void	calc_draw_range(t_ray *ray, double pos_x, double pos_y)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - pos_x + (1 - ray->step_x) / 2) \
								/ ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - pos_y + (1 - ray->step_y) / 2) \
								/ ray->dir_y;
	ray->line_height = (int)(SCREENHEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREENHEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREENHEIGHT / 2;
	if (ray->draw_end >= SCREENHEIGHT)
		ray->draw_end = SCREENHEIGHT - 1;
}

void	raycasting(t_data *data)
{
	int		x;

	x = -1;
	while (++x < SCREENWIDTH)
	{
		set_ray(x, data->ray, data->player);
		dda(data->ray, data->map_info->map);
		calc_draw_range(data->ray, data->player->pos_x, data->player->pos_y);
		set_img_buffer(x, data);
	}
}
