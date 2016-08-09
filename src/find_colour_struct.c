/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_colour_struct.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:29:05 by rojones           #+#    #+#             */
/*   Updated: 2016/08/09 13:33:47 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_colour	find_colour_struct(t_env *e, int depth)
{
	t_colour	reflect_col;
	t_colour	refract_col;
	t_colour	temp_c;
//	double		refract_key;
//	double		reflect_key;

//	refract_key = e->material[e->hit->material]->refract;
//	reflect_key	= e->material[e->hit->material]->reflect;
	if (e->hit == NULL)
		return ((t_colour){0.4980392156, 0.4980392156, 0.4980392156, 1.0});
	temp_c = diffuse_shade(e);
	if (depth < e->maxdepth && e->material[e->hit->material]->reflect > 0.0)
		reflect_col = reflect(e, depth + 1);
	if (e->material[e->hit->material]->refract < 1.0)
	{
		refract_col = refract(e, depth + 1, temp_c);
		temp_c.r = (temp_c.r * e->material[e->hit->material]->refract) + (refract_col.r * (1 - e->material[e->hit->material]->refract));
		temp_c.g = (temp_c.g * e->material[e->hit->material]->refract) + (refract_col.g * (1 - e->material[e->hit->material]->refract));
		temp_c.b = (temp_c.b * e->material[e->hit->material]->refract) + (refract_col.b * (1 - e->material[e->hit->material]->refract));
	}
	temp_c.r = ((temp_c.r * (1 - e->material[e->hit->material]->reflect)) + (reflect_col.r * e->material[e->hit->material]->reflect));
	temp_c.g = ((temp_c.g * (1 - e->material[e->hit->material]->reflect)) + (reflect_col.g * e->material[e->hit->material]->reflect));
	temp_c.b = ((temp_c.b * (1 - e->material[e->hit->material]->reflect)) + (reflect_col.b * e->material[e->hit->material]->reflect));
	return (temp_c);
}
