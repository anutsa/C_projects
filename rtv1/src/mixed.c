/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mixed.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/18 19:16:32 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 19:45:21 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	ft_create_triplet(t_scene *scene, t_mlx *mlx)
{
	scene->obj[0].visible = 1;
	scene->obj[1].visible = 1;
	scene->obj[2].visible = 1;
	scene->l[0].visible = 1;
	scene->l[1].visible = 1;
	ft_iterate_screen(scene, mlx);
}

void	ft_create_mix(t_scene *scene, t_mlx *mlx)
{
	scene->obj[2].visible = 1;
	scene->obj[3].visible = 1;
	scene->obj[4].visible = 1;
	scene->obj[6].visible = 1;
	scene->obj[7].visible = 1;
	scene->l[0].visible = 1;
	scene->l[1].visible = 1;
	ft_iterate_screen(scene, mlx);
}
