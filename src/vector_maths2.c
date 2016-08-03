/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:26:54 by adippena          #+#    #+#             */
/*   Updated: 2016/08/03 12:04:04 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		vdot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double		vnormalize(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	vunit(t_vector v)
{
	return (vdiv(v, vnormalize(v)));
}

t_vector	colour_to_vector(t_colour colour)
{
	return ((t_vector){colour.r, colour.g, colour.b});
}

/*
** Returns a vector parallel to B, but with a length based off A and the angle
** between A and B. Used for the diffuse shading of cones and cylinders
*/
t_vector	vproject(t_vector a, t_vector b)
{
	return (vmult(b, (vdot(a, b) / vdot(b, b))));
}
