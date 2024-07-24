/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:34:20 by jeshin            #+#    #+#             */
/*   Updated: 2024/06/05 17:05:11 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	i;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	ret = (char *)malloc(len_s1 + len_s2 + 1);
	if (!ret)
		return (0);
	i = 0;
	while (i < len_s1)
	{
		ret[i] = *s1;
		s1++;
		i++;
	}
	while (i - len_s1 < len_s2)
	{
		ret[i] = *s2;
		s2++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}
