/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:18:56 by adippena          #+#    #+#             */
/*   Updated: 2016/08/05 12:56:23 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vrotx(t_vector v, double angle)
{
	t_vector	res;

	res.x = v.x;
	res.y = v.y * cos(angle) - v.z * sin(angle);
	res.z = v.y * sin(angle) + v.z * cos(angle);
	return (res);
}

t_vector	vroty(t_vector v, double angle)
{
	t_vector	res;

	res.x = v.x * cos(angle) + v.z * sin(angle);
	res.y = v.y;
	res.z = v.z * cos(angle) + v.x * sin(angle);
	return (res);
}

t_vector	vrotz(t_vector v, double angle)
{
	t_vector	res;

	res.x = v.x * cos(angle) - v.y * sin(angle);
	res.y = v.x * sin(angle) - v.y * cos(angle);
	res.z = v.z;
	return (res);
}

t_vector	vrot(t_vector v, double angle)
{
	t_vector	res;

	res = vrotx(v, angle);
	res = vroty(res, angle);
	res = vrotz(res, angle);
	return(res);
}
