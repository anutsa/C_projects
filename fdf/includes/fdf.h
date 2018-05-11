/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 13:24:03 by anutsa            #+#    #+#             */
/*   Updated: 2017/07/10 16:19:59 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <limits.h>

# define PI 3.14159265
# define W_WIDTH 1000
# define W_HEIGHT 800
# define WHITE 0xFFFFFF
# define ZOOM(screen, obj) (screen) * 3. / 4. / (obj)

# define Y_UP 124
# define Y_DOWN 123
# define X_UP 126
# define X_DOWN 125
# define ZOOM_IN 69
# define ZOOM_OUT 78
# define ESC 53

typedef	enum		e_error_codes
{
	AC_NUM,
	FD,
	WIDTH,
	COLOR,
	EMPTY_MAP,
	BAD_SYM
}					t_error_codes;

typedef struct		s_bresenham
{
	int				x;
	int				y;
	int				sx;
	int				sy;
	int				dx;
	int				dy;
	int				err;
	int				e2;
}					t_bres;

typedef struct		s_lst
{
	double			x;
	double			y;
	double			z;
	double			x0;
	double			y0;
	double			z0;
	double			step;
	int				color;
	struct s_lst	*next;
	struct s_lst	*down;
}					t_fdflst;

typedef struct		s_fdfmlx
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*str;
	int				bpp;
	int				sizeline;
	int				endian;
	t_fdflst		*l;
	double			xa;
	double			ya;
	double			za;
	double			step;
	int				minheight;
	int				maxheight;
	double			width;
	double			height;
}					t_fdfmlx;

void				ft_valid_ac(int ac);
void				ft_valid_line(char **split);
void				ft_init_mlx(t_fdfmlx **tmp);
int					ft_fdfread(int fd, t_fdflst **lst, t_fdfmlx *init);
void				ft_lstpb(t_fdflst **lst, double x, double y, char *str);
void				ft_movecoordinates(t_fdflst *lst,
										double width, double height);
void				ft_scale(t_fdflst *lst, t_fdfmlx *init);
void				ft_drawmap(t_fdflst *lst, t_fdfmlx *init);
void				ft_check(t_fdflst *lst);
int					ft_get_color_num(char *s);
void				ft_movecoordinates(t_fdflst *lst,
										double width, double height);
void				ft_rx(t_fdflst *lst, int ang);
void				ft_ry(t_fdflst *lst, int ang);
void				ft_rz(t_fdflst *lst, int ang);
void				ft_get_projection(t_fdflst *lst, t_fdfmlx *init);
int					my_key_funct(int keycode, t_fdfmlx *init);
void				ft_error_handle(t_error_codes code);
int					exit_mouse(t_fdfmlx *init);
void				ft_zoom(t_fdfmlx *init);
#endif
