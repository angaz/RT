/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:38:20 by adippena          #+#    #+#             */
/*   Updated: 2016/08/11 22:11:44 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			intersect_prim(t_env *e, t_ray *ray, size_t prim, double *t)
{
	if (e->prim[prim]->type == PRIM_SPHERE)
		return (intersect_sphere(ray, e->prim[prim], t));
	if (e->prim[prim]->type == PRIM_PLANE)
		return (intersect_plane(ray, e->prim[prim], t));
	if (e->prim[prim]->type == PRIM_CYLINDER)
		return (intersect_cylinder(ray, e->prim[prim], t));
	if (e->prim[prim]->type == PRIM_CONE)
		return (intersect_cone(ray, e->prim[prim], t));
	return (0);
}

void		intersect_scene(t_env *e)
{
	double		t;
	size_t		prim;
	size_t		face;
	size_t		object;
	t_object	*o;

	e->t = INFINITY;
	e->p_hit = NULL;
	e->o_hit = NULL;
	e->hit_type = -1;
	prim = 0;
	object = 0;
	while (prim < e->prims)
	{
		if (intersect_prim(e, &e->ray, prim, &t) && t < e->t)
		{
			e->t = t;
			e->p_hit = e->prim[prim];
			e->hit_type = PRIMITIVE;
		}
		++prim;
	}
	while (object < e->objects)
	{
		o = e->object[object];
		if (intersect_box(&e->ray, o->box))
		{
			face = 0;
			while (face < o->faces)
			{
				if (intersect_triangle(&e->ray, o->face[face], &t) && t < e->t)
				{
					e->t = t;
					e->o_hit = o->face[face];
					e->o_hit_index = object;
					e->hit_type = FACE;
				}
				++face;
			}
		}
		++object;
	}
}
