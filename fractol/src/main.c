/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:16:32 by anutsa            #+#    #+#             */
/*   Updated: 2017/08/18 19:07:13 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"
#include <stdio.h>

void	ft_err(int code, const char **fname)
{
	int		i;

	i = 0;
	if (code == USAGE)
	{
		ft_putstr("usage: fractol fractol_name ...\n");
		while (fname[i])
			ft_putendl(fname[i++]);
	}
	else if (code == MLX)
		ft_putstr("Fails to set up the connection to the X server\n");
	exit(1);
}

int		ft_check_fname(char **av, const char **fname)
{
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 1;
	while (av[++i])
	{
		j = 0;
		while (fname[j])
		{
			if (!(k = ft_strcmp(av[i], fname[j])))
				break ;
			j++;
		}
		if (k)
			ft_err(USAGE, fname);
	}
	return (i - 1);
}

void	ft_init_fractol(char **name, void *mlx, int frnum)
{
	int		i;
	t_fract	fr[frnum];

	i = 1;
	while (name[i])
	{
		if (!(ft_strcmp(name[i], "Julia")))
			ft_init_julia(mlx, &fr[i - 1]);
		else if (!(ft_strcmp(name[i], "Mandelbrot")))
			ft_init_mandelbrot(mlx, &fr[i - 1]);
		else if (!(ft_strcmp(name[i], "Ship")))
			ft_init_ship(mlx, &fr[i - 1]);
		i++;
	}
	mlx_loop(mlx);
}

int		main(int ac, char **av)
{
	const char		*fname[] = {"Julia", "Mandelbrot", "Ship", 0};
	void			*mlx;

	if (ac < 2)
		ft_err(USAGE, fname);
	if (!(mlx = mlx_init()))
		ft_err(MLX, (const char **)av);
	ft_init_fractol(av, mlx, ft_check_fname(av, fname));
	return (0);
}
