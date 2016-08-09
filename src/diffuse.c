/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:55:24 by adippena          #+#    #+#             */
/*   Updated: 2016/08/09 14:15:51 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

/*
**	TODO: FIX the cone - normal changes because of the angle
** DON'T REMOVE : NEW CODE NOT TESTED - adippena
** Old normal calculation for the cylinder and cone
** normal = vsub(ray, e->hit->loc);
** normal = vsub(normal, vproject(normal, e->hit->dir));
*/

static void		diffuse_colour(t_env *e, t_diffuse *d)
{
	if (in_shadow(e, d->light) == 1)
	{
		d->l = vsub(d->light->loc, d->p);
		d->dist = vnormalize(d->l);
		d->l = vunit(d->l);
		d->v = vunit(vsub(e->camera.loc, d->p));
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

t_colour		diffuse_shade(t_env *e)
{
	t_diffuse	d;
	size_t		i;

	d.mat = e->material[e->hit->material];
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
