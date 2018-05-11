/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 17:41:05 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/01 19:42:06 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;

	i = 0;
	if (*little == '\0')
		return ((char *)big);
	while (big[i])
	{
		j = 0;
		while (big[i] && little[j] && big[i] == little[j])
		{
			i++;
			j++;
		}
		if (little[j] == '\0')
			return ((char *)big + i - j);
		else
			i -= j;
		i++;
	}
	return (NULL);
}
