/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 17:11:59 by jeshin            #+#    #+#             */
/*   Updated: 2024/07/28 18:07:01 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_space(const char ch)
{
	if (ch == 32 || (ch >= 9 && ch <= 13))
		return (1);
	return (0);
}

static int	is_digit(const char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	return (0);
}

long long	ft_atol(const char *str)
{
	long long	sign;
	long long	ret;

	ret = 0;
	sign = 1;
	while (is_space(*str))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (is_digit(*str))
	{
		ret = ret * 10 + (*str - '0');
		str++;
	}
	return ((sign * ret));
}
