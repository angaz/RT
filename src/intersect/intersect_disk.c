/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disk.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/15 08:44:50 by rojones           #+#    #+#             */
/*   Updated: 2016/08/19 10:04:27 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersect_disk(t_ray *r, t_prim *o, double *t)
{
	t_vector	point;
	double		denominator;
	double	numerator;
	double	t0;

	if ((denominator = vdot(r->dir, o->normal)) == 0)
		return (0);
	numerator = vdot(o->loc, o->normal) - vdot(r->loc, o->normal);
	t0 = numerator / denominator;
	if (t0 > EPSILON)
	{
		point = vadd(r->loc, vmult(r->dir, t0));
		if (vnormalize(vsub(point, o->loc)) <= o->radius)
		{
			*t = t0;
			return (1);
		}
		return (0);
	}
	return (0);
}
