/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rtv1.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 19:03:08 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 20:52:13 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RTV1_H
# define RTV1_H

# include "libft.h"
# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include <fcntl.h>
# include <stdbool.h>

# define W 800
# define H 800
# define ASPR (W / H)
# define W_MOVE (W - 1) * 0.5
# define H_MOVE (H - 1) * 0.5
# define ESC 53
# define OBJNUM 8
# define LIGHTNUM 2
# define RAY_T_MIN 0.0001
# define RAY_T_MAX 1.0e30
# define PI 3.14159265

typedef enum		e_codes
{
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	USAGE
}					t_codes;

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

typedef double		t_vector __attribute__((vector_size(sizeof(double)*3)));

typedef union		u_rgb
{
	unsigned int	color;
	unsigned char	c[4];
}					t_rgb;

/*
** coef  plays radius for sphere/cylinder and angle for cone
** axis plays vertex for cone/cylinder and normal for plane
*/

typedef	struct		s_obj
{
	int				visible;
	int				shape;
	t_vector		pos;
	t_vector		axis;
	double			coef;
	t_rgb			clr;
}					t_obj;

typedef struct		s_cam
{
	t_vector		pos;
	t_vector		dir;
	t_vector		rot;
	double			angle;
	double			t;
}					t_cam;

typedef struct		s_l
{
	int				visible;
	t_vector		pos;
	double			intensity;
}					t_light;

typedef struct		s_hit
{
	t_vector		phit;
	t_vector		nhit;
	t_rgb			clr;
	t_obj			obj;
	int				shape;
	t_vector		obj_pos;
}					t_hit;

typedef struct		s_math
{
	double			a;
	double			b;
	double			c;
	double			discr;
	t_vector		dist;
	double			t1;
	double			t2;
}					t_math;

typedef struct		s_scene
{
	int				id;
	t_cam			cam;
	t_obj			obj[OBJNUM];
	t_light			l[LIGHTNUM];
	t_hit			hit;
}					t_scene;

void				ft_create_sphere(t_scene *scene, t_mlx *mlx);
int					ft_inter_sphere(t_cam *cam, t_obj *sph, t_hit *hit, bool w);
void				ft_create_plane(t_scene *scene, t_mlx *mlx);
int					ft_inter_plane(t_cam *cam, t_obj *pln, t_hit *hit, bool w);
void				ft_create_cone(t_scene *scene, t_mlx *mlx);
int					ft_inter_cone(t_cam *cam, t_obj *cone, t_hit *hit, bool w);
void				ft_create_cylinder(t_scene *scene, t_mlx *mlx);
int					ft_inter_cylinder(t_cam *cam, t_obj *cyl, t_hit *hit,
																	bool w);
void				ft_create_triplet(t_scene *scene, t_mlx *mlx);
void				ft_create_mix(t_scene *scene, t_mlx *mlx);
double				length2(t_vector v);
double				length(t_vector v);
t_vector			vscale(double scale, t_vector v);
t_vector			normalv(t_vector v);
double				dot(t_vector v, t_vector u);
void				init_mlx(t_mlx *mlx);
void				ft_init_light_params(t_scene *scene);
void				ft_init_obj_params(t_scene *scene);
t_cam				ft_init_cam(void);
void				ft_rot_x(t_cam *cam);
void				ft_rot_y(t_cam *cam);
void				ft_rot_z(t_cam *cam);
void				ft_iterate_screen(t_scene *scene, t_mlx *mlx);
int					ft_intersection(t_scene *scene, t_cam *cam, bool write);
int					ft_check_light_src(t_scene *scene, t_hit *hit, t_cam *cam);
t_vector			ft_find_nhit(t_hit *hit);
void				ft_set_ray(t_cam *cam, int x, int y);
double				ft_find_light_coef(t_scene *scene, t_vector dist,
																t_hit *hit);
int					ft_pixel_color(t_rgb clr, double coef);
void				ft_put_pixel(t_mlx *mlx, int x, int y, int color);
#endif
