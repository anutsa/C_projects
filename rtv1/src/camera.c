/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/20 19:47:43 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 19:22:45 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_rot_x(t_cam *cam)
{
	double	a;
	double	y;

	a = cam->rot[0] * PI / 180.0;
	y = cam->dir[1];
	cam->dir[0] = cam->dir[0] * 1 + y * 0 + cam->dir[2] * 0;
	cam->dir[1] = cam->dir[0] * 0 + y * cos(a) + cam->dir[2] * (-sin(a));
	cam->dir[2] = cam->dir[0] * 0 + y * sin(a) + cam->dir[2] * cos(a);
}

void	ft_rot_y(t_cam *cam)
{
	double	a;
	double	x;

	a = cam->rot[1] * PI / 180.0;
	x = cam->dir[0];
	cam->dir[0] = x * cos(a) + cam->dir[1] * 0 + cam->dir[2] * sin(a);
	cam->dir[1] = x * 0 + cam->dir[1] * 1 + cam->dir[2] * 0;
	cam->dir[2] = x * (-sin(a)) + cam->dir[1] * 0 + cam->dir[2] * cos(a);
}

void	ft_rot_z(t_cam *cam)
{
	double	a;
	double	x;

	a = cam->rot[2] * PI / 180.0;
	x = cam->dir[0];
	cam->dir[0] = x * cos(a) + cam->dir[1] * (-sin(a)) + cam->dir[2] * 0;
	cam->dir[1] = x * sin(a) + cam->dir[1] * cos(a) + cam->dir[2] * 0;
	cam->dir[2] = x * 0 + cam->dir[1] * 0 + cam->dir[2] * 1;
}

void	ft_rotate_cam(t_cam *cam)
{
	ft_rot_z(cam);
	ft_rot_x(cam);
	ft_rot_y(cam);
}

void	ft_set_ray(t_cam *cam, int x, int y)
{
	double	scale;

	scale = tan(cam->angle * 0.5);
	cam->dir[0] = (2 * ((x - (W - 1) * 0.5) + 0.5) / (W - 1)) * ASPR * scale;
	cam->dir[1] = (1 - 2 * ((y - (H - 1) * 0.5) + 0.5)) / H * scale;
	cam->dir[2] = 1;
	cam->t = (double)RAY_T_MAX;
	ft_rotate_cam(cam);
	normalv(cam->dir);
}
