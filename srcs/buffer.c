/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/29 11:18:17 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/29 11:36:57 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	get_texture_index(t_ray *ray, t_texture_info *tex_info, t_texture **tex)
{
	if (ray->side == 0)
	{
		if (ray->dir_x < 0)
			tex_info->index = WE;
		else
			tex_info->index = EA;
	}
	else
	{
		if (ray->dir_y > 0)
			tex_info->index = SO;
		else
			tex_info->index = NO;
	}
	*tex = &(tex_info->tex_tab[tex_info->index]);
}

void	mapping_to_texture(t_ray *ray, t_player *player, \
							t_texture_info *tex_info, t_texture *tex)
{
	if (ray->side == 0)
		ray->wall_x = player->pos_y + ray->perp_wall_dist * ray->dir_y;
	else
		ray->wall_x = player->pos_x + ray->perp_wall_dist * ray->dir_x;
	ray->wall_x -= floor(ray->wall_x);
	tex_info->tex_x = (int)(ray->wall_x * (double)tex->width);
	if (ray->side == 0 && ray->dir_x > 0)
		tex_info->tex_x = tex->width - tex_info->tex_x - 1;
	if (ray->side == 1 && ray->dir_x < 0)
		tex_info->tex_x = tex->width - tex_info->tex_x - 1;
	tex_info->step = 1.0 * tex->height / ray->line_height;
	tex_info->pos = (ray->draw_start - SCREENHEIGHT / 2 + ray->line_height / 2) \
					* tex_info->step;
}

void	set_buffer(int x, t_data *data)
{
	int					y;
	int					color;
	t_ray				*ray;
	t_texture_info		*tex_info;
	t_texture			*tex;

	ray = data->ray;
	tex_info = data->texture_info;
	get_texture_index(ray, tex_info, &tex);
	mapping_to_texture(ray, data->player, tex_info, tex);
	y = ray->draw_start;
	while (y < ray->draw_end)
	{
		tex_info->tex_y = (int)tex_info->pos & (tex->height - 1);
		tex_info->pos += tex_info->step;
		color = (tex->pixel)[tex_info->tex_y][tex_info->tex_x];
		if (tex_info->index == NO || tex_info->index == EA)
			color = (color >> 1) & 8355711;
		if (color > 0)
			(data->buffer)[y][x] = color;
		y++;
	}
}
