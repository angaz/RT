/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/07 14:57:03 by adippena          #+#    #+#             */
/*   Updated: 2016/08/07 15:28:53 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Vec3f edge0 = v1 - v0;
** Vec3f edge1 = v2 - v1;
** Vec3f edge2 = v0 - v2;
** Vec3f C0 = P - v0;
** Vec3f C1 = P - v1;
** Vec3f C2 = P - v2;
**  if (dotProduct(N, crossProduct(edge0, C0)) > 0 &&
**		dotProduct(N, crossProduct(edge1, C1)) > 0 &&
**		dotProduct(N, crossProduct(edge2, C2)) > 0) return true; // P inside
*/

int		intersect_tri(t_ray *r, t_object *o, double *t)
{
	t_vecot		p;

	if (intersect_plane(r, o, t))
	{
		p = vmult(r->dir, *t);
		if (vdot(o->normal, vcross(vsub(o->p2, o->p1), vsub(p, o->p1))) > 0 &&

	}
}
