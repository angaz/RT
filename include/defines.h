/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defines.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:48:13 by adippena          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2016/09/01 22:40:04 by adippena         ###   ########.fr       */
=======
/*   Updated: 2016/09/01 13:02:50 by adippena         ###   ########.fr       */
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFINES_H
# define DEFINES_H

# define MAX(a, b)			((a > b) ? a : b)
# define MIN(a, b)			((a < b) ? a : b)
<<<<<<< HEAD
# define EPSILON			0.000001
=======
# define EPSILON			0.00001
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
# define ARBITRARY_NUMBER	2.175

/*
** PRIMITIVE DEFINES
*/
# define PRIM_SPHERE		1
# define PRIM_PLANE			2
# define PRIM_CONE			3
# define PRIM_CYLINDER		4
# define PRIM_TRIANGLE		5
# define PRIM_DISK			6
# define PRIM_HEMI_SPHERE	7

# define PRIMITIVE			1
# define FACE				2

/*
** ERROR DEFINES
*/
# define FILE_OPEN_ERROR	0
# define MALLOC_ERROR		1
# define FREE_ERROR			2
# define FILE_FORMAT_ERROR	16
# define USAGE_ERROR		32

<<<<<<< HEAD
/*
** KEYS
*/
# define KEY_SHIFT			(1 << 0)
# define KEY_G				(1 << 1)
# define KEY_R				(1 << 2)
# define KEY_X				(1 << 3)
# define KEY_Y				(1 << 4)
# define KEY_Z				(1 << 5)
# define KEY_W				(1 << 6)
# define KEY_S				(1 << 7)
# define KEY_A				(1 << 8)
# define KEY_D				(1 << 9)
# define KEY_CTRL			(1 << 10)
# define KEY_SPACE			(1 << 11)
# define KEY_MID_CLICK		(1 << 12)

=======
>>>>>>> 30a4314a13a467cafffd81c84ca3427de211883a
#endif
