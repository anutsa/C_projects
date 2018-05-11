/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_scene.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 12:56:52 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 20:49:31 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_check_light_src(t_scene *scene, t_hit *hit, t_cam *cam)
{
	t_vector	dist;
	t_rgb		clr;
	double		coef;
	int			i;

	hit->phit = cam->pos + vscale(cam->t, cam->dir);
	hit->nhit = ft_find_nhit(hit);
	clr = hit->clr;
	coef = 0;
	i = -1;
	if ((length2(hit->nhit)))
	{
		hit->nhit = normalv(hit->nhit);
		while (++i < LIGHTNUM)
		{
			if (scene->l[i].visible)
			{
				dist = scene->l[i].pos - hit->phit;
				coef += ft_find_light_coef(scene, dist, hit);
			}
		}
	}
	clr.color = ft_pixel_color(clr, coef);
	return (clr.color);
}

int		ft_intersection(t_scene *scene, t_cam *cam, bool write)
{
	int	i;
	int k;

	i = -1;
	k = 0;
	while (++i < OBJNUM)
	{
		if (scene->obj[i].visible)
		{
			if (scene->obj[i].shape == SPHERE)
				k += ft_inter_sphere(cam, &scene->obj[i], &scene->hit, write);
			else if (scene->obj[i].shape == PLANE)
				k += ft_inter_plane(cam, &scene->obj[i], &scene->hit, write);
			else if (scene->obj[i].shape == CONE)
				k += ft_inter_cone(cam, &scene->obj[i], &scene->hit, write);
			else if (scene->obj[i].shape == CYLINDER)
				k += ft_inter_cylinder(cam, &scene->obj[i], &scene->hit, write);
		}
	}
	if (!write && !k)
		return (0);
	if (cam->t > (double)RAY_T_MIN && cam->t < (double)RAY_T_MAX)
		return (1);
	return (0);
}

void	ft_iterate_screen(t_scene *scene, t_mlx *mlx)
{
	int x;
	int y;
	int col;

	y = -1;
	while (++y < H)
	{
		x = -1;
		while (++x < W)
		{
			col = 0;
			ft_set_ray(&scene->cam, x, y);
			if (ft_intersection(scene, &scene->cam, true))
				col = ft_check_light_src(scene, &scene->hit, &scene->cam);
			ft_put_pixel(mlx, x, y, col);
		}
	}
}
