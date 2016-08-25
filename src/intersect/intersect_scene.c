/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:38:20 by adippena          #+#    #+#             */
/*   Updated: 2016/08/22 20:50:02 by adippena         ###   ########.fr       */
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
	if (e->prim[prim]->type == PRIM_DISK)
		return (intersect_disk(ray, e->prim[prim], t));
	return (0);
}

void		intersect_scene(t_env *e)
{
	int			inter;
	double		t;
	size_t		prim;
	size_t		object;

	e->t = INFINITY;
	e->p_hit = NULL;
	e->o_hit = NULL;
	e->hit_type = 0;
	prim = e->prims;
	object = e->objects;
	while (prim--)
		if ((inter = intersect_prim(e, &e->ray, prim, &t)) && t < e->t)
		{
			e->ray.inter = inter;
			e->t = t;
			e->p_hit = e->prim[prim];
			e->hit_type = PRIMITIVE;
		}
	while (object--)
		if (intersect_box(&e->ray, e->object[object]->box))
			intersect_object(e, e->object[object], &t);
}
