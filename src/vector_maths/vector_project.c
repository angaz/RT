/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_project.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 12:50:00 by adippena          #+#    #+#             */
/*   Updated: 2016/08/05 12:51:06 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

/*
** Returns a vector parallel to B, but with a length based off A and the angle
** between A and B. Used for the diffuse shading of cones and cylinders
*/
t_vector	vproject(t_vector a, t_vector b)
{
	return (vmult(b, (vdot(a, b) / vdot(b, b))));
}
