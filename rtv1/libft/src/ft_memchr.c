/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 16:38:22 by anutsa            #+#    #+#             */
/*   Updated: 2016/11/30 19:01:18 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	int i;

	i = 0;
	while (n > 0)
	{
		if (((unsigned char*)s)[i] == (unsigned char)c)
			return (&((unsigned char*)s)[i]);
		i++;
		n--;
	}
	return (NULL);
}
