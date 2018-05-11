/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/05 17:44:40 by anutsa            #+#    #+#             */
/*   Updated: 2017/07/10 16:16:01 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_scale(t_fdflst *lst, t_fdfmlx *init)
{
	while (lst)
	{
		lst->x = lst->x0 * init->step;
		lst->y = lst->y0 * init->step;
		lst->z = lst->z0 * init->step;
		lst = lst->next;
	}
}

void	ft_rx(t_fdflst *lst, int ang)
{
	double	a;
	double	y;

	a = ang * PI / 180.0;
	y = lst->y;
	while (lst)
	{
		lst->x = lst->x * 1 + lst->y * 0 + lst->z * 0;
		lst->y = lst->x * 0 + lst->y * cos(a) + lst->z * (-sin(a));
		lst->z = lst->x * 0 + y * sin(a) + lst->z * cos(a);
		lst = lst->next;
	}
}

void	ft_ry(t_fdflst *lst, int ang)
{
	double	a;
	double	x;

	a = ang * PI / 180.0;
	x = lst->x;
	while (lst)
	{
		lst->x = lst->x * cos(a) + lst->y * 0 + lst->z * sin(a);
		lst->y = lst->x * 0 + lst->y * 1 + lst->z * 0;
		lst->z = x * (-sin(a)) + lst->y * 0 + lst->z * cos(a);
		lst = lst->next;
	}
}

void	ft_rz(t_fdflst *lst, int ang)
{
	double	a;
	double	x;

	a = ang * PI / 180.0;
	x = lst->x;
	while (lst)
	{
		lst->x = lst->x * cos(a) + lst->y * (-sin(a)) + lst->z * 0;
		lst->y = x * sin(a) + lst->y * cos(a) + lst->z * 0;
		lst->z = lst->x * 0 + lst->y * 0 + lst->z * 1;
		lst = lst->next;
	}
}

void	ft_get_projection(t_fdflst *lst, t_fdfmlx *init)
{
	ft_scale(lst, init);
	ft_rz(lst, init->za);
	ft_rx(lst, init->xa);
	ft_ry(lst, init->ya);
}
