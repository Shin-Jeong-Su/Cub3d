/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 18:13:17 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/21 19:19:52 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	word_count(char const *s, char c)
{
	size_t	ret;
	int		i;

	ret = 0;
	i = 0;
	if (s[i] && s[i] != c)
		ret++;
	while (s[i])
	{
		if (s[i] == c && (s[i + 1] != c && s[i + 1] != 0))
			ret++;
		i++;
	}
	return (ret);
}

char	*ft_strdup_till_c(const char **s, char c)
{
	char	*ret;
	int		i;

	i = 0;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	ret = (char *)malloc(sizeof(char) * (i + 1));
	if (!ret)
		return (0);
	i = 0;
	while (**s && **s != c)
	{
		ret[i] = **s;
		(*s)++;
		i++;
	}
	ret[i] = 0;
	return (ret);
}

void	is_deli(char const **s, char c)
{
	while (**s && **s == c)
		(*s)++;
}

void	arr_clear_all(char **arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(arr[i]);
		arr[i] = 0;
		i++;
	}
	free(arr);
	arr = 0;
}

char	**ft_split(char const *s, char c)
{
	char		**ret;
	char		*str;
	int			i;

	ret = (char **)malloc(sizeof(char *) * (word_count(s, c) + 1));
	if (!ret)
		return (0);
	i = 0;
	while (*s)
	{
		is_deli(&s, c);
		if (*s && (*s != c))
		{
			str = ft_strdup_till_c(&s, c);
			if (!str)
			{
				arr_clear_all(ret, i);
				return (0);
			}
			ret[i++] = str;
		}
	}
	ret[i] = 0;
	return (ret);
}
