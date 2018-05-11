/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 20:44:42 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/27 20:44:56 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wlf.h"

void	ft_calculate_stripe(t_e *e, t_cam *cam, t_ray *ray, int x)
{
	if (e->side == 0)
		cam->walldist = (e->map.x - ray->pos_x + (1 - cam->step_x) / 2)
																/ ray->dir_x;
	else
		cam->walldist = (e->map.y - ray->pos_y + (1 - cam->step_y) / 2)
																/ ray->dir_y;
	e->line_h = H / cam->walldist;
	e->draw_start = -e->line_h / 2 + H / 2;
	if (e->draw_start < 0)
		e->draw_start = 0;
	e->draw_end = e->line_h / 2 + H / 2;
	if (e->draw_end >= H)
		e->draw_end = H - 1;
	ft_draw_stripe(e, &e->mlx, x);
}

int		ft_perform_dda(t_e *e, t_ray *ray, t_cam *cam, t_map *map)
{
	if (ray->side_dist_x < ray->side_dist_y)
	{
		ray->side_dist_x += ray->delta_x;
		map->x += cam->step_x;
		e->side = 0;
	}
	else
	{
		ray->side_dist_y += ray->delta_y;
		map->y += cam->step_y;
		e->side = 1;
	}
	if (!(FREE(map->map[map->y][map->x])))
		return (1);
	return (0);
}

void	ft_find_step_direction(t_cam *cam, t_ray *ray, t_map *map)
{
	if (ray->dir_x < 0)
	{
		cam->step_x = -1;
		ray->side_dist_x = (ray->pos_x - map->x) * ray->delta_x;
	}
	else
	{
		cam->step_x = 1;
		ray->side_dist_x = (map->x + 1.0 - ray->pos_x) * ray->delta_x;
	}
	if (ray->dir_y < 0)
	{
		cam->step_y = -1;
		ray->side_dist_y = (ray->pos_y - map->y) * ray->delta_y;
	}
	else
	{
		cam->step_y = 1;
		ray->side_dist_y = (map->y + 1.0 - ray->pos_y) * ray->delta_y;
	}
}

int		ft_set_ray(t_cam *cam, t_ray *ray, t_map *map, int x)
{
	cam->x = 2 * x / (double)W - 1;
	ray->pos_x = cam->pos_x;
	ray->pos_y = cam->pos_y;
	ray->dir_x = cam->dir_x + cam->pln_x * cam->x;
	ray->dir_y = cam->dir_y + cam->pln_y * cam->x;
	map->x = ray->pos_x;
	map->y = ray->pos_y;
	ray->delta_x = sqrt(1 + (ray->dir_y * ray->dir_y)
					/ (ray->dir_x * ray->dir_x));
	ray->delta_y = sqrt(1 + (ray->dir_x * ray->dir_x)
					/ (ray->dir_y * ray->dir_y));
	ft_find_step_direction(cam, ray, map);
	return (0);
}

void	ft_compute_ray_data(t_e *e)
{
	int x;

	x = -1;
	while (++x < W)
	{
		e->hit = ft_set_ray(&e->cam, &e->ray, &e->map, x);
		while (!e->hit)
			e->hit = ft_perform_dda(e, &e->ray, &e->cam, &e->map);
		ft_calculate_stripe(e, &e->cam, &e->ray, x);
	}
	ft_move_fwd_bwd(&e->keys, &e->cam, e);
	ft_move_left_right(&e->keys, &e->cam, e);
}
