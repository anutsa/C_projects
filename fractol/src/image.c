/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/13 17:14:06 by anutsa            #+#    #+#             */
/*   Updated: 2017/08/18 19:07:32 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_get_color(int iter, t_fract *f)
{
	t_rgb	col;

	if (f->monoch == 1)
		col.color = MAX_ITER - (65536 * iter + 256 * iter + iter);
	else
	{
		col.c[0] = sin(f->bfreq * iter + f->bphase) * 127 + 128;
		col.c[1] = sin(f->gfreq * iter + f->gphase) * 127 + 128;
		col.c[2] = sin(f->rfreq * iter + f->rphase) * 127 + 128;
	}
	col.c[3] = 0;
	return (col.color);
}

void	ft_draw_fract(int x, int y, t_fract *f)
{
	double	xr;
	double	yi;
	size_t	i;
	int		color;

	i = x + y * W_WIDTH;
	xr = (double)x * RE_FACTOR(f->max_re, f->min_re) + f->min_re + f->move_x;
	yi = (double)y * IM_FACTOR(f->max_im, f->min_im) + f->min_im + f->move_y;
	if (f->name == 'm')
		color = ft_get_mand_set(xr, yi);
	else if (f->name == 'j')
		color = ft_get_julia_set(xr, yi, f);
	else
		color = ft_get_ship_set(xr, yi);
	f->istr[i] = (color == MAX_ITER) ? 0 : ft_get_color(color, f);
}

void	*ft_threads(void *t)
{
	int			x;
	int			y;
	int			limit;
	t_threads	*thr;

	thr = (t_threads *)t;
	y = thr->y;
	limit = thr->y + W_HEIGHT * 0.25;
	while (y < limit)
	{
		x = -1;
		while (++x < W_WIDTH)
			ft_draw_fract(x, y, thr->cur);
		y++;
	}
	pthread_exit(NULL);
}

void	ft_threads_create(t_fract *cur)
{
	t_threads	thr[4];
	pthread_t	thrid[4];
	int			i;

	i = 0;
	while (i < 4)
	{
		thr[i].cur = cur;
		thr[i].y = i * W_HEIGHT * 0.25;
		pthread_create(&thrid[i], NULL, &ft_threads, (void *)&thr[i]);
		i++;
	}
	i = -1;
	while (++i < 4)
		pthread_join(thrid[i], NULL);
}

void	ft_init_img(t_fract *f)
{
	f->img = mlx_new_image(f->mlx, W_WIDTH, W_HEIGHT);
	f->bpp = 0;
	f->sizeline = 0;
	f->endian = 0;
	f->str = mlx_get_data_addr(f->img, &(f->bpp),
									&(f->sizeline), &(f->endian));
	f->istr = (int *)f->str;
	ft_threads_create(f);
	mlx_put_image_to_window(f->mlx, f->win, f->img, 0, 0);
	mlx_destroy_image(f->mlx, f->img);
	ft_event(f);
}
