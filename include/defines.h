/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:48:13 by adippena          #+#    #+#             */
/*   Updated: 2016/08/22 20:49:13 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define MAX(a, b)	((a > b) ? a : b)
# define EPSILON	0.000001

/*
** PRIMITIVE DEFINES
*/
# define PRIM_SPHERE	1
# define PRIM_PLANE		2
# define PRIM_CONE		3
# define PRIM_CYLINDER	4
# define PRIM_TRIANGLE	5
# define PRIM_DISK		6

# define PRIMITIVE		1
# define FACE			2

/*
** ERROR DEFINES
*/
# define FILE_OPEN_ERROR	0
# define MALLOC_ERROR		1
# define FREE_ERROR			2
# define FILE_FORMAT_ERROR	16
# define USAGE_ERROR		32

#endif
