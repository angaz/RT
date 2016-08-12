/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:55:24 by adippena          #+#    #+#             */
/*   Updated: 2016/08/12 17:48:12 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

/*static t_vector	get_normal(t_env *e, t_vector ray)
{
	t_vector	normal;

	normal = (t_vector){0.0, 0.0, 1.0};
	if (e->p_hit->type == PRIM_SPHERE)
		normal = vdiv(vsub(ray, e->p_hit->loc), e->p_hit->radius);
	else if (e->p_hit->type == PRIM_PLANE)
		normal = e->p_hit->normal;
	else if (e->p_hit->type == PRIM_CYLINDER)
		normal = vsub(vsub(ray, e->p_hit->loc),
			vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir));
	else if (e->p_hit->type == PRIM_CONE)
		normal = vsub(vsub(ray, e->p_hit->loc),
			vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir));
	normal = vunit(normal);
	return (normal);
} */

static void		diffuse_colour(t_env *e, t_diffuse *d)
{
	if (in_shadow(e, d->light) == 1)
	{
		d->l = vsub(d->light->loc, d->p);
		d->dist = vnormalize(d->l);
		d->l = vunit(d->l);
		d->v = vunit(vsub(e->ray.loc, d->p));
		d->h = vunit(vadd(d->v, d->l));
		d->intensity = d->light->lm *
			(d->light->half / (d->light->half + d->dist * d->dist));
		d->ld = vmult(vmult(colour_to_vector(d->mat->diff),
			d->mat->diff.intensity), d->intensity * MAX(0, vdot(d->n, d->l)));
		d->ls = vmult(vmult(colour_to_vector(d->mat->spec),
			d->mat->spec.intensity), d->intensity *
			pow(MAX(0, vdot(d->n, d->h)), 50.0));
		d->colour = vadd(d->colour, vadd(d->ld, d->ls));
	}
}

t_colour		prim_diffuse(t_env *e)
{
	t_diffuse	d;
	size_t		i;

	d.mat = e->material[e->p_hit->material];
	d.p = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	d.n = get_normal(e, d.p);
	d.colour = (t_vector){0.0, 0.0, 0.0};
	d.intensity = 1.0;
	i = 0;
	while (i < e->lights)
	{
		d.light = e->light[i];
		diffuse_colour(e, &d);
		++i;
	}
	d.colour.x = (d.colour.x > 1.0) ? 1.0 : d.colour.x;
	d.colour.y = (d.colour.y > 1.0) ? 1.0 : d.colour.y;
	d.colour.z = (d.colour.z > 1.0) ? 1.0 : d.colour.z;
	return ((t_colour){d.colour.x, d.colour.y, d.colour.z, d.intensity});
}

t_colour		face_diffuse(t_env *e)
{
	t_diffuse	d;
	size_t		i;

	d.mat = e->material[e->object[e->o_hit_index]->material];
	d.p = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	d.n = *e->o_hit->n;
	d.colour = (t_vector){0.0, 0.0, 0.0};
	d.intensity = 1.0;
	i = 0;
	while (i < e->lights)
	{
		d.light = e->light[i];
		diffuse_colour(e, &d);
		++i;
	}
	d.colour.x = (d.colour.x > 1.0) ? 1.0 : d.colour.x;
	d.colour.y = (d.colour.y > 1.0) ? 1.0 : d.colour.y;
	d.colour.z = (d.colour.z > 1.0) ? 1.0 : d.colour.z;
	return ((t_colour){d.colour.x, d.colour.y, d.colour.z, d.intensity});
}
