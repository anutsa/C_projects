/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 15:37:39 by anutsa            #+#    #+#             */
/*   Updated: 2016/11/29 19:50:47 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*x;
	int				i;

	x = b;
	i = 0;
	while (len > 0)
	{
		x[i++] = (unsigned char)c;
		len--;
	}
	return (b);
}
