/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 13:04:04 by adippena          #+#    #+#             */
/*   Updated: 2016/07/17 13:04:14 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	size_t	len;
	size_t	start;
	char	temp;

	len = ft_strlen(str);
	start = 0;
	while (start++ != len--)
	{
		temp = str[start];
		str[start] = str[len];
		str[len] = temp;
	}
	return (str);
}
