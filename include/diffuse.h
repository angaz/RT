/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 19:40:14 by adippena          #+#    #+#             */
/*   Updated: 2016/08/03 13:38:03 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFUSE_H
# define DIFFUSE_H

# include "rt.h"

/*
** From intersection point::
**		n : normal of the surface
**		l : direction to light source
**		v : direction to the camera location
**		h : half-angle - bisector of v and l
*/

typedef struct	s_diffuse
{
	t_material	*mat;
	t_light		*light;
	t_vector	intersect;
	t_vector	n;
	t_vector	l;
	t_vector	v;
	t_vector	h;
	t_vector	colour;
	double		intensity;
	double		lambert;
	double		specular;
	double		spec_angle;
	double		dist;
}				t_diffuse;

#endif
