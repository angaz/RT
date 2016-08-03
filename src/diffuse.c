/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:55:24 by adippena          #+#    #+#             */
/*   Updated: 2016/08/03 14:02:52 by adippena         ###   ########.fr       */
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
		normal = vsub(vsub(ray, e->hit->loc), vproject(normal, e->hit->dir));
//		normal = vsub(normal, vproject(normal, e->hit->dir));
	}
	else if (e->hit->type == OBJ_CONE)
	{
		normal = vsub(vsub(ray, e->hit->loc), vproject(normal, e->hit->dir));
//		normal = vsub(ray, e->hit->loc);
//		normal = vsub(normal, vproject(normal, e->hit->dir));
	}
	else
		normal = (t_vector){0.0, 0.0, 1.0};
	normal = vunit(normal);
	return (normal);
}

/*static void		diffuse_colour(t_env *e, t_diffuse *d)
{
	d->light = e->light[d->i];
	if ((d->shade = in_shadow(e, d->light)) != 0.0)
	{
		d->light_dir = vector_sub(d->light->loc, d->ray);
		d->distance = vector_normalize(d->light_dir);
		d->light_dir = vector_unit(d->light_dir);
		d->specular = 0.0;
		if ((d->lambert = vector_dot(d->light_dir, d->normal)) < 0)
			d->lambert = 0.0;
		if (d->lambert > 0.0)
		{
			d->view_dir = vector_unit(vector_sub((t_vector){0, 0, 0}, d->ray));
			d->half_dir = vector_unit(vector_add(d->light_dir, d->view_dir));
			d->spec_angle = vector_dot(d->half_dir, d->normal);
			if (d->spec_angle < 0.0)
				d->spec_angle = 0;
			d->specular = pow(d->spec_angle, 50.0);
		}
		d->colour = vector_add(d->colour, vector_add(vector_mult(colour_to_vector
			(d->mat->diffuse), d->lambert / e->lights * d->mat->diffuse.intensity), vector_mult(colour_to_vector
			(d->mat->specular), d->specular / e->lights * d->mat->specular.intensity)));
		d->intensity += d->light->intensity / (2.0 * pow(d->distance / d->light->half, 2));
	}
} */

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
//		v = vunit(vsub(d->intersect, e->camera.loc));
		v = vunit(vsub(e->camera.loc, d->intersect));
		h = vunit(vadd(v, l));
		ld = vmult(vmult(colour_to_vector(d->mat->diff), d->mat->diff.intensity),
			d->light->intensity * MAX(0, vdot(d->n, l)));
		ls = vmult(vmult(colour_to_vector(d->mat->spec), d->mat->spec.intensity),
			d->light->intensity * pow(MAX(0, vdot(d->n, h)), 50.0));
//printf("%lf, %lf, %lf\n", d->mat->spec.r, d->mat->spec.g, d->mat->spec.b);
//printf("%lf, %lf, %lf\n", ls.x, ls.y, ls.z);
		d->colour = vadd(d->colour, vmult(vadd(ld, ls),
			d->light->intensity / (4.0 * M_PI * pow(d->dist / d->light->half, 2))));
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
