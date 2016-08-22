/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 23:47:45 by adippena          #+#    #+#             */
/*   Updated: 2016/08/20 10:53:57 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"
#include "in_shadow.h"

static void	init(t_in_shadow *var, t_env *e, t_light *light)
{
	var->t = INFINITY;
	var->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	var->ray.dir = vsub(light->loc, var->ray.loc);
	var->distance = vnormalize(var->ray.dir);
	var->ray.dir = vunit(var->ray.dir);
	var->prim = e->prims;
	var->object = e->objects;
}

int			in_shadow(t_env *e, t_light *light)
{
	t_in_shadow	var;

	init(&var, e, light);
	while (var.prim--)
	{
		if (intersect_prim(e, &var.ray, var.prim, &var.t) && var.t <
				var.distance)
			return (0);
	}
	while (var.object--)
	{
		var.o = e->object[var.object];
		if (intersect_box(&var.ray, var.o->box))
		{
			var.face = var.o->faces;
			while (var.face--)
				if (intersect_triangle(&var.ray, var.o->face[var.face], &var.t)
						&& var.t < var.distance)
					return (0);
		}
	}
	return (1);
}
