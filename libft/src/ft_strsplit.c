/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/15 11:30:36 by adippena          #+#    #+#             */
/*   Updated: 2016/05/15 11:50:47 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	size_t	words;
	size_t	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] && s[i] != c)
			i++;
		while (s[i] && s[i] == c)
			i++;
		words++;
	}
	return (words);
}

static char	*next_word(const char *s, char c, size_t *len)
{
	*len = 0;
	while (*s && *s == c)
		s++;
	while (s[*len] && s[*len] != c)
		(*len)++;
	return ((char *)s);
}

char		**ft_strsplit(char const *s, char c)
{
	char		**arr;
	size_t		words;
	size_t		wordl;
	size_t		i;

	i = 0;
	words = count_words(s, c);
	arr = (char **)malloc(sizeof(char *) * words);
	if (arr == NULL)
		return (NULL);
	while (i < words)
	{
		s = next_word(s, c, &wordl);
		arr[i] = (char *)ft_strsub(s, 0, wordl);
		if (arr[i] == NULL)
			return (NULL);
		s += wordl;
		i++;
	}
	return (arr);
}
