/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:47:45 by adippena          #+#    #+#             */
/*   Updated: 2016/08/10 22:48:28 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		in_shadow(t_env *e, t_light *light)
{
	t_ray		ray;
	double		t;
	double		delta;
	double		distance;
	size_t		prim;
	size_t		face;
	size_t		object;
	t_object	*o;

	t = INFINITY;
	ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	delta = vnormalize(ray.loc);
	ray.dir = vsub(light->loc, ray.loc);
	distance = vnormalize(ray.dir);
	ray.dir = vunit(ray.dir);
	prim = 0;
	object = 0;
	while (prim < e->prims)
		if (intersect_prim(e, &ray, prim, &t) && t < delta && t < distance)
			return (0);
		else
			++prim;
	while (object < e->objects)
	{
		face = 0;
		o = e->object[object];
		while (face < o->faces)
			if (intersect_triangle(&ray, o->face[face], &t) && t < delta && t < distance)
				return (0);
			else
				++face;
		++object;
	}
	return (1);
}
