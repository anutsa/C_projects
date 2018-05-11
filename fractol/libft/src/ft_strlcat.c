/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 13:04:01 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/01 16:49:12 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t l;
	size_t t;

	i = 0;
	l = 0;
	while (dst[l] && l < size)
		l++;
	t = l;
	while (src[i] && l < size - 1)
		dst[l++] = src[i++];
	if (l < size)
		dst[l] = '\0';
	return (t + ft_strlen((char*)src));
}
