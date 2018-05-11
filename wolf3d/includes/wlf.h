/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wlf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 21:00:49 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/23 22:03:26 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WLF_H
# define WLF_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

# define W 1000
# define H 800
# define MAP_W 24
# define MAP_H 24
# define ESC 53
# define FWD 13
# define BWD 1
# define RIGHT 2
# define LEFT 0
# define ARR_RIGHT 124
# define ARR_LEFT 123
# define OPEN 14
# define PLAY 23
# define STOP 22
# define RED 0xFF1500
# define BLUE 0x00BFFF
# define ORANGE 0xFF8400
# define GREEN 0x00FF8C
# define SKYBLUE 0x87CEEB
# define SADDLEBROWN 0x8B4513
# define DOORS 2
# define CELL_AT(x, y) e->map.map[y][x]
# define FREE(x) ((x) == 0 || (x) == 3) ? 1 : 0

typedef struct		s_mlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*str;
	int				*istr;
	int				bpp;
	int				sizeline;
	int				endian;
}					t_mlx;

typedef union		u_rgb
{
	unsigned int	color;
	unsigned char	c[4];
}					t_rgb;

typedef struct		s_ray
{
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			side_dist_x;
	double			side_dist_y;
	double			delta_x;
	double			delta_y;
}					t_ray;

typedef struct		s_map
{
	int				map[H][W];
	int				x;
	int				y;
}					t_map;

typedef struct		s_cam
{
	double			x;
	double			pos_x;
	double			pos_y;
	double			dir_x;
	double			dir_y;
	double			pln_x;
	double			pln_y;
	int				step_x;
	int				step_y;
	double			walldist;
}					t_cam;

typedef struct		s_keys
{
	int				fwd;
	int				bwd;
	int				right;
	int				left;
	int				rot_right;
	int				rot_left;
	int				music;
}					t_keys;

typedef struct		s_e
{
	t_mlx			mlx;
	t_cam			cam;
	t_ray			ray;
	t_map			map;
	t_keys			keys;
	t_rgb			color;
	int				line_h;
	int				draw_start;
	int				draw_end;
	int				hit;
	int				side;
	int				redraw;
}					t_e;

void				ft_help(void);
void				ft_init_img(t_mlx *mlx);
void				ft_generate_map(t_e *e);
void				ft_compute_ray_data(t_e *e);
void				ft_init_keys(t_keys *keys);
int					ft_key_press(int keycode, t_e *e);
int					ft_key_release(int keycode, t_e *e);
void				ft_draw_img(t_mlx *mlx, t_e *e);
void				ft_move_fwd_bwd(t_keys *keys, t_cam *cam, t_e *e);
void				ft_move_left_right(t_keys *keys, t_cam *cam, t_e *e);
void				ft_draw_stripe(t_e *e, t_mlx *mlx, int x);
void				ft_play_music(void);
void				ft_stop_music(void);
int					exit_mouse(t_e *e);
#endif
