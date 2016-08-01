/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 22:35:01 by adippena          #+#    #+#             */
/*   Updated: 2016/08/02 00:42:57 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		setup_camera_plane(t_env *e, t_camera_ray *c)
{
	c->d = 2.1675;
	c->h = 18.0 * c->d / 35.0;
	c->w = c->h * (double)WIN_X / (double)WIN_Y;
	c->n = vector_unit(vector_sub(e->camera.loc, e->camera.dir));
	c->u = vector_unit(vector_cross(e->camera.up, c->n));
	c->v = vector_unit(vector_cross(c->n, c->u));
	c->c = vector_sub(e->camera.loc, vector_mult(c->n, c->d));
	c->l = vector_sub(c->c, vector_mult(c->u, c->w / 2.0));
	c->l = vector_add(c->l, vector_mult(c->v, c->h / 2.0));
}

void		get_ray_dir(t_env *e, t_camera_ray *cr, double x, double y)
{
	t_vector	s;

	s = vector_add(cr->l, vector_mult(cr->u, x * cr->w / (double)WIN_X));
	s = vector_sub(s, vector_mult(cr->v, y * cr->h / (double)WIN_Y));
	e->ray.dir = vector_sub(s, e->camera.loc);;
	e->ray.loc = e->camera.loc;
}
