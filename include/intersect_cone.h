/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cone.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 09:40:33 by adippena          #+#    #+#             */
/*   Updated: 2016/08/20 10:06:02 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_CONE_H
# define INTERSECT_CONE_H

# include "rt.h"

typedef struct	s_intersect_cone
{
	t_quad		quad;
	double		cos2;
	double		sin2;
	double		v_va;
	double		dp_va;
	t_vector	dist;
	t_vector	a_v;
	t_vector	c_v;
}				t_intersect_cone;

typedef struct s_cone_normal
{
	t_vector    pro;
	t_vector    normal;
	t_vector    rot;
	t_vector    p_par;
	t_vector    p_orth;
	t_vector    nnor_orth;
}				t_cone_normal;

#endif
