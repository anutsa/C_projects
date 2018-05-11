/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/01 20:22:32 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/01 20:43:55 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int mult;
	int neg;

	mult = 0;
	neg = 1;
	while (*str == ' ' || *str == '\n' || *str == '\t' || *str == '\v' ||
			*str == '\r' || *str == '\f')
		str++;
	if (*str == '-')
	{
		neg = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
	{
		mult *= 10;
		mult += *str - '0';
		str++;
	}
	return (mult * neg);
}
