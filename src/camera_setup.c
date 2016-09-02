/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_setup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/01 22:35:01 by adippena          #+#    #+#             */
/*   Updated: 2016/09/02 11:12:28 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "draw.h"

void		setup_camera_plane(t_env *e)
{
	t_vector	n;
	t_vector	c;
	double		w;
	double		h;

	h = 18.0 * ARBITRARY_NUMBER / 35.0;
	w = h * (double)e->x / (double)e->y;
	n = vunit(vsub(e->camera.loc, e->camera.dir));
	e->camera.u = vunit(vcross(e->camera.up, n));
	e->camera.v = vunit(vcross(n, e->camera.u));
	c = vsub(e->camera.loc, vmult(n, ARBITRARY_NUMBER));
	e->camera.l = vadd(vsub(c,
		vmult(e->camera.u, w / 2.0)),
		vmult(e->camera.v, h / 2.0));
	e->camera.stepx = w / (double)e->x;
	e->camera.stepy = h / (double)e->y;
}

void		get_ray_dir(t_env *e, double x, double y)
{
	e->ray.dir = vunit(vsub(vsub(
		vadd(e->camera.l, vmult(e->camera.u, x * e->camera.stepx)),
		vmult(e->camera.v, y * e->camera.stepy)), e->camera.loc));
	e->ray.loc = e->camera.loc;
	e->ray.o_in = NULL;
	e->ray.ior = 1;
}
