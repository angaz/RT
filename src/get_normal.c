/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:10:39 by rojones           #+#    #+#             */
/*   Updated: 2016/08/20 15:26:24 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"
#include "intersect_cone.h"

static t_vector	get_con_normal(t_env *e, t_vector ray)
{
	t_cone_normal	cn;

	cn.pro = vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir);
	cn.normal = vunit(vsub(vsub(ray, e->p_hit->loc), cn.pro));
	cn.rot = (vdot(e->p_hit->dir, vsub(vsub(ray, e->p_hit->loc), e->p_hit->loc)) > 0) ? vunit(vcross(e->p_hit->dir, cn.normal)) : (t_vector){0, 0, 0}/*vunit(vcross(cn.normal, e->p_hit->dir))*/;
	cn.p_par = vproject(cn.normal, cn.rot);
	cn.p_orth = vsub(cn.normal, cn.p_par);
	cn.nnor_orth = vadd(vmult(cn.p_orth, cos(e->p_hit->angle)),
			vmult(vcross(cn.rot, cn.p_orth), sin(e->p_hit->angle)));
	cn.normal = vunit(vadd(cn.nnor_orth, cn.p_par));
	return (cn.normal);
}

t_vector		get_normal(t_env *e, t_vector ray)
{
	t_vector	normal;

	normal = (t_vector){0.0, 0.0, 1.0};
	if (e->hit_type == FACE)
		normal = (vunit(*e->o_hit->n));
	else if (e->p_hit->type == PRIM_SPHERE)
		normal = (vunit(vdiv(vsub(ray, e->p_hit->loc), e->p_hit->radius)));
	else if (e->p_hit->type == PRIM_PLANE || e->p_hit->type == PRIM_DISK)
		return ((vdot(e->p_hit->normal, ray) < -0.44807361612) ?
				vunit(e->p_hit->normal) :
				vunit(vsub((t_vector){0, 0, 0}, e->p_hit->normal)));
	else if (e->p_hit->type == PRIM_CYLINDER)
		normal = (vunit(vsub(vsub(ray, e->p_hit->loc),
						vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir))));
	else if (e->p_hit->type == PRIM_CONE)
		normal = (vunit(get_con_normal(e, ray)));
	if (e->ray.inter == 2)
		normal = vsub((t_vector){0, 0, 0}, normal);
	return (normal);
}
