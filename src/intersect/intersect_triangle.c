/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 14:57:03 by adippena          #+#    #+#             */
/*   Updated: 2016/08/22 20:50:22 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intersect_triangle.h"

/*
** https://en.wikipedia.org/wiki/Möller–Trumbore_intersection_algorithm
** Möller–Trumbore ray-triangle intersection algorithm
*/

int		intersect_triangle(t_ray *r, t_face *f, double *t)
{
	t_intersect_triangle	it;

	it.edge1 = vsub(*f->v1, *f->v0);
	it.edge2 = vsub(*f->v2, *f->v0);
	it.p = vcross(r->dir, it.edge2);
	it.d = vdot(it.edge1, it.p);
	if (it.d > -DBL_EPSILON && it.d < DBL_EPSILON)
		return (0);
	it.inverse_d = 1.0 / it.d;
	it.dist = vsub(r->loc, *f->v0);
	it.u = vdot(it.dist, it.p) * it.inverse_d;
	if (it.u < 0.0 || it.u > 1.0)
		return (0);
	it.q = vcross(it.dist, it.edge1);
	it.v = vdot(r->dir, it.q) * it.inverse_d;
	if (it.v < 0.0 || it.u + it.v > 1.0)
		return (0);
	it.t0 = vdot(it.edge2, it.q) * it.inverse_d;
	if (it.t0 > DBL_EPSILON)
	{
		*t = it.t0;
		return (1);
	}
	return (0);
}
