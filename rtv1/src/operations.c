/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anutsa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/27 13:12:30 by anutsa            #+#    #+#             */
/*   Updated: 2017/10/21 20:45:57 by anutsa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double		length2(t_vector v)
{
	double	res;

	v *= v;
	res = v[0] + v[1] + v[2];
	return (res);
}

double		length(t_vector v)
{
	double	l;

	l = length2(v);
	return (sqrt(l));
}

t_vector	normalv(t_vector v)
{
	double	l;

	l = length(v);
	v[0] /= l;
	v[1] /= l;
	v[2] /= l;
	return (v);
}

t_vector	vscale(double scale, t_vector v)
{
	v[0] *= scale;
	v[1] *= scale;
	v[2] *= scale;
	return (v);
}

double		dot(t_vector v, t_vector u)
{
	double		res;
	t_vector	c;

	c = v * u;
	res = (double)(c[0] + c[1] + c[2]);
	return (res);
}
