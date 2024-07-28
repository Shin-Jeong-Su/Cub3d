/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/26 13:19:44 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/28 18:10:26 by jeshin           ###   ########.fr       */
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

static void	set_ray_variable(int x, t_ray *ray, t_player *player)
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

static void	do_dda(t_ray *ray, char **map)
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

static void	set_ray_lineheight(t_ray *ray, t_player *player)
{
	if (ray->side == 0)
		ray->perp_wall_dist = ray->sidedist_x - ray->deltadist_x;
	else
		ray->perp_wall_dist = ray->sidedist_y - ray->deltadist_y;
	ray->line_height = (int)(SCREENHEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + SCREENHEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SCREENHEIGHT / 2;
	if (ray->draw_end >= SCREENHEIGHT)
		ray->draw_end = SCREENHEIGHT - 1;
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
}

void	get_texture_index(t_ray *ray, t_texture_info *texture_info)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			texture_info->index = WE;
		else
			texture_info->index = EA;
	}
	else
	{
		if (ray->dir_y > 0)
			texture_info->index = SO;
		else
			texture_info->index = NO;
	}
}

void	set_buffer(int x, t_ray *ray, t_texture_info *tex_info, int **buffer)
{
	t_texture	*tex;
	int			y;
	int			color;

	get_texture_index(ray, tex_info);
	tex = &(tex_info->tex_tab[tex_info->index]);
	tex_info->tex_x = (int)(ray->wall_x * (double)tex->width);
	if (ray->side == 0 && ray->dir_x > 0)
		tex_info->tex_x = tex->width - tex_info->tex_x - 1;
	if (ray->side == 1 && ray->dir_x < 0)
		tex_info->tex_x = tex->width - tex_info->tex_x - 1;
	tex_info->step = 1.0 * tex->height / ray->line_height;
	tex_info->pos = (ray->draw_start - SCREENHEIGHT / 2 + ray->line_height / 2) * tex_info->step;
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_info->tex_y = (int)tex_info->pos & (tex->height - 1);
		tex_info->pos += tex_info->step;
		color = (tex->pixel)[tex_info->tex_y][tex_info->tex_x];
		if (tex_info->index == NO || tex_info->index == EA)
			color = (color >> 1) & 8355711;
		if (color > 0)
			buffer[y][x] = color;
		y++;
	}
}

void	raycasting(t_data *data)
{
	int		x;

	x = -1;
	while (++x < SCREENWIDTH)
	{
		set_ray_variable(x, data->ray, data->player);
		do_dda(data->ray, data->map_info->map);
		set_ray_lineheight(data->ray, data->player);
		set_buffer(x, data->ray, data->texture_info, data->buffer);
	}
}
