/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reflect.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 09:46:58 by rojones           #+#    #+#             */
/*   Updated: 2016/08/14 16:00:02 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_reflect_ray(t_env *e, t_env *reflect)
{
	t_vector	v;
	t_vector	n;

	reflect->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	v = vunit(vsub(e->ray.loc, reflect->ray.loc));
	n = get_normal(e, reflect->ray.loc);
	reflect->ray.dir = vsub(vmult(n, (vdot(n, v) * 2)), v);
	reflect->ray.ior = 0;
}

t_colour	reflect(t_env *e, int depth)
{
	t_env		*reflect;
	t_colour	colour;

	colour = (t_colour){0.0, 0.0, 0.0, 0.0};
	reflect = copy_env(e);
	set_reflect_ray(e, reflect);
	intersect_scene(reflect);
	colour = find_colour_struct(reflect, depth + 1);
	free(reflect);
	return (colour);
}
