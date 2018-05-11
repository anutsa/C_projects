/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene_params.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/21 16:42:26 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 20:07:55 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

t_cam	ft_init_cam(void)
{
	t_cam	cam;

	cam.pos = (t_vector){0.0, 0.0, -520.0};
	cam.rot = (t_vector){0.0, 0.0, 0.0};
	cam.angle = 90.0;
	return (cam);
}

void	ft_init_light_params(t_scene *scene)
{
	scene->l[0].visible = 0;
	scene->l[0].pos = (t_vector){-150.0, 0.0, -400.0};
	scene->l[0].intensity = 1;
	scene->l[1].visible = 0;
	scene->l[1].pos = (t_vector){350.0, 200.0, -400.0};
	scene->l[1].intensity = 1;
}

void	init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, W, H, "RTv1");
	mlx->img = mlx_new_image(mlx->mlx, W, H);
	mlx->bpp = 0;
	mlx->sizeline = 0;
	mlx->endian = 0;
	mlx->str = mlx_get_data_addr(mlx->img, &(mlx->bpp),
					&(mlx->sizeline), &(mlx->endian));
	mlx->istr = (int *)mlx->str;
}
