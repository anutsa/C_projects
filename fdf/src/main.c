/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:22:35 by anutsa            #+#    #+#             */
/*   Updated: 2017/07/10 16:15:39 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_init_win(t_fdfmlx *init)
{
	init->win = mlx_new_window(init->mlx, W_WIDTH, W_HEIGHT, "fdf");
	init->img = mlx_new_image(init->mlx, W_WIDTH, W_HEIGHT);
	init->bpp = 0;
	init->sizeline = 0;
	init->endian = 0;
	init->str = mlx_get_data_addr(init->img, &(init->bpp),
							&(init->sizeline), &(init->endian));
}

void	ft_redraw(t_fdfmlx *init)
{
	mlx_destroy_window(init->mlx, init->win);
	ft_init_win(init);
	ft_drawmap(init->l, init);
}

int		my_key_funct(int keycode, t_fdfmlx *init)
{
	if (keycode == ESC)
		exit(0);
	if (keycode == ZOOM_IN)
		init->step *= 1.1;
	if (keycode == ZOOM_OUT)
		init->step *= 0.9;
	if (keycode == X_UP)
		init->xa = fmod((init->xa + 1.1), 360);
	if (keycode == X_DOWN)
		init->xa = fmod((init->xa - 0.9), 360);
	if (keycode == Y_UP)
		init->ya = fmod((init->ya + 1.1), 360);
	if (keycode == Y_DOWN)
		init->ya = fmod((init->ya - 0.9), 360);
	ft_redraw(init);
	return (0);
}

void	ft_init_mlx(t_fdfmlx **tmp)
{
	t_fdfmlx *init;

	init = (t_fdfmlx *)ft_memalloc(sizeof(t_fdfmlx));
	init->mlx = mlx_init();
	ft_init_win(init);
	init->step = 10.0;
	init->xa = 22;
	init->ya = 31;
	init->za = 25;
	init->minheight = INT_MAX;
	init->maxheight = INT_MIN;
	init->l = NULL;
	*tmp = init;
}

int		main(int ac, char **av)
{
	t_fdfmlx	*init;
	int			fd;
	t_fdflst	*lst;

	if (ac != 2)
		ft_error_handle(AC_NUM);
	if ((fd = open(av[1], O_RDONLY)) < 3)
		ft_error_handle(FD);
	lst = NULL;
	init = NULL;
	ft_init_mlx(&init);
	ft_fdfread(fd, &lst, init);
	init->step = 10.0;
	ft_zoom(init);
	ft_drawmap(lst, init);
	return (0);
}
