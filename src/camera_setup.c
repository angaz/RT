/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 22:35:01 by adippena          #+#    #+#             */
/*   Updated: 2016/08/22 19:28:45 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		setup_camera_plane(t_env *e, t_camera_ray *c)
{
	c->d = 2.175;
	c->h = 18.0 * c->d / 35.0;
	c->w = c->h * (double)e->x / (double)e->y;
	c->n = vunit(vsub(e->camera.loc, e->camera.dir));
	c->u = vunit(vcross(e->camera.up, c->n));
	c->v = vunit(vcross(c->n, c->u));
	c->c = vsub(e->camera.loc, vmult(c->n, c->d));
	c->l = vsub(c->c, vmult(c->u, c->w / 2.0));
	c->l = vadd(c->l, vmult(c->v, c->h / 2.0));
	c->stepx = c->w / (double)e->x;
	c->stepy = c->h / (double)e->y;
}

void		get_ray_dir(t_env *e, t_camera_ray *cr, double x, double y)
{
	t_vector	s;

	s = vadd(cr->l, vmult(cr->u, x * cr->stepx));
	s = vsub(s, vmult(cr->v, y * cr->stepy));
	e->ray.dir = vunit(vsub(s, e->camera.loc));
	e->ray.loc = e->camera.loc;
	e->ray.o_in = NULL;
	e->ray.ior = 1;
}
