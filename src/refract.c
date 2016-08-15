/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   refract.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/09 09:30:32 by rojones           #+#    #+#             */
/*   Updated: 2016/08/15 14:09:59 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "rt.h"

static int	set_refract_ray_prim(t_env *e, t_env *refract)
{
	t_vector	n;
	double		ior;
	double		cos;
	double		check;

	refract->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	n = get_normal(e, refract->ray.loc);
	if (e->ray.p_in == e->p_hit)
	{
		cos = M_PI - vdot(vunit(vsub(e->ray.loc, refract->ray.loc)), n);
		refract->ray.p_in = NULL;
		refract->ray.ior = 1;
	}
	else
	{
		cos = vdot(vunit(vsub(e->ray.loc, refract->ray.loc)), n);
		refract->ray.p_in = e->p_hit;
		refract->ray.ior = e->material[e->p_hit->material]->ior;
	}
	ior = (e->ray.ior / refract->ray.ior);
	if ((check = 1 - pow(ior, 2) * (1 - pow(cos,2))) < 0.0)
		return (0);
	refract->ray.dir = vunit(vadd(
		vmult(e->ray.dir, ior), vmult(n, ((ior * cos) - sqrt(check)))));
	return (1);
}

/*static int	set_refract_ray_object(t_env *e, t_env *refract)
{
	t_vector	n;
	double		ior;
	double		cos;
	double		check;

	refract->ray.loc = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	n = *e->o_hit->n;
	if (e->ray.o_in == e->object_hit)
	{
		cos = M_PI - vdot(vunit(vsub(e->ray.loc, refract->ray.loc)), n);
		refract->ray.o_in = NULL;
		refract->ray.ior = 1;
	}
	else
	{
		cos = vdot(vunit(vsub(e->ray.loc, refract->ray.loc)), n);
		refract->ray.o_in = e->object_hit;
		refract->ray.ior = e->material[e->object_hit->material]->ior;
	}
	ior = (e->ray.ior / refract->ray.ior);
	if ((check = 1 - pow(ior, 2) * (1 - pow(cos,2))) < 0.0)
		return (0);
	refract->ray.dir = vunit(vadd(
		vmult(e->ray.dir, ior), vmult(n, ((ior * cos) - sqrt(check)))));
	return (1);
} */

static int	set_refract_ray_object(t_env *e, t_env *r)
{
	double	n;
	double	cosi;
	double	sint2;
	double	cost;

	n = (r->ray.ior == e->material[r->object_hit->material]->ior) ?
		e->material[r->object_hit->material]->ior :
		r->ray.ior / e->material[r->object_hit->material]->ior;
	cosi = -vdot(*r->o_hit->n, r->ray.dir);
//printf("%lf\n", cosi);
//	cosi = (cosi > M_PI / 2.0) ? cosi - M_PI : cosi;
printf("%lf\n", n);
//	cosi = (n == 1.0) ? M_PI - cosi : cosi;
	sint2 = n * n * (1.0 - cosi * cosi);
	if (sint2 > 1.0)
		return (0);
	cost = sqrt(1.0 - sint2);
printf("%lf %lf\n", cosi, cost);
	r->ray.ior = e->material[r->object_hit->material]->ior;
	r->ray.loc = vmult(r->ray.dir, r->t);
	r->ray.dir = vadd(vmult(r->ray.dir, n), vmult(*r->o_hit->n, (n * cosi - cost)));
	return(1);
}

t_colour	refract(t_env *e, int depth, t_colour colour)
{
	t_env		*refract_env;

	refract_env = copy_env(e);
	if (e->hit_type == FACE && set_refract_ray_object(e, refract_env))
	{
		intersect_object(refract_env, refract_env->object_hit, &refract_env->t);
		set_refract_ray_object(e, refract_env);
		intersect_scene(refract_env);
		colour = find_colour_struct(refract_env, depth);
	}
	if (e->hit_type == PRIMITIVE && set_refract_ray_prim(e, refract_env))
	{
		intersect_scene(refract_env);
		colour = find_colour_struct(refract_env, depth);
	}
	free(refract_env);
	return (colour);
}
