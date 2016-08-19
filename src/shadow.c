/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:47:45 by adippena          #+#    #+#             */
/*   Updated: 2016/08/19 17:54:30 by arnovan-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		in_shadow(t_env *e, t_light *light)
{
	t_ray		ray;
	double		t;
	double		distance;
	size_t		prim;
	size_t		face;
	size_t		object;
	t_object	*o;

	t = INFINITY;
	ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	ray.dir = vsub(light->loc, ray.loc);
	distance = vnormalize(ray.dir);
	ray.dir = vunit(ray.dir);
	prim = e->prims;
	object = e->objects;
	while (prim--)
		if (intersect_prim(e, &ray, prim, &t) && t < distance)
			return (1);
	while (object--)
	{
		o = e->object[object];
		if (intersect_box(&ray, o->box))
		{
			face = o->faces;
			while (face--)
				if (intersect_triangle(&ray, o->face[face], &t) && t < distance)
					return (1);
		}
	}
	return (0);
}
