/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:21:58 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/27 20:22:16 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf.h"

void	ft_move_fwd_bwd(t_keys *keys, t_cam *cam, t_e *e)
{
	double	move_x;
	double	move_y;

	move_x = cam->dir_x * 0.16;
	move_y = cam->dir_y * 0.16;
	if (keys->fwd)
	{
		if (FREE(CELL_AT((int)(cam->pos_x + move_x), (int)(cam->pos_y))))
			cam->pos_x += move_x;
		if (FREE(CELL_AT((int)cam->pos_x, (int)(cam->pos_y + move_y))))
			cam->pos_y += move_y;
	}
	else if (keys->bwd)
	{
		if (FREE(CELL_AT((int)(cam->pos_x - move_x), (int)cam->pos_y)))
			cam->pos_x -= move_x;
		if (FREE(CELL_AT((int)cam->pos_x, (int)(cam->pos_y - move_y))))
			cam->pos_y -= move_y;
	}
}

void	ft_rotate(t_cam *cam, int way)
{
	double	dir_x;
	double	pln_x;
	double	cosa;
	double	sina;

	dir_x = cam->dir_x;
	pln_x = cam->pln_x;
	cosa = cos(0.016 * way);
	sina = sin(0.016 * way);
	cam->dir_x = dir_x * cosa - cam->dir_y * sina;
	cam->dir_y = dir_x * sina + cam->dir_y * cosa;
	cam->pln_x = pln_x * cosa - cam->pln_y * sina;
	cam->pln_y = pln_x * sina + cam->pln_y * cosa;
}

void	ft_move_left_right(t_keys *keys, t_cam *cam, t_e *e)
{
	double	move_x;
	double	move_y;

	move_x = cam->pln_x * 0.16;
	move_y = cam->pln_y * 0.16;
	if (keys->right)
	{
		if (FREE(CELL_AT((int)(cam->pos_x + move_x), (int)(cam->pos_y))))
			cam->pos_x += move_x;
		if (FREE(CELL_AT((int)cam->pos_x, (int)(cam->pos_y + move_y))))
			cam->pos_y += move_y;
	}
	else if (keys->left)
	{
		if (FREE(CELL_AT((int)(cam->pos_x - move_x), (int)cam->pos_y)))
			cam->pos_x -= move_x;
		if (FREE(CELL_AT((int)cam->pos_x, (int)(cam->pos_y - move_y))))
			cam->pos_y -= move_y;
	}
	if (keys->rot_right)
		ft_rotate(cam, -1);
	else if (keys->rot_left)
		ft_rotate(cam, 1);
}
