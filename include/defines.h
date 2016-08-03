/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:48:13 by adippena          #+#    #+#             */
/*   Updated: 2016/08/03 13:34:21 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

/*#define max(a, b) ({__typeof__ (a) _a = (a); __typeof__ (b) _b = (b); \
	_a > _b ? _a : _b;}) */

# define MAX(a, b) ((a > b) ? a : b)

/*
** WINDOW DEFINES
*/
# define WIN_X	1600
# define WIN_Y	900

/*
** SHAPE DEFINES
*/
# define OBJ_SPHERE		1
# define OBJ_PLANE		2
# define OBJ_CONE		3
# define OBJ_CYLINDER	4

/*
** ERROR DEFINES
*/
# define FILE_OPEN_ERROR	0
# define MALLOC_ERROR		1
# define FREE_ERROR			2
# define FILE_FORMAT_ERROR	16
# define USAGE_ERROR		32

#endif
