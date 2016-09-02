/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:30:44 by adippena          #+#    #+#             */
/*   Updated: 2016/07/09 16:58:16 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new_str;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = 0;
	if ((end = ft_strlen(s)))
	{
		while (s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			start++;
		while (s[end - 1] == ' ' || s[end - 1] == '\n' || s[end - 1] == '\t')
			end--;
	}
	new_str = ft_strnew((end - start) + 1);
	while (start < end)
		new_str[i++] = s[start++];
	return (new_str);
}
