/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_add.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 12:45:10 by adippena          #+#    #+#             */
/*   Updated: 2016/08/05 12:45:31 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	vadd(t_vector v1, t_vector v2)
{
	t_vector	res;

	res.x = v1.x + v2.x;
	res.y = v1.y + v2.y;
	res.z = v1.z + v2.z;
	return (res);
}
