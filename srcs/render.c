/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:42:40 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/27 18:19:57 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
void	put_pixel(t_img_info * img_info, int x, int y, int color)
{
	char	*dst;

	dst = img_info->addr + (y * img_info->line_length + x * (img_info->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}
// void	put_pixel(t_img_info * img_info, int x, int y, int color)
// {
// 	int	pixel;

// 	pixel = y * (img_info->line_length / 4) + x;
// 	(img_info->addr)[pixel] = color;

// }

static void	set_image(t_data *data, t_img_info *img_info, int x, int y)
{
	if (data->buffer[y][x] > 0)
		put_pixel(img_info, x, y, data->buffer[y][x]);
	else if (y < SCREENHEIGHT / 2)
		put_pixel(img_info, x, y, data->rgb->c);
	else if (y < SCREENHEIGHT - 1)
		put_pixel(img_info, x, y, data->rgb->f);
}

void	init_img_info(t_data *data)
{
	data->img_info = (t_img_info *)malloc(sizeof(t_img_info));
	if (data->img_info == 0)
		sys_err("Error: malloc: ");
	data->img_info->img = mlx_new_image(data->mlx_info->mlx, SCREENWIDTH, SCREENHEIGHT);
	if (data->img_info->img == 0)
		sys_err("Error: mlx new image: ");
	data->img_info->addr = mlx_get_data_addr(data->img_info->img, &(data->img_info->bits_per_pixel), &(data->img_info->line_length), &(data->img_info->endian));
}


int	rendering(t_data *data)
{
	int		x;
	int		y;

	data->buffer = (int **)malloc(sizeof (int *) * SCREENHEIGHT);
	if (data->buffer == 0)
		sys_err("Error: malloc: ");
	int i = -1;
	while (++i < SCREENHEIGHT)
	{
		(data->buffer)[i] = malloc(sizeof(int) * SCREENWIDTH);
		if (data->buffer[i] == 0)
			sys_err("Error: malloc: ");
	}
	raycasting(data);
	init_img_info(data);
	y = -1;
	while (++y < SCREENHEIGHT)
	{
		x = -1;
		while (++x < SCREENWIDTH)
			set_image(data, data->img_info->img, x, y);
	}
	mlx_put_image_to_window(data->mlx_info->mlx, data->mlx_info->win, data->img_info->img ,0, 0);
	mlx_loop(data->mlx_info->mlx);
	// mlx_destroy_image(data->mlx_info->mlx, data->img_info->img);
	return (EXIT_SUCCESS);
}
