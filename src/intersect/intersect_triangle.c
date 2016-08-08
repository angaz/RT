/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 14:57:03 by adippena          #+#    #+#             */
/*   Updated: 2016/08/08 16:10:04 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** https://en.wikipedia.org/wiki/Möller–Trumbore_intersection_algorithm
** Möller–Trumbore ray-triangle intersection algorithm
*/

int		intersect_triangle(t_ray *r, t_object *o, double *s)
{
	t_vector	edge1;
	t_vector	edge2;
	t_vector	p;
	t_vector	q;
	t_vector	dist;
	double		d;
	double		inverse_d;
	double		u;
	double		v;
	double		t0;

	edge1 = vsub(o->p2, o->p1);
	edge2 = vsub(o->p3, o->p1);
	p = vcross(r->dir, edge2);
	d = vdot(edge1, p);
	if (d > -EPSILON && d < EPSILON)
		return (0);
	inverse_d = 1.0 / d;
	dist = vsub(r->loc, o->p1);
	u = vdot(dist, p) * inverse_d;
	if (u < EPSILON || u > 1.0)
		return (0);
	q = vcross(dist, edge1);
	v = vdot(r->dir, q) * inverse_d;
	if (v < EPSILON || u + v > 1.0)
		return (0);
	t0 = vdot(edge2, q) * inverse_d;
	if (t0 > EPSILON)
	{
		*s = t0;
		return (1);
	}
	return (0);
}
