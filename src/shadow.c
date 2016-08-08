/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:47:45 by adippena          #+#    #+#             */
/*   Updated: 2016/08/09 01:27:46 by adippena         ###   ########.fr       */
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

	t = INFINITY;
	ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	delta = vnormalize(ray.loc);
	ray.dir = vsub(light->loc, ray.loc);
	distance = vnormalize(ray.dir);
	ray.dir = vunit(ray.dir);
	prim = 0;
	while (prim < e->prims)
		if (intersect_prim(e, &ray, prim, &t) && t < delta && t < distance)
			return (0);
		else
			++prim;
	return (1);
}
