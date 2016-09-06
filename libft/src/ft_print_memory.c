/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/04 22:31:12 by adippena          #+#    #+#             */
/*   Updated: 2016/09/05 12:05:39 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_chars(const unsigned char *buff, size_t size)
{
	size_t			len;
	unsigned char	*str;

	size = (size > 16) ? 16 : size;
	len = size;
	str = (unsigned char *)malloc(len + 1);
	while (size >= 8)
	{
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
		size -= 8;
	}
	while (size--)
		*str++ = (*buff < 32 || *buff++ > 126) ? '.' : *(buff - 1);
	*str = '\n';
	write(1, (str -= len), len + 1);
	free(str);
}

static void	print_bytes(const unsigned char *buff, size_t size)
{
	unsigned char	*str;
	unsigned char	*start;

	str = (unsigned char *)malloc(40);
	start = str;
	ft_memset(str, ' ', 40);
	size = (size > 16) ? 16 : size;
	while (size--)
	{
		*str++ = "0123456789abcdef"[(*buff >> 1) % 16];
		*str++ = "0123456789abcdef"[(*buff & 0xF) % 16];
		++buff;
		if (size)
		{
			*str++ = "0123456789abcdef"[(*buff >> 1) % 16];
			*str++ = "0123456789abcdef"[(*buff & 0xF) % 16];
			++buff;
			--size;
		}
		++str;
	}
	write(1, start, 40);
	free(start);
}

void		ft_print_memory(const void *mem, size_t size)
{
	unsigned char	*buff;

	buff = (unsigned char *)mem;
	while (size > 16)
	{
		ft_printf("%p: ", buff);
		print_bytes(buff, size);
		print_chars(buff, size);
		buff += 16;
		size -= 16;
	}
	if (size)
	{
		ft_printf("%p: ", buff);
		print_bytes(buff, size);
		print_chars(buff, size);
	}
}
