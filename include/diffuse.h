/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diffuse.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/16 19:40:14 by adippena          #+#    #+#             */
/*   Updated: 2016/07/17 14:07:41 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIFFUSE_H
# define DIFFUSE_H

# include "rtv1.h"

typedef struct	s_diffuse
{
	t_material	*mat;
	t_light		*light;
	t_vector	ray;
	t_vector	normal;
	t_vector	light_dir;
	t_vector	view_dir;
	t_vector	half_dir;
	t_vector	colour;
	double		lambert;
	double		specular;
	double		spec_angle;
	double		shade;
	double		distance;
	size_t		i;
}				t_diffuse;

#endif
