/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 18:02:39 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 17:24:06 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

int		ft_key(int keycode, t_mlx *mlx)
{
	t_mlx	*x;

	x = mlx;
	if (keycode == ESC)
		exit(0);
	return (0);
}

void	ft_err(int code, const char **fname)
{
	int		i;

	i = 0;
	if (code == USAGE)
	{
		ft_putstr("usage: RTv1 scene_name ...\n");
		while (fname[i])
			ft_putendl(fname[i++]);
	}
	exit(1);
}

void	ft_choose_scene(t_scene *scene, t_mlx *mlx)
{
	ft_init_obj_params(scene);
	if (scene->id == 0)
		ft_create_sphere(scene, mlx);
	else if (scene->id == 1)
		ft_create_plane(scene, mlx);
	else if (scene->id == 2)
		ft_create_cone(scene, mlx);
	else if (scene->id == 3)
		ft_create_cylinder(scene, mlx);
	else if (scene->id == 4)
		ft_create_triplet(scene, mlx);
	else if (scene->id == 5)
		ft_create_mix(scene, mlx);
}

void	ft_check_name(char *av, const char **scenes)
{
	int			i;
	int			valname;
	t_mlx		mlx;
	t_scene		scene;

	i = -1;
	valname = 1;
	while (scenes[++i])
	{
		if (!(valname = ft_strcmp(av, scenes[i])))
		{
			init_mlx(&mlx);
			scene.id = i;
			ft_choose_scene(&scene, &mlx);
			break ;
		}
	}
	if (valname)
		ft_err(USAGE, scenes);
	mlx_put_image_to_window(mlx.mlx, mlx.win, mlx.img, 0, 0);
	mlx_hook(mlx.win, 2, 1 << 7, ft_key, &mlx);
	mlx_loop(&mlx);
}

int		main(int ac, char **av)
{
	const char	*scenes[] = {"sphere", "plane", "cone", "cylinder",
				"triplet", "mix", 0};

	if (ac != 2)
		ft_err(USAGE, scenes);
	ft_check_name(av[1], scenes);
	return (0);
}
