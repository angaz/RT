/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:43:57 by adippena          #+#    #+#             */
/*   Updated: 2016/07/26 14:45:30 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_free_split(t_split_string *split)
{
	size_t	i;

	i = 0;
	while (i < split->words)
		ft_strdel(&split->strings[i++]);
	if (split->strings)
		free(split->strings);
	split->words = 0;
}
