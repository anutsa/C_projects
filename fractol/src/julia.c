/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/12 16:59:03 by anutsa            #+#    #+#             */
/*   Updated: 2017/08/18 19:19:16 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_get_julia_set(double zr, double zi, t_fract *julia)
{
	int		i;
	double	temp;

	i = 0;
	while (i < MAX_ITER && (zr * zr + zi * zi < 4.0))
	{
		temp = zr * zr - zi * zi + julia->cr;
		zi = 2.0 * zr * zi + julia->ci;
		zr = temp;
		i++;
	}
	if (i != MAX_ITER)
		i = (i + 1 - (log((log(sqrt(zr * zr + zi * zi)) / 2)
						/ log(2)) / log(2)));
	return (i);
}

void	ft_init_julia(void *mlx, t_fract *julia)
{
	julia->mlx = mlx;
	julia->win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "julia");
	julia->name = 'j';
	julia->min_re = -1.5;
	julia->max_re = 1.5;
	julia->min_im = -1.3;
	julia->max_im = 1.3;
	julia->zoom = 1;
	julia->move_x = 0;
	julia->move_y = 0;
	julia->inout = 0;
	julia->cr = -0.7;
	julia->ci = 0.27015;
	julia->rfreq = 0.0;
	julia->gfreq = 0.1;
	julia->bfreq = -0.19;
	julia->rphase = 5.2;
	julia->gphase = 5.6;
	julia->bphase = -7.0;
	julia->monoch = 0;
	ft_init_img(julia);
}
