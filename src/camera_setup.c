/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 22:35:01 by adippena          #+#    #+#             */
/*   Updated: 2016/08/06 13:42:42 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		setup_camera_plane(t_env *e, t_camera_ray *c)
{
	c->d = 2.1675;
	c->h = 18.0 * c->d / 35.0;
	c->w = c->h * (double)WIN_X / (double)WIN_Y;
	c->n = vunit(vsub(e->camera.loc, e->camera.dir));
	c->u = vunit(vcross(e->camera.up, c->n));
	c->v = vunit(vcross(c->n, c->u));
	c->c = vsub(e->camera.loc, vmult(c->n, c->d));
	c->l = vsub(c->c, vmult(c->u, c->w / 2.0));
	c->l = vadd(c->l, vmult(c->v, c->h / 2.0));
}

void		get_ray_dir(t_env *e, t_camera_ray *cr, double x, double y)
{
	t_vector	s;

	s = vadd(cr->l, vmult(cr->u, x * cr->w / (double)WIN_X));
	s = vsub(s, vmult(cr->v, y * cr->h / (double)WIN_Y));
	e->ray.dir = vsub(s, e->camera.loc);
	e->ray.loc = e->camera.loc;
}
