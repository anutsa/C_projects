/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/22 17:51:50 by anutsa            #+#    #+#             */
/*   Updated: 2017/07/10 16:15:14 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error_handle(t_error_codes code)
{
	if (code == AC_NUM)
		ft_putstr("usage: fdf source_file\n");
	else if (code == FD)
		ft_putstr("Bad file descriptor or permission denied\n");
	else if (code == WIDTH)
		ft_putstr("Invalid map: different row lenth\n");
	else if (code == COLOR)
		ft_putstr("Invalid map (bad color symbols)\n");
	else if (code == EMPTY_MAP)
		ft_putstr("Empty file\n");
	else if (code == BAD_SYM)
		ft_putstr("Bad symbol\n");
	exit(1);
}

void	ft_valid_line(char **split)
{
	int		i;
	int		j;

	i = 0;
	while (split[i])
	{
		j = 0;
		while (ft_isdigit(split[i][j]))
			j++;
		if (!(split[i][j]) || split[i][j] == ',')
			i++;
		else
			ft_error_handle(BAD_SYM);
	}
}

int		validc(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 'A' && c <= 'F')
		return (1);
	else if (c >= 'a' && c <= 'f')
		return (1);
	return (0);
}

int		ft_atoi_base(char *s, int base)
{
	int res;
	int i;
	int j;

	i = 0;
	j = 6;
	(s[i] == '0') ? i++ : 0;
	(s[i] == 'x') ? i++ : 0;
	while (s[i] && validc(s[i]) && j-- > 0)
	{
		if (s[i] >= '0' && s[i] <= '9')
			res = res * base + s[i] - 48;
		else if (s[i] >= 'A' && s[i] <= 'F')
			res = res * base + s[i] - 55;
		else if (s[i] >= 'a' && s[i] <= 'f')
			res = res * base + s[i] - 87;
		i++;
	}
	if (s[i])
		ft_error_handle(COLOR);
	return (res);
}

int		ft_get_color_num(char *s)
{
	int		res;
	char	*buf;

	res = 0;
	buf = ft_strsub(s, (ft_strchr(s, ',') - s + 1),
	ft_strlen(s) - (ft_strchr(s, ',') - s) - 1);
	res = ft_atoi_base(buf, 16);
	ft_strdel(&buf);
	return (res);
}
