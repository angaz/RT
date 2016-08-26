/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_rot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:18:56 by adippena          #+#    #+#             */
/*   Updated: 2016/08/25 16:55:12 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

inline t_vector	vrotx(t_vector v, double angle)
{
	return (t_vector){
		v.x,
		v.y * cos(angle) - v.z * sin(angle),
		v.y * sin(angle) + v.z * cos(angle)};
}

inline t_vector	vroty(t_vector v, double angle)
{
	return (t_vector){
		v.x * cos(angle) + v.z * sin(angle),
		v.y,
		v.z * cos(angle) + v.x * sin(angle)};
}

inline t_vector	vrotz(t_vector v, double angle)
{
	return (t_vector){
		v.x * cos(angle) - v.y * sin(angle),
		v.x * sin(angle) - v.y * cos(angle),
		v.z};
}

inline t_vector	vrot(t_vector v, double angle)
{
	t_vector	res;

	res = vrotx(v, angle);
	res = vroty(res, angle);
	res = vrotz(res, angle);
	return (res);
}
