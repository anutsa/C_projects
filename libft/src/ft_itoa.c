/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/08 16:18:18 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/09 15:02:29 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_size(long n)
{
	int		j;

	j = (n < 0) ? 2 : 1;
	n = (n < 0) ? -n : n;
	while (n >= 10)
	{
		n /= 10;
		j++;
	}
	return (j);
}

char			*ft_itoa(int n)
{
	char	*str;
	long	i;
	size_t	j;

	i = (n < 0) ? -(long)n : (long)n;
	j = ft_size(n);
	str = ft_strnew(j);
	if (str)
	{
		if (i == 0)
			str[--j] = i + '0';
		while (i > 0)
		{
			str[--j] = '0' + (i % 10);
			i /= 10;
		}
		if (n < 0)
			str[0] = '-';
		return (str);
	}
	else
		return (NULL);
}
