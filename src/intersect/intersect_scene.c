/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:38:20 by adippena          #+#    #+#             */
/*   Updated: 2016/08/18 15:01:24 by rojones          ###   ########.fr       */
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
		//printf("intersect scene called with rayloc %f %f %f dir %f %f %f\n",e->ray.loc.x, e->ray.loc.y, e->ray.loc.z, e->ray.dir.x, e->ray.dir.y, e->ray.dir.z);

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
	{

		if (intersect_prim(e, &e->ray, prim, &t) && t < e->t)
		{
			e->t = t;
			e->p_hit = e->prim[prim];
			e->hit_type = PRIMITIVE;

			t_vector p;
			p = vadd(e->ray.loc, vmult(e->ray.dir, t));
		//	printf("hit prim at %f %f %f \n", p.x, p.y, p.z);
		}
		else
			;
		//	puts("missed prim");
	}
	while (object--)
		if (intersect_box(&e->ray, e->object[object]->box))
			intersect_object(e, e->object[object], &t);
}
