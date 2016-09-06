/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:29:05 by rojones           #+#    #+#             */
/*   Updated: 2016/09/03 13:29:10 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** l = ref[l]ect colour
** r = ref[r]act colour
*/

uint32_t	find_colour(t_env *e)
{
	t_colour	c;
	t_colour	l;
	t_colour	r;
	t_material	*mat;

	c = (e->hit_type == FACE) ? face_diffuse(e) : prim_diffuse(e);
	mat = (e->hit_type == FACE) ?
		e->material[e->object_hit->material] :
		e->material[e->p_hit->material];
	l = mat->reflect > 0.0 ? reflect(e, 1) : (t_colour){0.0, 0.0, 0.0, 0.0};
	if (mat->refract > 0.0)
	{
		r = refract(e, 1, c);
		c.r = (c.r * (1 - mat->refract)) + (r.r * mat->refract);
		c.g = (c.g * (1 - mat->refract)) + (r.g * mat->refract);
		c.b = (c.b * (1 - mat->refract)) + (r.b * mat->refract);
	}
	return ((uint32_t)(
	(int)(((c.r * (1 - mat->reflect)) + (l.r * mat->reflect)) * 255.0) << 16 |
	(int)(((c.g * (1 - mat->reflect)) + (l.g * mat->reflect)) * 255.0) << 8 |
	(int)(((c.b * (1 - mat->reflect)) + (l.b * mat->reflect)) * 255.0)));
}

uint32_t	find_base_colour(t_env *e)
{
	t_colour	c;

	if (!e->hit_type)
		return (0x7F7F7F);
	c = (e->hit_type == FACE) ? face_diffuse(e) : prim_diffuse(e);
	return ((uint32_t)(
	(unsigned int)(c.r * 255.0) << 16 |
	(unsigned int)(c.g * 255.0) << 8 |
	(unsigned int)(c.b * 255.0)));
}

t_colour	find_colour_struct(t_env *e, int depth)
{
	t_colour	l;
	t_colour	r;
	t_colour	temp_c;
	t_material	*mat;

	l = (t_colour){0.0, 0.0, 0.0, 1.0};
	if (!e->hit_type)
		return ((t_colour){0.5, 0.5, 0.5, 1.0});
	temp_c = (e->hit_type == FACE) ? face_diffuse(e) : prim_diffuse(e);
	mat = (e->hit_type == FACE) ?
		e->material[e->object_hit->material] :
		e->material[e->p_hit->material];
	if (depth < e->maxdepth && mat->reflect > 0.0)
		l = reflect(e, depth + 1);
	if (mat->refract > 0.0)
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
