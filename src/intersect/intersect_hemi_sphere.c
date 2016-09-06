/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_hemi_sphere.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/01 09:55:11 by rojones           #+#    #+#             */
/*   Updated: 2016/09/02 16:29:33 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	check_lim(t_ray *r, t_prim *o, double *t, double *t_test)
{
	t_vector	ph;

	ph = vadd(r->loc, vmult(r->dir, *t_test));
	if (vdot(o->dir, vsub(ph, o->loc)) <= 0)
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
		if (check_lim(r, o, t, &tc))
			return (1);
	tc = (tc == t1) ? t0 : t1;
	if (tc > EPSILON)
		if (check_lim(r, o, t, &tc))
			return (2);
	return (0);
}

int			intersect_hemi_sphere(t_ray *r, t_prim *o, double *t)
{
	t_quad		quad;
	int			inter;
	t_vector	dist;

	dist = vsub(r->loc, o->loc);
	quad.a = vdot(r->dir, r->dir);
	quad.b = 2.0 * vdot(r->dir, dist);
	quad.c = vdot(dist, dist) - (o->radius * o->radius);
	quad.discr = quad.b * quad.b - 4.0 * quad.a * quad.c;
	if (quad.discr < EPSILON)
		return (0);
	inter = find_t(&quad, t, o, r);
	return (inter);
}
