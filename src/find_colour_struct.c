/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colour_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:29:05 by rojones           #+#    #+#             */
/*   Updated: 2016/08/18 17:06:23 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** l = ref[l]ect colour
** r = ref[r]act colour
*/

t_colour	find_colour_struct(t_env *e, int depth)
{
	t_colour	l;
	t_colour	r;
	t_colour	temp_c;
	t_material	*mat;

	if (!e->hit_type)
		return ((t_colour){0.5, 0.5, 0.5, 1.0});
	temp_c = (e->hit_type == FACE) ? face_diffuse(e) : prim_diffuse(e);
	mat = (e->hit_type == FACE) ?
		e->material[e->object_hit->material] :
		e->material[e->p_hit->material];
	if (depth < e->maxdepth && mat->reflect > EPSILON)
		l = reflect(e, depth + 1);
	if (mat->refract > EPSILON)
	{
		r = refract(e, depth + 1, temp_c);
		temp_c.r = (temp_c.r * (1 - mat->refract)) + (r.r * mat->refract);
		temp_c.g = (temp_c.g * (1 - mat->refract)) + (r.g * mat->refract);
		temp_c.b = (temp_c.b * (1 - mat->refract)) + (r.b * mat->refract);
	}
	temp_c.r = ((temp_c.r * (1 - mat->reflect)) + (l.r * mat->reflect));
	temp_c.g = ((temp_c.g * (1 - mat->reflect)) + (l.g * mat->reflect));
	temp_c.b = ((temp_c.b * (1 - mat->reflect)) + (l.b * mat->reflect));
	return (temp_c);
}
