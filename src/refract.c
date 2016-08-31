/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:30:32 by rojones           #+#    #+#             */
/*   Updated: 2016/08/31 20:32:53 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	set_refract_ray_prim(t_env *e, t_env *refract)
{
	t_vector	n;
	double		ior;
	double		cos;
	double		check;

	refract->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	n = get_normal(e, refract->ray.loc);
	if (e->ray.inter == 2)
		refract->ray.ior = 1;
	else
		refract->ray.ior = e->material[e->p_hit->material]->ior;
	cos = vdot(vunit(vsub(e->ray.loc, refract->ray.loc)), n);
	ior = (e->ray.ior / refract->ray.ior);
	if ((check = 1 - pow(ior, 2) * (1 - pow(cos, 2))) < 0.0)
		set_reflect_ray(e, refract);
	refract->ray.dir = vunit(vadd(
		vmult(e->ray.dir, ior), vmult(n, ((ior * cos) - sqrt(check)))));
}

static void	set_refract_ray_object(t_env *e, t_env *refract)
{
	t_vector	n;
	double		ior;
	double		cos;
	double		check;

	refract->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	n = get_normal(e, refract->ray.loc);
	if (e->object_hit == e->ray.o_in)
	{
		refract->ray.o_in = NULL;
		refract->ray.ior = 1;
		ior = (e->ray.ior / refract->ray.ior);
	}
	else
	{
		refract->ray.o_in = e->object_hit;
		refract->ray.ior = e->material[e->object_hit->material]->ior;
		ior = (1.0 / refract->ray.ior);
	}
	cos = vdot(vunit(vsub(e->ray.loc, refract->ray.loc)), n);
	if ((check = 1 - pow(ior, 2) * (1 - pow(cos, 2))) < -EPSILON)
		set_reflect_ray(e, refract);
	else
	refract->ray.dir = vunit(vadd(
		vmult(e->ray.dir, ior), vmult(n, ((ior * cos) - sqrt(check)))));
//printf("%lf, %lf, %lf\n", refract->ray.dir.x, refract->ray.dir.y, refract->ray.dir.z);

}

t_colour	refract(t_env *e, int depth, t_colour colour)
{
	t_env		*refract_env;

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
