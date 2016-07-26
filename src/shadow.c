/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:47:45 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 16:07:44 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		in_shadow(t_env *e, t_light *light)
{
	t_ray		ray;
	double		t;
	double		delta;
	double		distance;
	size_t		object;

	t = INFINITY;
	ray.loc = vector_add(e->ray.loc, vector_mult(e->ray.dir, e->t));
	delta = vector_normalize(ray.loc);
	ray.dir = vector_sub(light->loc, ray.loc);
	distance = vector_normalize(ray.dir);
	ray.dir = vector_unit(ray.dir);
	object = 0;
	while (object < e->objects)
		if (intersect_object(e, &ray, object, &t) && t < delta && t < distance)
			return (0.0);
		else
			++object;
	return (1.0);
}
