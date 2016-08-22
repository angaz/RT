/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_intersection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:00:52 by adippena          #+#    #+#             */
/*   Updated: 2016/08/19 16:44:09 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	find_t(double a, double b, double discr, double *t)
{
	double	sqrt_discr;
	double	t0;
	double	t1;
	double	tc;

	sqrt_discr = sqrt(discr);
	t0 = (-b + sqrt_discr) / (2.0 * a);
	t1 = (-b - sqrt_discr) / (2.0 * a);
	tc = (t0 > t1) ? t1 : t0;
	if (tc > EPSILON)
	{
		*t = tc;
		return (1);
	}
	else
	{
		tc = (tc == t1) ? t0 : t1;
		if (tc > EPSILON)
		{
			*t = tc;
			return (2);
		}
	}
	return (0);
}

int			intersect_sphere(t_ray *r, t_prim *o, double *t)
{
	double		a;
	double		b;
	double		c;
	double		discr;
	t_vector	dist;

	dist = vsub(r->loc, o->loc);
	a = vdot(r->dir, r->dir);
	b = 2.0 * vdot(r->dir, dist);
	c = vdot(dist, dist) - (o->radius * o->radius);
	discr = b * b - 4.0 * a * c;
	if (discr < EPSILON)
		return (0);
	return (find_t(a, b, discr, t));
}
