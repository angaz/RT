/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:10:39 by rojones           #+#    #+#             */
/*   Updated: 2016/08/12 18:27:02 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

static t_vector	get_con_normal(t_env *e, t_vector ray)
{
	t_vector    normal;
	t_vector	pro;
//	t_vector	com;
	t_vector    rot;
	t_vector	p_par;
	t_vector	p_orth;
	t_vector	nnor_orth;
	double		angle;

	pro = vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir);
	normal = vsub(vsub(ray, e->p_hit->loc), pro);
	normal = vunit(normal);
//	com = vsub(pro, e->p_hit->loc);
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
	t_vector	normal;

	normal = (t_vector){0.0, 0.0, 1.0};
	if (e->p_hit->type == PRIM_SPHERE)
		normal = vdiv(vsub(ray, e->p_hit->loc), e->p_hit->radius);
	else if (e->p_hit->type == PRIM_PLANE)
		normal = e->p_hit->normal;
	else if (e->p_hit->type == PRIM_CYLINDER)
		normal = vsub(vsub(ray, e->p_hit->loc),
			vproject(vsub(ray, e->p_hit->loc), e->p_hit->dir));
	else if (e->p_hit->type == PRIM_CONE)
		normal = get_con_normal(e, ray);
	normal = vunit(normal);
	return (normal);
}
