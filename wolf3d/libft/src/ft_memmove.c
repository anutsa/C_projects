/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 15:30:31 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/11 18:21:01 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	long int	l;

	l = len - 1;
	if ((unsigned long int)dst - (unsigned long int)src >= len)
		return (ft_memcpy(dst, src, len));
	else
	{
		while (l >= 0)
		{
			((unsigned char*)dst)[l] = ((unsigned char*)src)[l];
			l--;
		}
		return (dst);
	}
}
