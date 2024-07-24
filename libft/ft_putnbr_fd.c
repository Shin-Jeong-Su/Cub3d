/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 22:06:10 by jeshin            #+#    #+#             */
/*   Updated: 2023/12/09 18:33:04 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char		c;
	long long	l;

	l = n;
	if (n < 0)
	{
		l *= -1;
		write(fd, "-", 1);
	}
	if (l < 10)
	{
		c = l + '0';
		write(fd, &c, 1);
		return ;
	}
	else if (l >= 10)
	{
		ft_putnbr_fd(l / 10, fd);
		c = (l % 10) + '0';
		write(fd, &c, 1);
		l /= 10;
	}
}

void	ft_putnbr_cnt(int n, int *num)
{
	char		c;
	long long	l;

	l = n;
	if (n < 0)
	{
		l *= -1;
		*num += write(1, "-", 1);
	}
	if (l < 10)
	{
		c = l + '0';
		*num += write(1, &c, 1);
		return ;
	}
	else if (l >= 10)
	{
		ft_putnbr_cnt(l / 10, num);
		c = (l % 10) + '0';
		*num += write(1, &c, 1);
		l /= 10;
	}
}

void	ft_putnbr_unsigned(unsigned int n, int *num)
{
	char		c;
	long long	l;

	l = n;
	if (n < 0)
	{
		l *= -1;
		*num += write(1, "-", 1);
	}
	if (l < 10)
	{
		c = l + '0';
		*num += write(1, &c, 1);
		return ;
	}
	else if (l >= 10)
	{
		ft_putnbr_unsigned(l / 10, num);
		c = (l % 10) + '0';
		*num += write(1, &c, 1);
		l /= 10;
	}
}
