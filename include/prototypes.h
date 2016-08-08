/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:49:05 by adippena          #+#    #+#             */
/*   Updated: 2016/08/08 13:04:30 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*
** src/vector_maths
*/
double		vdot(t_vector v1, t_vector v2);
double		vnormalize(t_vector v);
t_vector	vmult(t_vector v, double s);
t_vector	vdiv(t_vector v, double d);
t_vector	vadd(t_vector v1, t_vector v2);
t_vector	vsub(t_vector v1, t_vector v2);
t_vector	vcross(t_vector v1, t_vector v2);
t_vector	vunit(t_vector v);
t_vector	vproject(t_vector a, t_vector b);
t_vector	colour_to_vector(t_colour colour);
t_vector	vrotx(t_vector v, double angle);
t_vector	vroty(t_vector v, double angle);
t_vector	vrotz(t_vector v, double angle);
t_vector	vrot(t_vector v, double angle);

/*
** src/loop.c
*/
void		event_loop(t_env *e);

/*
** src/init_env.c
*/
void		init_env(t_env *e, char **av);
void		nullify_pointers(t_env *e);

/*
** src/error.c
*/
void		err(int error_no, char *function, t_env *e);
void		exit_rt(t_env *e);

/*
** src/read_scene
*/
void		read_scene(char *file, t_env *e);
void		get_object_attributes(t_env *e, int fd);
void		get_camera_attributes(t_env *e, int fd);
void		get_light_attributes(t_env *e, int fd);
t_colour	get_colour(t_env *e, t_split_string values);
t_vector	get_vector(t_env *e, t_split_string values);
t_vector	get_unit_vector(t_env *e, t_split_string values);
void		get_material_attributes(t_env *e, int fd);

/*
** src/draw.c
*/
void		draw(t_env *e, SDL_Rect draw);
int			intersect_object(t_env *e, t_ray *ray, size_t object, double *t);

/*
** src/intersect
*/
void		intersect_scene(t_env *e);
int			intersect_sphere(t_ray *r, t_object *s, double *t);
int			intersect_plane(t_ray *r, t_object *o, double *t);
int			intersect_cylinder(t_ray *r, t_object *o, double *t);
int			intersect_cone(t_ray *r, t_object *o, double *t);
int			intersect_triangle(t_ray *r, t_object *o, double *t);

/*
** src/diffuse.c
*/
t_colour	diffuse_shade(t_env *e);

/*
** src/shadow.c
*/
int			in_shadow(t_env *e, t_light *light);

/*
** src/camera_setup.c
*/
void		setup_camera_plane(t_env *e, t_camera_ray *c);
void		get_ray_dir(t_env *e, t_camera_ray *cr, double x, double y);

#endif
