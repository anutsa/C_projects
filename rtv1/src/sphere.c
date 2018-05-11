/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 20:17:17 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 20:44:38 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_vector	ft_find_nhit(t_hit *hit)
{
	t_vector	n;
	t_vector	v;
	t_vector	projv;

	n = (t_vector){1.0, 0.0, 0.0};
	if (hit->obj.shape == SPHERE)
		n = hit->phit - hit->obj.pos;
	else if (hit->obj.shape == PLANE)
		n = hit->obj.axis;
	else if (hit->obj.shape == CONE)
	{
		v = hit->phit - hit->obj.pos;
		projv = vscale(dot(v, hit->obj.axis) / length2(hit->obj.axis),
						hit->obj.axis);
		n = vscale((1 + tan(hit->obj.coef) * tan(hit->obj.coef)), (v - projv));
	}
	else if (hit->obj.shape == CYLINDER)
	{
		v = hit->phit - hit->obj.pos;
		projv = vscale(dot(v, hit->obj.axis), hit->obj.axis);
		n = v - projv;
	}
	return (n);
}

int			ft_inter_sphere(t_cam *cam, t_obj *sph, t_hit *hit, bool w)
{
	t_math		m;

	m.dist = cam->pos - sph->pos;
	m.a = dot(cam->dir, cam->dir);
	m.b = 2 * dot(cam->dir, m.dist);
	m.c = dot(m.dist, m.dist) - sph->coef * sph->coef;
	m.discr = (m.b * m.b) - (4 * m.a * m.c);
	if (m.discr < 0)
		return (0);
	m.t1 = (-m.b - sqrt(m.discr)) / (2 * m.a);
	m.t2 = (-m.b + sqrt(m.discr)) / (2 * m.a);
	if ((m.t1 > (double)RAY_T_MIN && m.t1 < cam->t))
		cam->t = m.t1;
	else if ((m.t2 > (double)RAY_T_MIN && m.t2 < cam->t))
		cam->t = m.t2;
	else
		return (0);
	if (w)
	{
		hit->clr = sph->clr;
		hit->shape = SPHERE;
		hit->obj = *sph;
	}
	return (1);
}

void		ft_create_sphere(t_scene *scene, t_mlx *mlx)
{
	scene->obj[0].visible = 1;
	scene->l[0].visible = 1;
	ft_iterate_screen(scene, mlx);
}
