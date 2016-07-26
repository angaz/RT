/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_plane.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:37:04 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 17:24:52 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersect_plane(t_ray *r, t_object *o, double *t)
{
	double	denominator;
	double	numerator;
	double	t0;

	if ((denominator = vector_dot(r->dir, o->normal)) == 0)
		return (0);
	numerator = vector_dot(o->loc, o->normal) - vector_dot(r->loc, o->normal);
	t0 = numerator / denominator;
	if (t0 > 0.00001 && t0 < *t)
	{
		*t = t0;
		return (1);
	}
	return (0);
}
