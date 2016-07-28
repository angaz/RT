/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/13 13:55:24 by adippena          #+#    #+#             */
/*   Updated: 2016/07/28 18:32:31 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

static t_vector	get_normal(t_env *e, t_vector ray)
{
	t_vector	normal;

	if (e->hit->type == OBJ_SPHERE)
		normal = vector_div(vector_sub(ray, e->hit->loc), e->hit->radius);
	else if (e->hit->type == OBJ_PLANE)
		normal = e->hit->normal;
	else if (e->hit->type == OBJ_CYLINDER)
	{
		normal = (vector_sub(ray, e->hit->loc));
		normal = vector_sub(normal, vector_project(normal, e->hit->dir));
	}
	else if (e->hit->type == OBJ_CONE)
	{
		normal = vector_sub(ray, e->hit->loc);
		normal = vector_sub(normal, vector_project(normal, e->hit->dir));
	}
	else
		normal = (t_vector){0.0, 0.0, 0.0};
	normal = vector_unit(normal);
	return (normal);
}

int				diffuse_colour(t_env *e, t_diffuse *d)
{
	d->light = e->light[d->i];
	d->shade = in_shadow(e, d->light);
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
			d->spec_angle = 0.0;
		d->specular = pow(d->spec_angle, 16.0);
	}
	d->colour = vector_add(d->colour, vector_mult(vector_add(vector_mult(
		colour_to_vector(d->mat->diffuse), d->lambert / e->lights), vector_mult(
		colour_to_vector(d->mat->specular), d->specular / e->lights)),
		(d->light->intensity * d->shade) / (4.0 * M_PI * d->distance * d->distance * 0.001)));
	return (1);
}

t_colour		diffuse_shade(t_env *e)
{
	t_diffuse	d;

	d.mat = e->material[e->hit->material];
	d.ray = vector_add(e->ray.loc, vector_mult(e->ray.dir, e->t));
	d.normal = get_normal(e, d.ray);
	d.colour = (t_vector){0.0, 0.0, 0.0};
	d.i = 0;
	while (d.i < e->lights)
	{
		diffuse_colour(e, &d);
		++d.i;
	}
	if (d.colour.x > 1.0)
		d.colour.x = 1.0;
	if (d.colour.y > 1.0)
		d.colour.y = 1.0;
	if (d.colour.z > 1.0)
		d.colour.z = 1.0;
	return ((t_colour){d.colour.x, d.colour.y, d.colour.z});
}
