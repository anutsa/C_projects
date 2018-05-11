/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/22 17:01:00 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/23 22:03:23 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf.h"

void	ft_init_img(t_mlx *mlx)
{
	mlx->img = mlx_new_image(mlx->mlx, W, H);
	mlx->bpp = 0;
	mlx->sizeline = 0;
	mlx->endian = 0;
	mlx->str = mlx_get_data_addr(mlx->img, &(mlx->bpp),
						&(mlx->sizeline), &(mlx->endian));
	mlx->istr = (int *)mlx->str;
}

int		ft_loop_hook(t_e *e)
{
	ft_draw_img(&e->mlx, e);
	return (0);
}

void	ft_init_mlx(t_mlx *mlx)
{
	mlx->mlx = mlx_init();
	mlx->win = mlx_new_window(mlx->mlx, W, H, "wolf3d");
}

void	ft_init_params(t_e *e)
{
	e->cam.pos_x = 22;
	e->cam.pos_y = 12;
	e->cam.dir_x = -1;
	e->cam.dir_y = 0;
	e->cam.pln_x = 0;
	e->cam.pln_y = 0.66;
	e->keys.fwd = 0;
	e->keys.bwd = 0;
	e->keys.right = 0;
	e->keys.left = 0;
	e->keys.rot_right = 0;
	e->keys.rot_left = 0;
	e->keys.music = 0;
	e->redraw = 0;
	ft_generate_map(e);
}

int		main(void)
{
	t_e	e;

	ft_init_params(&e);
	ft_init_mlx(&e.mlx);
	ft_help();
	mlx_hook(e.mlx.win, 2, 1 << 7, ft_key_press, &e);
	mlx_hook(e.mlx.win, 3, 1 << 7, ft_key_release, &e);
	mlx_hook(e.mlx.win, 17, 1L << 17, exit_mouse, &e);
	mlx_loop_hook(e.mlx.mlx, ft_loop_hook, &e);
	mlx_loop(&e.mlx);
	return (0);
}
