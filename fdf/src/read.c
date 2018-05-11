/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/27 18:10:15 by anutsa            #+#    #+#             */
/*   Updated: 2017/07/10 16:15:23 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_fdflst	*ft_getdownlst(t_fdflst *lst)
{
	double		x;

	x = lst->x0;
	lst = lst->next;
	while (lst)
	{
		if (lst->x0 == x)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void		ft_addlink(t_fdflst *lst, double y, t_fdfmlx *init)
{
	while (lst)
	{
		lst->down = ((lst->y0 == (y - 1)) ? NULL : ft_getdownlst(lst));
		(init->minheight > (int)lst->z0) ? init->minheight = (int)lst->z0 : 0;
		(init->maxheight < (int)lst->z0) ? init->maxheight = (int)lst->z0 : 0;
		lst->x0 -= (init->width - 1) / 2;
		lst->y0 -= (y - 1) / 2;
		lst = lst->next;
	}
}

void		ft_lstpb(t_fdflst **lst, double x, double y, char *str)
{
	t_fdflst	*tmp;
	t_fdflst	*buf;

	tmp = (t_fdflst *)ft_memalloc(sizeof(t_fdflst));
	tmp->x0 = x;
	tmp->y0 = y;
	tmp->z0 = ft_atoi(str);
	tmp->step = 1.0;
	tmp->color = WHITE;
	if ((ft_strchr(str, ',')))
		tmp->color = ft_get_color_num(str);
	tmp->next = NULL;
	buf = *lst;
	if (buf)
	{
		while (buf->next)
			buf = buf->next;
		buf->next = tmp;
	}
	else
		*lst = tmp;
}

double		ft_savedata(char **split, t_fdflst **lst, double y)
{
	double	x;

	x = 0.0;
	while (split[(int)x])
	{
		ft_lstpb(lst, x, y, split[(int)x]);
		ft_strdel(split + (int)x);
		x++;
	}
	return (x);
}

int			ft_fdfread(int fd, t_fdflst **lst, t_fdfmlx *init)
{
	char		*line;
	char		**split;
	double		x;
	double		y;
	double		width;

	y = 0.0;
	x = 0.0;
	width = -1;
	while ((get_next_line(fd, &line)))
	{
		split = ft_strsplit(line, ' ');
		ft_valid_line(split);
		ft_strdel(&line);
		if (!(x = ft_savedata(split, lst, y)) || (x != width && width != -1))
			ft_error_handle(WIDTH);
		free(split);
		width = x;
		y++;
	}
	(width == -1) ? ft_error_handle(EMPTY_MAP) : 0;
	init->width = x;
	init->height = y;
	ft_addlink(*lst, y, init);
	return (0);
}
