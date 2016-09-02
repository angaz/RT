/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/09 17:40:01 by adippena          #+#    #+#             */
/*   Updated: 2016/08/26 22:47:21 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*strnl(const char *buff, size_t *pos, size_t stop)
{
	size_t	len;
	size_t	offset;

	len = 0;
	offset = *pos;
	while (buff[*pos] != '\n' && *pos < stop)
	{
		*pos += 1;
		len++;
	}
	return (ft_strsub(buff, offset, len));
}

static char		*sjoin(char *buff, size_t *pos, size_t eob, char *temp_line)
{
	char	*temp;
	char	*temp_nl;

	temp_nl = strnl(buff, pos, eob);
	if ((temp = ft_strjoin(temp_line, temp_nl)) == NULL)
		return (NULL);
	ft_strdel(&temp_line);
	ft_strdel(&temp_nl);
	return (temp);
}

int				ft_gnl(const int fd, char **line)
{
	static size_t	pos = BUFF_SIZE;
	static ssize_t	eob = BUFF_SIZE;
	static char		buff[BUFF_SIZE];
	char			*temp_line;

	temp_line = ft_strnew(1);
	while (buff[pos] != '\n' && eob > 0)
	{
		if ((ssize_t)pos == eob)
			if (((pos = 0) == 0) &&
				((eob = read(fd, buff, BUFF_SIZE)) == -1))
				return (-1);
		if ((temp_line = sjoin(buff, &pos, eob, temp_line)) == NULL)
			return (-1);
	}
	if (ft_strlen(temp_line) == 0 && buff[pos] != '\n')
		ft_strdel(&temp_line);
	if ((ssize_t)pos != eob)
		pos++;
	if (eob == 0 && ((pos = BUFF_SIZE) == BUFF_SIZE) &&
		((eob = BUFF_SIZE) == BUFF_SIZE))
		return (0);
	*line = temp_line;
	return (ft_strlen(*line));
}
