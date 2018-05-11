/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burning_ship.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/31 20:22:08 by anutsa            #+#    #+#             */
/*   Updated: 2017/08/18 19:07:17 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		ft_get_ship_set(double cr, double ci)
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
		zi = 2.0 * FABS(zr) * FABS(zi) + ci;
		zr = temp;
		i++;
	}
	if (i != MAX_ITER)
		i = (i + 1 - (log((log(sqrt(zr * zr + zi * zi)) / 2)
						/ log(2)) / log(2)));
	return (i);
}

void	ft_init_ship(void *mlx, t_fract *ship)
{
	ship->mlx = mlx;
	ship->win = mlx_new_window(mlx, W_WIDTH, W_HEIGHT, "burning_ship");
	ship->name = 's';
	ship->min_re = -2.0;
	ship->max_re = 1.0;
	ship->min_im = -1.5;
	ship->max_im = 1.0;
	ship->zoom = 1;
	ship->move_x = 0;
	ship->move_y = 0;
	ship->rfreq = -0.12;
	ship->gfreq = -0.05;
	ship->bfreq = 0.03;
	ship->rphase = 4.4;
	ship->gphase = 4.4;
	ship->bphase = 4.4;
	ship->monoch = 0;
	ft_init_img(ship);
}
