/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_triangle.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 16:12:26 by adippena          #+#    #+#             */
/*   Updated: 2016/08/08 16:16:49 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_TRIANGLE_H
# define INTERSECT_TRIANGLE_H

# include "rt.h"

typedef struct	s_intersect_triangle
{
	t_vector	edge1;
	t_vector	edge2;
	t_vector	p;
	t_vector	q;
	t_vector	dist;
	double		d;
	double		inverse_d;
	double		u;
	double		v;
	double		t0;
}				t_intersect_triangle;

#endif
