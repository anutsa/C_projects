/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 21:26:49 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/10 17:54:14 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;
	t_list	*tmp;

	tmp = NULL;
	new = NULL;
	if (lst && f)
	{
		if (!(tmp = f(ft_lstnew(lst->content, lst->content_size))))
			return (0);
		new = tmp;
		lst = lst->next;
		while (lst)
		{
			if (!(tmp->next = f(ft_lstnew(lst->content, lst->content_size))))
				return (0);
			tmp = tmp->next;
			lst = lst->next;
		}
		return (new);
	}
	return (0);
}
