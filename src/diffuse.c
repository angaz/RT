/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:55:24 by adippena          #+#    #+#             */
/*   Updated: 2016/08/05 15:16:21 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

static t_vector	get_normal(t_env *e, t_vector ray)
{
	t_vector	normal;

	if (e->hit->type == OBJ_SPHERE)
		normal = vdiv(vsub(ray, e->hit->loc), e->hit->radius);
	else if (e->hit->type == OBJ_PLANE)
		normal = e->hit->normal;
	else if (e->hit->type == OBJ_CYLINDER)
	{
		normal = vsub(vsub(ray, e->hit->loc),
			vproject(vsub(ray, e->hit->loc), e->hit->dir));
//		normal = vsub(normal, vproject(normal, e->hit->dir));		UNTESTED DON'T REMOVE
	}
	else if (e->hit->type == OBJ_CONE)
	{
		normal = vsub(vsub(ray, e->hit->loc),
			vproject(vsub(ray, e->hit->loc), e->hit->dir));
//		normal = vsub(ray, e->hit->loc);							UNTESTED DON'T REMOVE
//		normal = vsub(normal, vproject(normal, e->hit->dir));		UNTESTED DON'T REMOVE
	}
	else
		normal = (t_vector){0.0, 0.0, 1.0};
	normal = vunit(normal);
	return (normal);
}

static void		diffuse_colour(t_env *e, t_diffuse *d)
{
	t_vector	l;
	t_vector	h;
	t_vector	v;
	t_vector	ld;
	t_vector	ls;

	if (in_shadow(e, d->light) == 1)
	{
		l = vsub(d->light->loc, d->intersect);
		d->dist = vnormalize(l);
		l = vunit(l);
		v = vunit(vsub(e->camera.loc, d->intersect));
		h = vunit(vadd(v, l));
		ld = vmult(vmult(colour_to_vector(d->mat->diff), d->mat->diff.intensity),
			/*d->light->lm */ MAX(0, vdot(d->n, l)));
		ls = vmult(vmult(colour_to_vector(d->mat->spec), d->mat->spec.intensity),
			/*d->light->lm */ pow(MAX(0, vdot(d->n, h)), 50.0));
		d->colour = vadd(d->colour, vmult(vadd(ld, ls),
			d->light->lm * (pow(d->light->half, 2) /
			(pow(d->light->half, 2) + pow(d->dist, 2)))));
//			d->light->intensity / (4.0 * M_PI * pow(d->dist / d->light->half, 2))));
	}
}

t_colour		diffuse_shade(t_env *e)
{
	t_diffuse	d;
	size_t		i;

	d.mat = e->material[e->hit->material];
	d.intersect = vadd(e->ray.loc, vmult(e->ray.dir, e->t));
	d.n = get_normal(e, d.intersect);
	d.colour = (t_vector){0.0, 0.0, 0.0};
	d.intensity = 1.0;
	i = 0;
	while (i < e->lights)
	{
		d.light = e->light[i];
		diffuse_colour(e, &d);
		++i;
	}
	if (d.colour.x > 1.0)
		d.colour.x = 1.0;
	if (d.colour.y > 1.0)
		d.colour.y = 1.0;
	if (d.colour.z > 1.0)
		d.colour.z = 1.0;
	if (d.intensity > 1.0)
		d.intensity = 1.0;
	return ((t_colour){d.colour.x, d.colour.y, d.colour.z, d.intensity});
}
