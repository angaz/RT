/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_split_strings.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 09:58:17 by adippena          #+#    #+#             */
/*   Updated: 2016/07/16 17:00:34 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		free_split_strings(t_split_string *split)
{
	size_t	i;

	i = 0;
	while (i < split->words)
	{
		ft_strdel(&split->strings[i]);
		++i;
	}
	if (split->strings)
		free(split->strings);
	split->words = 0;
}
