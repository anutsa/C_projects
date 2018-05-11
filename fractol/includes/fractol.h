/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/11 19:19:00 by anutsa            #+#    #+#             */
/*   Updated: 2017/08/18 19:29:59 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <math.h>
# include <fcntl.h>
# include <stdio.h>

# define W_WIDTH 1000
# define W_HEIGHT 1000
# define ESC 53
# define MAX_ITER 255
# define RE_FACTOR(max_re, min_re) ((max_re) - (min_re)) / (W_WIDTH - 1)
# define IM_FACTOR(max_im, min_im) ((max_im) - (min_im)) / (W_HEIGHT - 1)
# define FABS(value) (((value) < 0) ? -(value) : (value))

typedef	enum		e_err_codes
{
	USAGE,
	MLX
}					t_err_codes;

typedef union		u_rgb
{
	unsigned int	color;
	unsigned char	c[4];
}					t_rgb;

typedef	struct		s_fract
{
	void			*mlx;
	void			*win;
	void			*img;
	char			name;
	char			*str;
	int				*istr;
	int				bpp;
	int				sizeline;
	int				endian;
	int				inout;
	int				monoch;
	double			zoom;
	double			move_x;
	double			move_y;
	double			rfreq;
	double			gfreq;
	double			bfreq;
	double			rphase;
	double			gphase;
	double			bphase;
	double			cr;
	double			ci;
	double			min_re;
	double			max_re;
	double			min_im;
	double			max_im;
	double			delta_x;
	double			delta_y;
}					t_fract;

typedef struct		s_threads
{
	t_fract			*cur;
	int				y;
}					t_threads;

void				ft_init_julia(void *mlx, t_fract *fr);
void				ft_init_mandelbrot(void *mlx, t_fract *fr);
void				ft_init_ship(void *mlx, t_fract *fr);
int					ft_get_mand_set(double cr, double ci);
int					ft_get_ship_set(double cr, double ci);
int					ft_get_julia_set(double zr, double zi, t_fract *julia);
void				ft_init_img(t_fract *f);
void				ft_event(t_fract *f);
int					ft_key(int keycode, t_fract *f);
int					ft_zoom(int key, int x, int y, t_fract *f);
#endif
