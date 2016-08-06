/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_colour.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 15:54:07 by adippena          #+#    #+#             */
/*   Updated: 2016/08/06 13:40:42 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static double	to_range(double value, double min, double max)
{
	if (value < min)
		value = min;
	if (value > max)
		value = max;
	return (value);
}

t_colour		get_colour(t_env *e, t_split_string values)
{
	t_colour	res;
	char		*temp;

	res = (t_colour){0.0, 0.0, 0.0, 1.0};
	if (values.words == 1 || values.words == 2)
	{
		if (ft_strlen(values.strings[0]) != 6)
			err(FILE_FORMAT_ERROR, "get_colour", e);
		temp = ft_strnew(3);
		temp = ft_strncpy(temp, values.strings[0], 2);
		res.r = ft_atoi_hex(temp) / 255.0;
		ft_strdel(&temp);
		temp = ft_strncpy(temp, values.strings[0] + 2, 2);
		res.g = ft_atoi_hex(temp) / 255.0;
		ft_strdel(&temp);
		temp = ft_strncpy(temp, values.strings[0] + 4, 2);
		res.b = ft_atoi_hex(temp) / 255.0;
		ft_strdel(&temp);
	}
	if (values.words == 2)
		res.intensity = to_range(ft_atod(values.strings[1]), 0.0, 1.0);
	if (values.words > 2)
		err(FILE_FORMAT_ERROR, "get_colour", e);
	return (res);
}
