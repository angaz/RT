/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_scene.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:38:20 by adippena          #+#    #+#             */
/*   Updated: 2016/08/08 16:21:02 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int			intersect_object(t_env *e, t_ray *ray, size_t object, double *t)
{
	if (e->object[object]->type == OBJ_SPHERE)
		return (intersect_sphere(ray, e->object[object], t));
	if (e->object[object]->type == OBJ_PLANE)
		return (intersect_plane(ray, e->object[object], t));
	if (e->object[object]->type == OBJ_CYLINDER)
		return (intersect_cylinder(ray, e->object[object], t));
	if (e->object[object]->type == OBJ_CONE)
		return (intersect_cone(ray, e->object[object], t));
	if (e->object[object]->type == OBJ_TRIANGLE)
		return (intersect_triangle(ray, e->object[object], t));
	return (0);
}

void		intersect_scene(t_env *e)
{
	double		min_dist;
	double		t;
	size_t		object_no;
	t_object	*hit;

	min_dist = INFINITY;
	t = INFINITY;
	hit = NULL;
	object_no = 0;
	while (object_no < e->objects)
	{
		if (intersect_object(e, &e->ray, object_no, &t) && t < min_dist)
		{
			min_dist = t;
			hit = e->object[object_no];
		}
		++object_no;
	}
	e->t = min_dist;
	e->hit = hit;
}
