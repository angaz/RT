/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:30:32 by rojones           #+#    #+#             */
/*   Updated: 2016/09/04 13:21:03 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static int	refract_prim(t_env *e, t_env *refract, t_vector n)
{
	double	cos;
	double	factor;
	double	index;

	cos = vdot(e->ray.dir, n);
	if (cos > 0.0)
	{
		index = e->material[e->p_hit->material]->ior;
		factor = 1.0 - (1.0 - cos * cos) * index * index;
		if (factor <= 0.0)
			return (0);
		factor = -cos * index + sqrt(factor);
	}
	else
	{
		index = 1.0 / e->material[e->p_hit->material]->ior;
		factor = 1.0 - (1.0 - cos * cos) * index * index;
		if (factor <= 0.0)
			return (0);
		factor = -cos * index - sqrt(factor);
	}
	refract->ray.dir = vadd(vmult(e->ray.dir, index), vmult(n, factor));
	return (1);
}

static int	refract_obj(t_env *e, t_env *refract, t_vector n)
{
	double	cos;
	double	factor;
	double	index;

	cos = vdot(e->ray.dir, n);
	if (cos > 0.0)
	{
		index = e->material[e->object_hit->material]->ior;
		factor = 1.0 - (1.0 - cos * cos) * index * index;
		if (factor <= 0.0)
			return (0);
		factor = -cos * index + sqrt(factor);
	}
	else
	{
		index = 1.0 / e->material[e->object_hit->material]->ior;
		factor = 1.0 - (1.0 - cos * cos) * index * index;
		if (factor <= 0.0)
			return (0);
		factor = -cos * index - sqrt(factor);
	}
	refract->ray.dir = vadd(vmult(e->ray.dir, index), vmult(n, factor));
	return (1);
}

static void	set_refract_ray_object(t_env *e, t_env *refract)
{
	t_vector	n;

	refract->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	n = get_normal(e, refract->ray.loc);
	if (refract->flags & RAY_INSIDE)
	{
		n = vunit(vsub((t_vector){0.0, 0.0, 0.0}, n));
		if (refract_obj(e, refract, n))
			refract->flags &= ~RAY_INSIDE;
		else
			set_reflect_ray(e, refract);
	}
	else
	{
		if (refract_obj(e, refract, n))
			refract->flags |= RAY_INSIDE;
		else
			set_reflect_ray(e, refract);
	}
}

static void	set_refract_ray_prim(t_env *e, t_env *refract)
{
	t_vector	n;

	refract->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	n = get_normal(e, refract->ray.loc);
	if (refract->flags & RAY_INSIDE)
	{
		n = vunit(vsub((t_vector){0.0, 0.0, 0.0}, n));
		if (refract_prim(e, refract, n))
			refract->flags &= ~RAY_INSIDE;
		else
			set_reflect_ray(e, refract);
	}
	else
	{
		if (refract_prim(e, refract, n))
			refract->flags |= RAY_INSIDE;
		else
			set_reflect_ray(e, refract);
	}
}

t_colour	refract(t_env *e, int depth, t_colour colour)
{
	t_env		*refract_env;

	if (depth > e->maxdepth)
		return (colour);
	refract_env = copy_env(e);
	if (e->hit_type == FACE)
	{
		set_refract_ray_object(e, refract_env);
		intersect_scene(refract_env);
		colour = find_colour_struct(refract_env, depth);
	}
	else if (e->hit_type == PRIMITIVE)
	{
		set_refract_ray_prim(e, refract_env);
		intersect_scene(refract_env);
		colour = find_colour_struct(refract_env, depth);
	}
	free(refract_env);
	return (colour);
}
