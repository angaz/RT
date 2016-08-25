/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_object.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/14 11:36:29 by adippena          #+#    #+#             */
/*   Updated: 2016/08/22 20:49:54 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

int		intersect_object(t_env *e, t_object *o, double *t)
{
	size_t	face;
	int		hit;

	face = o->faces;
	hit = 0;
	while (face--)
		if (intersect_triangle(&e->ray, o->face[face], t) && *t < e->t)
		{
			e->t = *t;
			e->o_hit = o->face[face];
			e->object_hit = o;
			e->hit_type = FACE;
			hit = 1;
		}
	return (hit);
}
