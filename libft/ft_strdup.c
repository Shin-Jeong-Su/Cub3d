/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 15:54:23 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/20 16:07:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		len;
	char	*ret;
	char	*tmp;

	len = ft_strlen(s1);
	ret = (char *)malloc(sizeof(char) * len + 1);
	if (!ret)
		return (0);
	tmp = ret;
	while (*s1)
	{
		*tmp = *s1;
		tmp++;
		s1++;
	}
	*tmp = 0;
	return (ret);
}
