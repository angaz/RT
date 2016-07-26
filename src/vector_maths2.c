/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:26:54 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 17:26:53 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

double		vector_dot(t_vector v1, t_vector v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}

double		vector_normalize(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

t_vector	vector_unit(t_vector v)
{
	return (vector_div(v, vector_normalize(v)));
}

t_vector	colour_to_vector(t_colour colour)
{
	return ((t_vector){colour.r, colour.g, colour.b});
}

/*
** Returns a vector parallel to B, but with a length based off A and the angle
** between A and B. Used for the diffuse shading of cones and cylinders
*/
t_vector	vector_project(t_vector a, t_vector b)
{
	return (vector_mult(b, (vector_dot(a, b) / vector_dot(b, b))));
}
