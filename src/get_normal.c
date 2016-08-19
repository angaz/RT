/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:10:39 by rojones           #+#    #+#             */
/*   Updated: 2016/08/19 10:05:22 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

static t_vector	get_con_normal(t_env *e, t_vector ray)
{
	t_vector    normal;
	t_vector    rot;
	t_vector	p_par;
	t_vector	p_orth;
	t_vector	nnor_orth;

	normal = vunit(vsub(vsub(ray, e->p_hit->loc),
				vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir)));
	rot = vunit(vcross(normal, e->p_hit->dir));
	p_par = vproject(normal, rot);
	p_orth = vsub(normal, p_par);
	nnor_orth = vadd(vmult(p_orth, cos(e->p_hit->angle)),
			vmult(vcross(rot, p_orth), sin(e->p_hit->angle)));
	normal = vunit(vadd(nnor_orth, p_par));
	return (normal);
}

t_vector	get_normal(t_env *e, t_vector ray)
{
	if (e->hit_type == FACE)
		return (vunit(*e->o_hit->n));
	if (e->p_hit->type == PRIM_SPHERE)
		return (vunit(vdiv(vsub(ray, e->p_hit->loc), e->p_hit->radius)));
	if (e->p_hit->type == PRIM_PLANE || e->p_hit->type == PRIM_DISK)
		return ((vdot(e->p_hit->normal, ray) < -0.44807361612) ? 
				vunit(e->p_hit->normal) : 
				vunit(vsub((t_vector){0, 0, 0}, e->p_hit->normal)));
	if (e->p_hit->type == PRIM_CYLINDER)
		return (vunit(vsub(vsub(ray, e->p_hit->loc),
			vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir))));
	if (e->p_hit->type == PRIM_CONE)
		return (vunit(get_con_normal(e, ray)));
	return ((t_vector){0.0, 0.0, 1.0});
}
