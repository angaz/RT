/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:30:32 by rojones           #+#    #+#             */
/*   Updated: 2016/08/09 15:54:43 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rt.h"

static int	set_refract_ray(t_env *e, t_env *refract)
{
	t_vector	i_scale;
	t_vector	n_scale;
	t_vector	n;
	double		cos;
	double		sin;
	double		check;

	refract->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	n = get_normal(e, refract->ray.loc);
	refract->ray.ior = e->material[e->hit->material]->ior;
	cos = vdot(e->ray.dir, n);
	sin = pow ((e->ray.ior / refract->ray.ior), 2) * (1 - pow(cos,2));
	check = 1 - sin;
	if (check < 0)
		return (0);
	i_scale = vmult(e->ray.dir, (e->ray.ior / refract->ray.ior));
	n_scale = vmult(n, (((e->ray.ior / refract->ray.ior) * cos) - sqrt(check)));
	refract->ray.dir = vunit(vadd(i_scale, n_scale));
	return (1);
}

t_colour	refract(t_env *e, int depth, t_colour colour)
{
	t_env		*refract_env;

	refract_env = copy_env(e);
	if(set_refract_ray(e, refract_env))
	{
		intersect_scene(refract_env);
		colour = find_colour_struct(refract_env, depth);
	}
	free(refract_env);
	return (colour);
}
