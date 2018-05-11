/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mandelbrot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 17:20:01 by anutsa            #+#    #+#             */
/*   Updated: 2017/08/18 19:07:20 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_get_mand_set(double cr, double ci)
{
	int		i;
	double	zr;
	double	zi;
	double	temp;

	i = 0;
	zr = 0.0;
	zi = 0.0;
	while (i < MAX_ITER && (zr * zr + zi * zi < 4.0))
	{
		temp = zr * zr - zi * zi + cr;
		zi = 2.0 * zr * zi + ci;
		zr = temp;
		i++;
	}
	if (i != MAX_ITER)
		i = (i + 1 - (log((log(sqrt(zr * zr + zi * zi)) / 2)
						/ log(2)) / log(2)));
	return (i);
}

void	ft_init_mandelbrot(void *mlx, t_fract *mand)
{
	mand->mlx = mlx;
	mand->win = mlx_new_window(mand->mlx, W_WIDTH, W_HEIGHT, "mandelbrot");
	mand->name = 'm';
	mand->min_re = -2.0;
	mand->max_re = 1.0;
	mand->min_im = -1.3;
	mand->max_im = 1.3;
	mand->zoom = 1;
	mand->move_x = 0;
	mand->move_y = 0;
	mand->rfreq = -0.01;
	mand->gfreq = 0.1;
	mand->bfreq = 0.01;
	mand->rphase = 0.3;
	mand->gphase = 4.1;
	mand->bphase = 1.3;
	mand->monoch = 0;
	ft_init_img(mand);
}
