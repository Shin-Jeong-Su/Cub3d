/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:19:44 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/26 18:38:03 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
static void	init_ray2(t_ray *ray, t_player *player)
{
	if (ray->dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (player->pos_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
        ray->step_x = 1;
        ray->side_dist_x = (ray->map_x + 1.0 - player->pos_x) * ray->delta_dist_x;
	}
	if (ray->dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (player->pos_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
        ray->step_y = 1;
        ray->side_dist_y = (ray->map_y + 1.0 - player->pos_y) * ray->delta_dist_y;
	}
}

static void	init_ray(int x, t_ray *ray, t_player *player)
{
	ray->camera_x = 2 * x / SCREENWIDTH - 1;
	ray->dir_y = player->dir_y + player->plane_y * ray->camera_x;
	ray->dir_x = player->dir_x + player->plane_x * ray->camera_x;
	ray->map_y = (int)player->pos_y;
	ray->map_x = (int)player->pos_x;
	ray->delta_dist_y = sqrt(1 + (ray->dir_x * ray->dir_x) / ray->dir_y * ray->dir_y);
	ray->delta_dist_x = sqrt(1 + (ray->dir_y * ray->dir_y) / ray->dir_x * ray->dir_x);
	ray->hit = 0;
}

static void	check_hit(t_ray *ray, char **map)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			ray->side = 0;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			ray->side = 1;
		}
		if (map[ray->map_x][ray->map_y] > 0)
			ray->hit = 1;
	}
}

static void	set_dist(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->dir_x;
	else
		ray->perp_wall_dist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->dir_y;
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

	data->ray = (t_ray *)malloc(sizeof(t_ray));
	if (data->ray == 0)
		sys_err();
	x = -1;
	while (++x < SCREENWIDTH)
	{
		init_ray(x, data->ray, data->player);
		init_ray2(data->ray, data->player);
		check_hit(data->ray, data->map_info->map);
		set_dist(data->ray, data->player);
	}
}