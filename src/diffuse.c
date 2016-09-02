/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:55:24 by adippena          #+#    #+#             */
/*   Updated: 2016/08/30 23:36:23 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

static void		diffuse_colour(t_env *e, t_diffuse *d)
{
	t_vector	temp_colour;

	if (!in_shadow(e, d->light))
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
		temp_colour = vadd(d->ld, d->ls);
		temp_colour = (t_vector){
			temp_colour.x * d->light->colour.r,
			temp_colour.y * d->light->colour.g,
			temp_colour.z * d->light->colour.b};
		d->colour = vadd(d->colour, temp_colour);
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
	i = e->lights;
	while (i--)
	{
		d.light = e->light[i];
		diffuse_colour(e, &d);
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

	d.mat = e->material[e->object_hit->material];
	d.p = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	d.n = *e->o_hit->n;
	d.colour = (t_vector){0.0, 0.0, 0.0};
	d.intensity = 1.0;
	i = e->lights;
	while (i--)
	{
		d.light = e->light[i];
		diffuse_colour(e, &d);
	}
	d.colour.x = (d.colour.x > 1.0) ? 1.0 : d.colour.x;
	d.colour.y = (d.colour.y > 1.0) ? 1.0 : d.colour.y;
	d.colour.z = (d.colour.z > 1.0) ? 1.0 : d.colour.z;
	return ((t_colour){d.colour.x, d.colour.y, d.colour.z, d.intensity});
}
