/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:28:51 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 17:28:00 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_CYLINDER_H
# define INTERSECT_CYLINDER_H

# include "rt.h"

typedef struct	s_int_cylinder
{
	double		a;
	double		b;
	double		c;
	double		d;
	t_vector	dist;
	t_vector	a_v;
	t_vector	c_v;
}				t_int_cylinder;

#endif
