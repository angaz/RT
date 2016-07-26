/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 22:44:25 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 17:24:42 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_cylinder.h"

static int	find_t(double a, double b, double discr, double *t)
{
	double	sqrt_discr;
	double	t0;
	double	t1;

	sqrt_discr = sqrt(discr);
	t0 = (-b + sqrt_discr) / (2.0 * a);
	t1 = (-b - sqrt_discr) / (2.0 * a);
	if (t0 > t1)
		t0 = t1;
	if (t0 > 0.00001 && t0 < *t)
	{
		*t = t0;
		return (1);
	}
	return (0);
}

int			intersect_cylinder(t_ray *r, t_object *o, double *t)
{
	t_int_cylinder	c;

	c.dist = vector_sub(r->loc, o->loc);
	c.a_v = vector_sub(r->dir, vector_mult(o->dir, vector_dot(r->dir, o->dir)));
	c.c_v = vector_sub(
		c.dist, (vector_mult(o->dir, vector_dot(c.dist, o->dir))));
	c.a = vector_dot(c.a_v, c.a_v);
	c.b = 2.0 * vector_dot(c.a_v, c.c_v);
	c.c = vector_dot(c.c_v, c.c_v) - (o->radius * o->radius);
	c.d = c.b * c.b - 4.0 * c.a * c.c;
	if (c.d < 0.00001)
		return (0);
	return (find_t(c.a, c.b, c.d, t));
}
