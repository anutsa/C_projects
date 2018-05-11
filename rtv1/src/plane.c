/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/14 16:18:04 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 20:51:15 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_inter_plane(t_cam *cam, t_obj *pln, t_hit *hit, bool w)
{
	double	ddotn;
	double	t;

	ddotn = dot(cam->dir, pln->axis);
	if (ddotn == 0.0)
		return (0);
	t = dot(pln->pos - cam->pos, pln->axis) / ddotn;
	if (t < (double)RAY_T_MIN || t > cam->t)
		return (0);
	cam->t = t;
	if (w)
	{
		hit->clr = pln->clr;
		hit->shape = PLANE;
		hit->obj = *pln;
	}
	return (1);
}

void	ft_create_plane(t_scene *scene, t_mlx *mlx)
{
	scene->obj[3].visible = 1;
	scene->l[0].visible = 1;
	scene->l[1].visible = 1;
	ft_iterate_screen(scene, mlx);
}
