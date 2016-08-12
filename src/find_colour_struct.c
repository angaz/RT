/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colour_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:29:05 by rojones           #+#    #+#             */
/*   Updated: 2016/08/12 19:35:24 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_colour	find_colour_struct(t_env *e, int depth)
{
	t_colour	reflect_c;
	t_colour	refract_c;
	t_colour	temp_c;
	t_material	*mat;

	if (!e->hit_type)
		return ((t_colour){0.4980392156, 0.4980392156, 0.4980392156, 1.0});
	temp_c = (e->hit_type == FACE) ? face_diffuse(e) : prim_diffuse(e);
	mat = (e->hit_type == FACE) ?
		e->material[e->object[e->o_hit_index]->material] :
		e->material[e->p_hit->material];
	if (depth < e->maxdepth && mat->reflect > 0.0)
		reflect_c = reflect(e, depth + 1);
	if (mat->refract < 1.0)
	{
		refract_c = refract(e, depth + 1, temp_c);
		temp_c.r = (temp_c.r * mat->refract) + (refract_c.r * (1 - mat->refract));
		temp_c.g = (temp_c.g * mat->refract) + (refract_c.g * (1 - mat->refract));
		temp_c.b = (temp_c.b * mat->refract) + (refract_c.b * (1 - mat->refract));
	}
	temp_c.r = ((temp_c.r * (1 - mat->reflect)) + (reflect_c.r * mat->reflect));
	temp_c.g = ((temp_c.g * (1 - mat->reflect)) + (reflect_c.g * mat->reflect));
	temp_c.b = ((temp_c.b * (1 - mat->reflect)) + (reflect_c.b * mat->reflect));
	return (temp_c);
}
