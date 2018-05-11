/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 18:06:03 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/25 18:06:05 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf.h"

void	ft_switch_key_status(int key, t_e *e, int swap)
{
	key == FWD ? e->keys.fwd = swap : 0;
	key == BWD ? e->keys.bwd = swap : 0;
	key == RIGHT ? e->keys.right = swap : 0;
	key == LEFT ? e->keys.left = swap : 0;
	key == ARR_RIGHT ? e->keys.rot_right = swap : 0;
	key == ARR_LEFT ? e->keys.rot_left = swap : 0;
}

int		ft_key_release(int keycode, t_e *e)
{
	ft_switch_key_status(keycode, e, 0);
	return (0);
}

void	ft_open_doors(t_map *map, t_cam *cam)
{
	int		x;
	int		y;

	x = (int)(cam->pos_x + cam->dir_x);
	y = (int)(cam->pos_y + cam->dir_y);
	if (map->map[y][x] == 2)
		map->map[y][x] = 3;
	else if (map->map[y][x] == 3)
		map->map[y][x] = 2;
}

int		ft_key_press(int keycode, t_e *e)
{
	t_e *env;

	env = e;
	if (keycode == ESC)
	{
		ft_stop_music();
		exit(0);
	}
	else if (keycode == OPEN)
	{
		ft_open_doors(&e->map, &e->cam);
		ft_draw_img(&e->mlx, e);
	}
	else if (keycode == PLAY)
		ft_play_music();
	else if (keycode == STOP)
		ft_stop_music();
	else
		ft_switch_key_status(keycode, e, 1);
	return (0);
}

int		exit_mouse(t_e *e)
{
	ft_stop_music();
	mlx_destroy_window(e->mlx.mlx, e->mlx.win);
	exit(0);
	return (0);
}
