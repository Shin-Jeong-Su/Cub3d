/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jeshin <jeshin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:19:17 by jeshin            #+#    #+#             */
/*   Updated: 2023/10/20 19:32:41 by jeshin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*new_lst;
	void	*f_result;

	new_lst = 0;
	if (!lst || !f || !del)
		return (0);
	while (lst)
	{
		f_result = f(lst->content);
		new = ft_lstnew(f_result);
		if (new)
			ft_lstadd_back(&new_lst, new);
		else
		{
			del(f_result);
			f_result = 0;
			ft_lstclear(&new_lst, del);
			return (0);
		}
		lst = lst->next;
	}
	return (new_lst);
}
