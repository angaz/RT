/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/14 22:44:25 by adippena          #+#    #+#             */
/*   Updated: 2016/08/20 13:05:17 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_cylinder.h"

static int	check_lim(t_ray *r, t_prim *o, double *t, double *t_test)
{
	t_vector	p1;
	t_vector	p2;
	t_vector	ph;

	ph = vadd(r->loc, vmult(r->dir, *t_test));
	p1 = vadd(o->loc, vmult(o->dir, o->limit));
	p2 = vadd(o->loc, vmult(o->dir, -o->limit));
	if (vdot(o->dir, vsub(ph, p1)) <= 0 && vdot(o->dir, vsub(ph, p2)) >= 0)
	{
		*t = *t_test;
		return (1);
	}
	return (0);
}

static int	check_t(t_ray *r, t_prim *o, double *t, double *t_test)
{
	if (o->limit != -1)
	{
		if (check_lim(r, o, t, t_test))
			return (1);
	}
	else
	{
		*t = *t_test;
		return (1);
	}
	return (0);
}

static int	find_t(t_quad *quad, double *t, t_prim *o, t_ray *r)
{
	double	sqrt_discr;
	double	t0;
	double	t1;
	double	tc;

	sqrt_discr = sqrt(quad->discr);
	t0 = (-quad->b + sqrt_discr) / (2.0 * quad->a);
	t1 = (-quad->b - sqrt_discr) / (2.0 * quad->a);
	tc = (t0 > t1) ? t1 : t0;
	if (tc > EPSILON)
	{
		if (check_t(r, o, t, &tc))
			return (1);
	}
	tc = (tc == t1) ? t0 : t1;
	if (tc > EPSILON)
	{
		if (check_t(r, o, t, &tc))
			return (2);
	}
	return (0);
}

int			intersect_cylinder(t_ray *r, t_prim *o, double *t)
{
	t_int_cylinder	c;

	c.dist = vsub(r->loc, o->loc);
	c.a_v = vsub(r->dir, vmult(o->dir, vdot(r->dir, o->dir)));
	c.c_v = vsub(c.dist, (vmult(o->dir, vdot(c.dist, o->dir))));
	c.quad.a = vdot(c.a_v, c.a_v);
	c.quad.b = 2.0 * vdot(c.a_v, c.c_v);
	c.quad.c = vdot(c.c_v, c.c_v) - (o->radius * o->radius);
	c.quad.discr = c.quad.b * c.quad.b - 4.0 * c.quad.a * c.quad.c;
	if (c.quad.discr < EPSILON)
		return (0);
	return (find_t(&c.quad, t, o, r));
}
