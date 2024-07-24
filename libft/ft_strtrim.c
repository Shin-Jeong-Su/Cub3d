/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 16:52:23 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/21 19:24:27 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	len_endof(char const *s1, char const *set)
{
	size_t	ret;
	size_t	len;
	size_t	prv_len;

	ret = 0;
	len = ft_strlen(s1);
	len--;
	while (s1[len])
	{
		if (ft_strchr(set, s1[len]))
			ret++;
		else
			break ;
		prv_len = len--;
		if (len > prv_len)
			break ;
	}
	return (ret);
}

size_t	len_begfrom(char const *s1, char const *set)
{
	size_t	ret;
	int		i;

	ret = 0;
	i = 0;
	while (s1[i])
	{
		if (ft_strchr(set, s1[i]))
			ret++;
		else
			break ;
		i++;
	}
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ret;
	size_t	len;
	size_t	l_beg;
	size_t	l_end;
	size_t	i;

	if (!s1)
		return (0);
	l_beg = len_begfrom(s1, set);
	l_end = len_endof(s1, set);
	len = ft_strlen(s1);
	if (l_beg + l_end >= len)
		len = 0;
	else
		len -= l_beg + l_end;
	ret = (char *)malloc(sizeof(char) * (len + 1));
	if (!ret)
		return (0);
	i = 0;
	while (s1[l_beg] && i < len)
		ret[i++] = s1[l_beg++];
	ret[i] = 0;
	return (ret);
}
