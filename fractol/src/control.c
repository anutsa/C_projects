/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/08/01 15:31:16 by anutsa            #+#    #+#             */
/*   Updated: 2017/08/18 19:19:23 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_key(int keycode, t_fract *f)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == 124 || keycode == 123)
		f->move_x += (keycode == 123) ? 0.01 : -.01;
	else if (keycode == 125 || keycode == 126)
		f->move_y += (keycode == 126) ? 0.01 : -.01;
	else if (keycode == 12 || keycode == 0)
		f->rfreq += (keycode == 12) ? 0.01 : -.01;
	else if (keycode == 13 || keycode == 1)
		f->gfreq += (keycode == 13) ? 0.01 : -.01;
	else if (keycode == 14 || keycode == 2)
		f->bfreq += (keycode == 14) ? 0.01 : -.01;
	else if (keycode == 15 || keycode == 3)
		f->rphase += (keycode == 15) ? 0.1 : -.1;
	else if (keycode == 17 || keycode == 5)
		f->gphase += (keycode == 17) ? 0.1 : -.1;
	else if (keycode == 16 || keycode == 4)
		f->bphase += (keycode == 16) ? 0.1 : -.1;
	else if (keycode == 38)
		f->inout = (f->inout == 1) ? 0 : 1;
	else if (keycode == 46)
		f->monoch = (f->monoch == 0) ? 1 : 0;
	ft_init_img(f);
	return (0);
}

int		ft_zoom(int key, int x, int y, t_fract *f)
{
	double	delta_x;
	double	delta_y;

	if (key == 4)
		f->zoom = 1.1;
	if (key == 5)
		f->zoom = 0.9;
	delta_x = (double)x * RE_FACTOR(f->max_re, f->min_re) + f->min_re;
	delta_y = (double)y * IM_FACTOR(f->max_im, f->min_im) + f->min_im;
	f->min_re = f->min_re * f->zoom + delta_x * (1 - f->zoom);
	f->max_re = f->max_re * f->zoom + delta_x * (1 - f->zoom);
	f->min_im = f->min_im * f->zoom + delta_y * (1 - f->zoom);
	f->max_im = f->max_im * f->zoom + delta_y * (1 - f->zoom);
	ft_init_img(f);
	return (0);
}

int		ft_iterate_julia(int x, int y, t_fract *j)
{
	if (j->inout == 1 && (x >= 0 && x < W_WIDTH) && (y >= 0 && y < W_HEIGHT))
	{
		j->cr = x * RE_FACTOR(j->max_re, j->min_re) + j->min_re + j->move_x;
		j->ci = y * RE_FACTOR(j->max_im, j->min_im) + j->min_im + j->move_y;
		ft_init_img(j);
	}
	return (0);
}

void	ft_event(t_fract *f)
{
	mlx_hook(f->win, 2, 1 << 7, ft_key, f);
	mlx_hook(f->win, 4, 0, ft_zoom, f);
	if (f->name == 'j')
		mlx_hook(f->win, 6, 0, ft_iterate_julia, f);
}
