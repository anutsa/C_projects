/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 20:14:28 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/09 21:00:14 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*tmp;
	t_list	*lst;

	tmp = 0;
	lst = *alst;
	while (lst)
	{
		if (lst->next)
			tmp = lst->next;
		else
			tmp = 0;
		del(lst->content, lst->content_size);
		free(lst);
		lst = tmp;
	}
	*alst = lst;
}
