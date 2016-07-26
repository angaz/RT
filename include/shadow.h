/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shadow.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 15:06:50 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 15:08:09 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADOW_H
# define SHADOW_H

typedef struct	s_shadow
{
	t_ray		ray;
	double		t;
	double		delta;
	double		distance;
	size_t		object;
}				t_shadow;

#endif
