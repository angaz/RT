/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_maths.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 20:01:01 by adippena          #+#    #+#             */
/*   Updated: 2016/08/03 12:02:56 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vmult(t_vector v, double s)
{
	t_vector	res;

	res.x = v.x * s;
	res.y = v.y * s;
	res.z = v.z * s;
	return (res);
}

t_vector	vdiv(t_vector v, double d)
{
	t_vector	res;

	res.x = v.x / d;
	res.y = v.y / d;
	res.z = v.z / d;
	return (res);
}

t_vector	vadd(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}

t_vector	vsub(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x - v2.x;
	res.y = v1.y - v2.y;
	res.z = v1.z - v2.z;
	return (res);
}

t_vector	vcross(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.y * v2.z - v1.z * v2.y;
	res.y = v1.z * v2.x - v1.x * v2.z;
	res.z = v1.x * v2.y - v1.y * v2.x;
	return (res);
}
