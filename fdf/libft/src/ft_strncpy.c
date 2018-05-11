/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 19:51:58 by anutsa            #+#    #+#             */
/*   Updated: 2016/11/29 19:52:05 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dest, char *src, size_t len)
{
	int	i;

	i = 0;
	while (len > 0 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
		len--;
	}
	while (len > 0)
	{
		dest[i++] = '\0';
		len--;
	}
	return (dest);
}
