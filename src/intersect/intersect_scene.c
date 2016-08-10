/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:38:20 by adippena          #+#    #+#             */
/*   Updated: 2016/08/10 11:39:20 by adippena         ###   ########.fr       */
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
	double		min_dist;
	double		t;
	size_t		prim_no;
	t_prim		*hit;

	min_dist = INFINITY;
	t = INFINITY;
	hit = NULL;
	prim_no = 0;
	while (prim_no < e->prims)
	{
		if (intersect_prim(e, &e->ray, prim_no, &t) && t < min_dist)
		{
			min_dist = t;
			hit = e->prim[prim_no];
		}
		++prim_no;
	}
	e->t = min_dist;
	e->p_hit = hit;
}
