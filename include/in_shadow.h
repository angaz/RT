/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   in_shadow.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 10:39:15 by rojones           #+#    #+#             */
/*   Updated: 2016/08/20 10:48:31 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IN_SHADOW_H
# define IN_SHADOW_H

typedef struct	s_in_shadow
{
	t_ray		ray;
	double		t;
	double		distance;
	size_t		prim;
	size_t		face;
	size_t		object;
	t_object	*o;
}				t_in_shadow;

#endif
