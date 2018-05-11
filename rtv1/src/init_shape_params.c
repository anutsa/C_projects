/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_shape_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 17:14:42 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 21:26:10 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_init_sph_params(t_scene *scene)
{
	scene->obj[0].visible = 0;
	scene->obj[0].shape = SPHERE;
	scene->obj[0].pos = (t_vector){0.0, 0.0, 0.0};
	scene->obj[0].coef = 200.0;
	scene->obj[0].clr.color = 0x0000FF;
	scene->obj[1].visible = 0;
	scene->obj[1].shape = SPHERE;
	scene->obj[1].pos = (t_vector){-200.0, -90.0, -100.0};
	scene->obj[1].coef = 100.0;
	scene->obj[1].clr.color = 0x0FFF0F;
	scene->obj[2].visible = 0;
	scene->obj[2].shape = SPHERE;
	scene->obj[2].pos = (t_vector){150.0, -90.0, -150.0};
	scene->obj[2].coef = 50.0;
	scene->obj[2].clr.color = 0xFFFFF0;
}

void	ft_init_plane_params(t_scene *scene)
{
	scene->obj[3].visible = 0;
	scene->obj[3].shape = PLANE;
	scene->obj[3].pos = (t_vector){0.0, -150.0, 0.0};
	scene->obj[3].axis = normalv(((t_vector){0.0, -50.0, 5.0})
											- scene->obj[3].pos);
	scene->obj[3].clr.color = 0xFF0000;
	scene->obj[4].visible = 0;
	scene->obj[4].shape = PLANE;
	scene->obj[4].pos = (t_vector){100.0, 0.0, 300.0};
	scene->obj[4].axis = normalv(((t_vector){0.0, 0.0, 0.0})
											- scene->obj[4].pos);
	scene->obj[4].clr.color = 0x33CCFF;
	scene->obj[5].visible = 0;
	scene->obj[5].shape = PLANE;
	scene->obj[5].pos = (t_vector){-300.0, 0.0, 100.0};
	scene->obj[5].axis = normalv(((t_vector){0.0, 0.0, 0.0})
											- scene->obj[5].pos);
	scene->obj[5].clr.color = 0xFFF000;
}

void	ft_init_cone_params(t_scene *scene)
{
	scene->obj[6].visible = 0;
	scene->obj[6].shape = CONE;
	scene->obj[6].pos = (t_vector){100.0, 100.0, -250.0};
	scene->obj[6].axis = normalv(((t_vector){200.0, 0.0, -250.0})
											- scene->obj[6].pos);
	scene->obj[6].coef = 20.0 * PI / 180.0;
	scene->obj[6].clr.color = 0xFFFF00;
}

void	ft_init_cylinder_params(t_scene *scene)
{
	scene->obj[7].visible = 0;
	scene->obj[7].shape = CYLINDER;
	scene->obj[7].pos = (t_vector){-70.0, -100.0, -250.0};
	scene->obj[7].axis = normalv(((t_vector){100.0, 100.0, -240.0})
											- scene->obj[7].pos);
	scene->obj[7].coef = 70.0;
	scene->obj[7].clr.color = 0x00FF00;
}

void	ft_init_obj_params(t_scene *scene)
{
	ft_init_sph_params(scene);
	ft_init_plane_params(scene);
	ft_init_cone_params(scene);
	ft_init_cylinder_params(scene);
	ft_init_light_params(scene);
	scene->cam = ft_init_cam();
}
