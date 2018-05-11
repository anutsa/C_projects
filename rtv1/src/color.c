/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 18:14:20 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 20:46:32 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	ft_find_light_coef(t_scene *scene, t_vector dist, t_hit *hit)
{
	t_vector	reflect_ray;
	t_cam		newray;
	double		coef;

	coef = 0;
	if (hit->obj.shape == PLANE && dot(hit->nhit, dist) < 0)
		hit->nhit = vscale(-1, hit->nhit);
	if ((dot(hit->nhit, dist) > 0) && (length(dist)))
	{
		newray.t = length(dist);
		newray.pos = hit->phit;
		newray.dir = normalv(dist);
		reflect_ray = normalv(vscale(2 * dot(newray.dir, hit->nhit),
													hit->nhit) - newray.dir);
		if (!(ft_intersection(scene, &newray, false)))
		{
			coef += dot(newray.dir, hit->nhit) * 0.6;
			if (dot(reflect_ray, newray.dir) > 0)
				coef += pow(dot(reflect_ray, newray.dir), 10) * 0.3;
		}
	}
	return (coef);
}

int		ft_pixel_color(t_rgb clr, double coef)
{
	clr.c[0] = (unsigned char)fmin(clr.c[0] * (0.2 + coef), 255.0);
	clr.c[1] = (unsigned char)fmin(clr.c[1] * (0.2 + coef), 255.0);
	clr.c[2] = (unsigned char)fmin(clr.c[2] * (0.2 + coef), 255.0);
	return (clr.color);
}

void	ft_put_pixel(t_mlx *mlx, int x, int y, int color)
{
	int i;

	i = x + y * H;
	mlx->istr[i] = color;
}
