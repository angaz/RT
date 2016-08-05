/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:47:45 by adippena          #+#    #+#             */
/*   Updated: 2016/08/05 10:15:24 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		in_shadow(t_env *e, t_light *light)
{
	t_ray		ray;
	double		t;
	double		delta;
	double		distance;
	size_t		object;

	t = INFINITY;
	ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	delta = vnormalize(ray.loc);
	ray.dir = vsub(light->loc, ray.loc);
	distance = vnormalize(ray.dir);
	ray.dir = vunit(ray.dir);
	object = 0;
	while (object < e->objects)
		if (intersect_object(e, &ray, object, &t) && t < delta && t < distance)
			return (0);
		else
			++object;
	return (1);
}
