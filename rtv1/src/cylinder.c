/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 16:41:36 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 20:02:35 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_set_hit_obj_cyl(t_hit *hit, t_obj *cyl)
{
	hit->clr = cyl->clr;
	hit->shape = CYLINDER;
	hit->obj = *cyl;
}

int		ft_inter_cylinder(t_cam *cam, t_obj *cyl, t_hit *hit, bool w)
{
	t_math	m;

	m.dist = cam->pos - cyl->pos;
	m.a = length2(cam->dir)
		- dot(cam->dir, cyl->axis) * dot(cam->dir, cyl->axis);
	m.b = 2 * (dot(cam->dir, m.dist)
		- dot(cam->dir, cyl->axis) * dot(m.dist, cyl->axis));
	m.c = length2(m.dist)
		- dot(m.dist, cyl->axis) * dot(m.dist, cyl->axis)
		- cyl->coef * cyl->coef;
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
		ft_set_hit_obj_cyl(hit, cyl);
	return (1);
}

void	ft_create_cylinder(t_scene *scene, t_mlx *mlx)
{
	scene->obj[7].visible = 1;
	scene->l[0].visible = 1;
	scene->l[1].visible = 1;
	ft_iterate_screen(scene, mlx);
}
