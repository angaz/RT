/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_vector.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/05 15:53:16 by adippena          #+#    #+#             */
/*   Updated: 2016/08/15 16:26:25 by rojones          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

t_vector	get_vector(t_env *e, t_split_string values)
{
	t_vector	res;

	if (values.words != 3)
		err(FILE_FORMAT_ERROR, "get_vector", e);
	res = (t_vector){
		ft_atod(values.strings[0]),
		ft_atod(values.strings[1]),
		ft_atod(values.strings[2])};
	return (res);
}

t_vector	get_unit_vector(t_env *e, t_split_string values)
{
	t_vector	res;

	if (values.words != 3)
		err(FILE_FORMAT_ERROR, "get_vector", e);
	res = vunit((t_vector){
		ft_atod(values.strings[0]),
		ft_atod(values.strings[1]),
		ft_atod(values.strings[2])});
	return (res);
}
