/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:09:42 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/24 17:09:45 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf.h"

int		ft_choose_color(t_e *e, int y)
{
	int		color;

	if (e->side)
	{
		if (e->cam.step_y < 0)
			color = RED;
		else
			color = BLUE;
	}
	else
	{
		if (e->cam.step_x < 0)
			color = ORANGE;
		else
			color = GREEN;
	}
	if (y < e->draw_start)
		color = SKYBLUE;
	else if (y > e->draw_end)
		color = SADDLEBROWN;
	else if (e->map.map[e->map.y][e->map.x] == DOORS)
		color /= 2;
	return (color);
}

void	ft_draw_stripe(t_e *e, t_mlx *mlx, int x)
{
	int		y;
	int		pixel;
	int		color;

	y = -1;
	while (++y < H)
	{
		color = ft_choose_color(e, y);
		pixel = (x) + (y * W);
		mlx->istr[pixel] = color;
	}
}

void	ft_draw_img(t_mlx *mlx, t_e *e)
{
	ft_init_img(mlx);
	ft_compute_ray_data(e);
	mlx_put_image_to_window(e->mlx.mlx, e->mlx.win, e->mlx.img, 0, 0);
	mlx_destroy_image(mlx->mlx, mlx->img);
}
