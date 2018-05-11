/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/03 17:41:57 by anutsa            #+#    #+#             */
/*   Updated: 2016/12/08 18:46:35 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_strnum(char const *s, char c)
{
	int size;
	int j;

	size = 0;
	j = 0;
	if (s && c)
		while (s[j])
		{
			if (s[j] != c && (s[j + 1] == '\0' || s[j + 1] == c))
				size++;
			j++;
		}
	return (size);
}

static int		ft_strsize(char const *s, const int i, char c)
{
	int size;

	size = 0;
	while (s[i + size] != '\0' && s[i + size] != c)
		size++;
	return (size);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	size_t	i;
	int		j;
	int		snum;

	i = 0;
	j = 0;
	if (!(arr = (char **)malloc(sizeof(char *) * (ft_strnum(s, c) + 1))))
		return (NULL);
	if (s)
	{
		snum = ft_strnum(s, c);
		while (s[i] && snum > 0)
		{
			while (s[i] && s[i] == c)
				i++;
			arr[j++] = ft_strsub(s, i, ft_strsize(s, i, c));
			snum--;
			i += ft_strsize(s, i, c);
		}
		arr[j] = 0;
	}
	return (arr);
}
