/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/02 11:44:14 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/09 19:19:17 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t *str;

	str = 0;
	str = (size_t *)malloc(size);
	if (str)
	{
		ft_bzero(str, size);
		return (str);
	}
	else
		return (NULL);
}
