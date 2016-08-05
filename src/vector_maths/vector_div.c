/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_div.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 12:43:10 by adippena          #+#    #+#             */
/*   Updated: 2016/08/05 12:43:31 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vdiv(t_vector v, double d)
{
	t_vector	res;

	res.x = v.x / d;
	res.y = v.y / d;
	res.z = v.z / d;
	return (res);
}
