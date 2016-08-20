/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 08:00:54 by rojones           #+#    #+#             */
/*   Updated: 2016/08/20 11:01:59 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_light(t_light **light, size_t num_light)
{
	if (light)
	{
		while (num_light--)
		{
			if (light[num_light])
				free(light[num_light]);
			light[num_light] = NULL;
		}
		free(light);
		light = NULL;
	}
}
