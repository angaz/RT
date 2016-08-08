/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 12:10:39 by rojones           #+#    #+#             */
/*   Updated: 2016/08/08 12:11:38 by rojones          ###   ########.fr       */
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
		normal = vsub(vsub(ray, e->hit->loc),
			vproject(vsub(ray, e->hit->loc), e->hit->dir));
	normal = vunit(normal);
	return (normal);
}
