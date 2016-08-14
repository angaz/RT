/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:10:39 by rojones           #+#    #+#             */
/*   Updated: 2016/08/14 14:56:07 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

static t_vector	get_con_normal(t_env *e, t_vector ray)
{
	t_vector    normal;
	t_vector	pro;
	t_vector    rot;
	t_vector	p_par;
	t_vector	p_orth;
	t_vector	nnor_orth;
	double		angle;

	pro = vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir);
	normal = vunit(vsub(vsub(ray, e->p_hit->loc), pro));
	rot = vunit(vcross(normal, e->p_hit->dir));
	p_par = vproject(normal, rot);
	p_orth = vsub(normal, p_par);
	angle = e->p_hit->angle;
	nnor_orth = vadd(vmult(p_orth, cos(angle)), vmult(vcross(rot, p_orth), sin(angle)));
	normal = vunit(vadd(nnor_orth, p_par));
	return (normal);
}

t_vector	get_normal(t_env *e, t_vector ray)
{
	if (e->hit_type == FACE)
		return (vunit(*e->o_hit->n));
	if (e->p_hit->type == PRIM_SPHERE)
		return (vunit(vdiv(vsub(ray, e->p_hit->loc), e->p_hit->radius)));
	if (e->p_hit->type == PRIM_PLANE)
		return (vunit(e->p_hit->normal));
	if (e->p_hit->type == PRIM_CYLINDER)
		return (vunit(vsub(vsub(ray, e->p_hit->loc),
			vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir))));
	if (e->p_hit->type == PRIM_CONE)
		return (vunit(get_con_normal(e, ray)));
	return ((t_vector){0.0, 0.0, 1.0});
}
