/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 09:40:33 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 17:27:51 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_CONE_H
# define INTERSECT_CONE_H

# include "rt.h"

typedef struct	s_intersect_cone
{
	double		a;
	double		b;
	double		c;
	double		d;
	double		cos2;
	double		sin2;
	double		v_va;
	double		dp_va;
	t_vector	dist;
	t_vector	a_v;
	t_vector	c_v;
}				t_intersect_cone;

#endif
