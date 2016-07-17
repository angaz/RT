/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:30:13 by adippena          #+#    #+#             */
/*   Updated: 2016/05/15 12:35:05 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char			*new_str;
	unsigned int	i;

	new_str = NULL;
	i = 0;
	if (s)
		new_str = (char *)malloc(ft_strlen(s) + 1);
	if (!new_str || !s)
		return (NULL);
	while (s[i] != '\0')
	{
		new_str[i] = f(s[i]);
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}
