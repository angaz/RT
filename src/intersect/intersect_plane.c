/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:37:04 by adippena          #+#    #+#             */
/*   Updated: 2016/08/22 20:50:00 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersect_plane(t_ray *r, t_prim *o, double *t)
{
	double	denominator;
	double	numerator;
	double	t0;

	if ((denominator = vdot(r->dir, o->normal)) == 0)
		return (0);
	numerator = vdot(o->loc, o->normal) - vdot(r->loc, o->normal);
	t0 = numerator / denominator;
	if (t0 > EPSILON)
	{
		*t = t0;
		return (1);
	}
	return (0);
}
