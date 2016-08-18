/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_material.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 07:50:06 by rojones           #+#    #+#             */
/*   Updated: 2016/08/17 17:26:10 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_material(t_material **material, size_t num_mat)
{
	if(material)
	{
		while (num_mat--)
		{
			ft_strdel(&material[num_mat]->name);
			if (material[num_mat])
				free(material[num_mat]);
			material[num_mat] = NULL;
		}

		free(material);
	}
}
