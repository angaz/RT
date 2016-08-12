/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:10:39 by rojones           #+#    #+#             */
/*   Updated: 2016/08/12 13:58:13 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diffuse.h"

/*
**	TODO: FIX the cone - normal changes because of the angle
** DON'T REMOVE : NEW CODE NOT TESTED - adippena
** Old normal calculation for the cylinder and cone
** normal = vsub(ray, e->hit->loc);
** normal = vsub(normal, vproject(normal, e->hit->dir));
*/

static t_vector	get_con_normal(t_env *e, t_vector ray)
{
	t_vector    normal;
	t_vector	pro;
	t_vector	com;
	t_vector    rot;
	t_vector	p_par;
	t_vector	p_orth;
	t_vector	nnor_orth;
	double		angle;

	pro = vproject(vsub(ray, e->hit->loc), e->hit->dir);
	normal = vsub(vsub(ray, e->hit->loc), pro);
	normal = vunit(normal);
	com = vsub(pro, e->hit->loc);
	rot = vunit(vcross(normal, e->hit->dir));
	p_par = vproject(normal, rot);
	p_orth = vsub(normal, p_par);
	angle = e->hit->angle;
	nnor_orth = vadd(vmult(p_orth, cos(angle)), vmult(vcross(rot, p_orth), sin(angle)));
	normal = vunit(vadd(nnor_orth, p_par));
	return (normal);
}

t_vector	get_normal(t_env *e, t_vector ray)
{
	t_vector	normal;

	normal = (t_vector){0.0, 0.0, 1.0};
	if (e->hit->type == OBJ_SPHERE)
		normal = vdiv(vsub(ray, e->hit->loc), e->hit->radius);
	else if (e->hit->type == OBJ_PLANE)
		normal = e->hit->normal;
	else if (e->hit->type == OBJ_CYLINDER)
		normal = vsub(vsub(ray, e->hit->loc),
			vproject(vsub(ray, e->hit->loc), e->hit->dir));
	else if (e->hit->type == OBJ_CONE)
		normal = get_con_normal(e, ray);
	normal = vunit(normal);
	return (normal);
}
