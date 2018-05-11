/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/08 11:28:29 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 19:32:41 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_set_hit_obj_cone(t_hit *hit, t_obj *cone)
{
	hit->clr = cone->clr;
	hit->shape = CONE;
	hit->obj = *cone;
}

int		ft_inter_cone(t_cam *cam, t_obj *cone, t_hit *hit, bool w)
{
	t_math	m;

	m.dist = cam->pos - cone->pos;
	m.a = length2(cam->dir) - (1 + tan(cone->coef) * tan(cone->coef))
		* dot(cam->dir, cone->axis) * dot(cam->dir, cone->axis);
	m.b = 2 * (dot(cam->dir, m.dist)
		- (1 + tan(cone->coef) * tan(cone->coef))
		* dot(cam->dir, cone->axis) * dot(m.dist, cone->axis));
	m.c = length2(m.dist) - (1 + tan(cone->coef) * tan(cone->coef))
		* dot(m.dist, cone->axis) * dot(m.dist, cone->axis);
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
		ft_set_hit_obj_cone(hit, cone);
	return (1);
}

void	ft_create_cone(t_scene *scene, t_mlx *mlx)
{
	scene->obj[6].visible = 1;
	scene->l[0].visible = 1;
	scene->l[1].visible = 1;
	ft_iterate_screen(scene, mlx);
}
