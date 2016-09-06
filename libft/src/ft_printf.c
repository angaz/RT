/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/17 12:57:51 by adippena          #+#    #+#             */
/*   Updated: 2016/09/05 12:09:17 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*my_char_to_str(char c)
{
	char	*str;

	str = ft_strnew(2);
	str[0] = c;
	return (str);
}

static char	*my_recognise_arg(char c, va_list ap)
{
	if (c == 's')
		return (ft_strdup(va_arg(ap, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_itoa(va_arg(ap, int)));
	else if (c == 'u')
		return (ft_uitoa(va_arg(ap, unsigned int)));
	else if (c == 'o')
		return (ft_uitoa_base(va_arg(ap, unsigned int), 8));
	else if (c == 'x')
		return (ft_uitoa_base(va_arg(ap, unsigned int), 16));
	else if (c == 'X')
		return (ft_strto(ft_uitoa_base(va_arg(ap, unsigned int), 16),
			ft_toupper));
	else if (c == 'c')
		return (my_char_to_str(va_arg(ap, int)));
	else if (c == 'p')
		return (ft_uitoa_base((uintptr_t)va_arg(ap, void *), 16));
	else if (c == 'P')
		return (ft_uitoa_base((uintptr_t)va_arg(ap, void *), 16));
		return (NULL);
}

static char	*get_next_percent(const char *format, char *str, size_t *offset)
{
	size_t	len;
	size_t	pos;
	char	*temp;
	char	*new_temp;

	len = 0;
	pos = *offset;
	while (format[*offset] != '%' && format[*offset] != '\0')
	{
		*offset += 1;
		len++;
	}
	temp = ft_strsub(format, pos, len);
	new_temp = ft_strjoin(str, temp);
	ft_strdel(&str);
	ft_strdel(&temp);
	return (new_temp);
}

static int	print(char **str)
{
	int		len;

	ft_putstr(*str);
	len = ft_strlen(*str);
	ft_strdel(str);
	return (len);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	char	*str;
	char	*temp;
	char	*new_temp;
	size_t	offset;

	va_start(ap, format);
	offset = 0;
	str = ft_strnew(1);
	while (format[offset] != '\0')
		if (format[offset] != '%')
			str = get_next_percent(format, str, &offset);
		else
		{
			temp = my_recognise_arg(format[offset + 1], ap);
			new_temp = ft_strjoin(str, temp);
			ft_strdel(&str);
			ft_strdel(&temp);
			str = new_temp;
			offset += 2;
		}
	return (print(&str));
}
