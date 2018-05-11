/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/26 11:46:30 by anutsa            #+#    #+#             */
/*   Updated: 2017/07/10 16:15:27 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		exit_mouse(t_fdfmlx *init)
{
	mlx_destroy_window(init->mlx, init->win);
	exit(0);
	return (0);
}

void	ft_my_pixel_put(t_fdfmlx *init, t_bres *line, t_fdflst *s)
{
	size_t	i;

	i = line->y * init->sizeline + line->x * init->bpp / 8;
	if ((line->x < 0 || line->x >= W_WIDTH) || (line->y < 0 ||
			line->y >= W_HEIGHT) || i >= (size_t)(init->sizeline * W_HEIGHT))
		return ;
	init->str[i] = (s->color & 0xFF);
	init->str[++i] = (s->color >> 8) & 0xFF;
	init->str[++i] = ((s->color >> 16) & 0xFF);
}

void	ft_drawline(t_fdfmlx *init, t_fdflst *s, t_fdflst *e, t_bres *line)
{
	line->x = (int)s->x + W_WIDTH / 2;
	line->y = (int)s->y + W_HEIGHT / 2;
	line->sx = s->x < e->x ? 1 : -1;
	line->sy = s->y < e->y ? 1 : -1;
	line->dx = abs((int)e->x - (int)s->x);
	line->dy = abs((int)e->y - (int)s->y);
	line->err = (line->dx > line->dy ? line->dx : -line->dy) / 2;
	while (line->x != ((int)e->x + W_WIDTH / 2) ||
					line->y != ((int)e->y) + W_HEIGHT / 2)
	{
		ft_my_pixel_put(init, line, s);
		line->e2 = line->err;
		if (line->e2 > -line->dx)
		{
			line->err -= line->dy;
			line->x += line->sx;
		}
		if (line->e2 < line->dy)
		{
			line->err += line->dx;
			line->y += line->sy;
		}
	}
	ft_my_pixel_put(init, line, s);
}

void	ft_drawmap(t_fdflst *lst, t_fdfmlx *init)
{
	t_bres	line;

	init->l = lst;
	ft_get_projection(lst, init);
	while (lst && lst->next)
	{
		if ((init->ya > 90 && init->ya < 270) ||
				(init->ya < -90 && init->ya > -270))
			(lst->x >= lst->next->x) ?
				ft_drawline(init, lst, lst->next, &line) : 0;
		else
			(lst->x <= lst->next->x) ?
				ft_drawline(init, lst, lst->next, &line) : 0;
		(lst->down) ? ft_drawline(init, lst, lst->down, &line) : 0;
		lst = lst->next;
	}
	mlx_put_image_to_window(init->mlx, init->win, init->img, 0, 0);
	mlx_hook(init->win, 2, 1 << 7, my_key_funct, init);
	mlx_hook(init->win, 17, 1L << 17, exit_mouse, init->mlx);
	mlx_loop(init->mlx);
}

void	ft_zoom(t_fdfmlx *init)
{
	double	hypo;
	double	x;
	double	y;
	int		z;

	hypo = sqrt(pow(W_WIDTH, 2) + pow(W_HEIGHT, 2));
	z = (init->maxheight - init->minheight);
	x = ZOOM(W_WIDTH, init->width);
	y = ZOOM(W_HEIGHT, init->height);
	init->step = (x < y) ? x : y;
	if (z > 0)
		(init->step > ZOOM(hypo, z)) ? init->step = ZOOM(hypo, z) : 0;
	(init->step == 0) ? init->step = 1 : 0;
}
