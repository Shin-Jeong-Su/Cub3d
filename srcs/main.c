/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 16:38:33 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/26 12:43:37 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	chl(void)
{
	system("leaks cub3D");
}

int	main(int ac, char **av)
{
	t_data	data;

	atexit(chl);
	init(ac, av, &data);
	parse(&data);
	display(&data);
}
