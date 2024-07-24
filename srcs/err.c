/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 17:02:56 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/25 20:30:49 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	err(char *s)
{
	while (*s)
		write(2, s++, 1);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}

int	sys_err(void)
{
	perror("Error: ");
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
