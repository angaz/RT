/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_object.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rojones <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/17 08:05:34 by rojones           #+#    #+#             */
/*   Updated: 2016/08/20 11:03:49 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

void	free_object(t_object **obj, size_t num_obj)
{
	if (obj)
	{
		while (num_obj--)
		{
			if (obj[num_obj])
			{
				ft_strdel(&obj[num_obj]->name);
				free_obj_vert((void**)(obj[num_obj]->face),
						obj[num_obj]->faces);
				free_obj_vert((void**)(obj[num_obj]->v),
						obj[num_obj]->verticies);
				free_obj_vert((void**)(obj[num_obj]->vn),
						obj[num_obj]->vnormals);
				free(obj[num_obj]);
				obj[num_obj] = NULL;
			}
		}
		free(obj);
		obj = NULL;
	}
}
