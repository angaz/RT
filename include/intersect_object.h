/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_object.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/20 11:05:17 by rojones           #+#    #+#             */
/*   Updated: 2016/09/01 13:44:11 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERSECT_OBJECT_H
# define INTERSECT_OBJECT_H

typedef struct	s_intersect_box
{
	t_vector	inv_dir;
	int			sign[3];
	t_vector	min;
	t_vector	max;
}				t_intersect_box;

#endif
