/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_normalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 12:48:39 by adippena          #+#    #+#             */
/*   Updated: 2016/08/25 16:54:45 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

inline double		vnormalize(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}
