/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_triangle.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:23:25 by adippena          #+#    #+#             */
/*   Updated: 2016/08/08 16:24:22 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void		get_tri(t_env *e, t_object *o, t_split_string *values)
{
	if (values->words != 9)
		err(FILE_FORMAT_ERROR, "get_tri", e);
	o->p1.x = ft_atod(values->strings[0]);
	o->p1.y = ft_atod(values->strings[1]);
	o->p1.z = ft_atod(values->strings[2]);
	o->p2.x = ft_atod(values->strings[3]);
	o->p2.y = ft_atod(values->strings[4]);
	o->p2.z = ft_atod(values->strings[5]);
	o->p3.x = ft_atod(values->strings[6]);
	o->p3.y = ft_atod(values->strings[7]);
	o->p3.z = ft_atod(values->strings[8]);
	o->normal = vcross(vsub(o->p2, o->p1), vsub(o->p3, o->p1));
}
