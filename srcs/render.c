/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:42:40 by jeshin            #+#    #+#             */
/*   Updated: 2024/08/04 19:09:20 by seunghan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	put_pixel(t_img_info *img_info, int x, int y, int color)
{
	char	*dst;

	dst = img_info->addr \
			+ (y * img_info->line_length) \
			+ (x * (img_info->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	set_image(t_data *data, t_img_info *img_info, int x, int y)
{
	if (data->buffer[y][x] > 0)
		put_pixel(img_info, x, y, data->buffer[y][x]);
	else if (y < SCREENHEIGHT / 2)
		put_pixel(img_info, x, y, data->rgb->c);
	else if (y < SCREENHEIGHT - 1)
		put_pixel(img_info, x, y, data->rgb->f);
}

void	update_player_position(t_data *data)
{
	if (data->player->rotate != 0)
		rotate(data, data->player->rotate);
	if (data->player->move_y == -1)
		move_forward(data);
	if (data->player->move_y == 1)
		move_backward(data);
	if (data->player->move_x == -1)
		move_left(data);
	if (data->player->move_x == 1)
		move_right(data);
}

void	clear_buffer(int **buffer)
{
	int	i;

	i = -1;
	while (++i < SCREENHEIGHT)
		ft_bzero(buffer[i], sizeof(int) * SCREENWIDTH);
}

int	rendering(t_data *data)
{
	int			x;
	int			y;
	t_img_info	img_info;

	init_img_info(&img_info, data->mlx_info);
	clear_buffer(data->buffer);
	update_player_position(data);
	printf("p_y : %.3f\n",data->player->pos_y);
	printf("p_x : %.3f\n",data->player->pos_x);
	printf("map : %c\n",data->map_info->map[(int)data->player->pos_y][(int)data->player->pos_x]);
	raycasting(data);
	y = -1;
	while (++y < SCREENHEIGHT)
	{
		x = -1;
		while (++x < SCREENWIDTH)
			set_image(data, &img_info, x, y);
	}
	mlx_put_image_to_window(data->mlx_info->mlx, \
							data->mlx_info->win, \
							img_info.img, 0, 0);
	mlx_destroy_image(data->mlx_info->mlx, img_info.img);
	return (EXIT_SUCCESS);
}
