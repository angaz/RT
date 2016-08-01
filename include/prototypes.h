/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prototypes.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adippena <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/26 14:49:05 by adippena          #+#    #+#             */
/*   Updated: 2016/08/01 22:37:12 by adippena         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PROTOTYPES_H
# define PROTOTYPES_H

/*
** src/vector_maths.c
*/
double		vector_dot(t_vector v1, t_vector v2);
double		vector_normalize(t_vector v);
t_vector	vector_mult(t_vector v, double s);
t_vector	vector_div(t_vector v, double d);
t_vector	vector_add(t_vector v1, t_vector v2);
t_vector	vector_sub(t_vector v1, t_vector v2);
t_vector	vector_cross(t_vector v1, t_vector v2);
t_vector	vector_unit(t_vector v);
t_vector	colour_to_vector(t_colour colour);
t_vector	vector_project(t_vector a, t_vector b);

/*
** vector_rot.c
*/
t_vector	vector_rot_x(t_vector v, double angle);
t_vector	vector_rot_y(t_vector v, double angle);
t_vector	vector_rot_z(t_vector v, double angle);

/*
** src/intersect_scene.c
*/
void		intersect_scene(t_env *e);

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
** src/read_scene.c
*/
void		read_scene(char *file, t_env *e);

/*
** src/object_values.c
*/
void		get_object_attributes(t_env *e, int fd);

/*
** src/free_split_strings.c
*/
void		free_split_strings(t_split_string *split);

/*
** src/camera_values.c
*/
void		get_camera_attributes(t_env *e, int fd);

/*
** src/light_values.c
*/
void		get_light_attributes(t_env *e, int fd);
t_colour	get_colour(t_env *e, t_split_string values);
t_vector	get_vector(t_env *e, t_split_string values);
t_vector	get_unit_vector(t_env *e, t_split_string values);

/*
** src/material_values.c
*/
void		get_material_attributes(t_env *e, int fd);

/*
** src/draw.c
*/
void		draw(t_env *e, SDL_Rect draw);
double		intersect_object(t_env *e, t_ray *ray, size_t object, double *t);

/*
** INTERSECTIONS : src/intersect[object].c
*/
int			intersect_sphere(t_ray *r, t_object *s, double *t);
int			intersect_plane(t_ray *r, t_object *o, double *t);
int			intersect_cylinder(t_ray *r, t_object *o, double *t);
int			intersect_cone(t_ray *r, t_object *o, double *t);

/*
** src/diffuse.c
*/
t_colour	diffuse_shade(t_env *e);

/*
** src/shadow.c
*/
double		in_shadow(t_env *e, t_light *light);

/*
** src/camera_setup.c
*/
void		setup_camera_plane(t_env *e, t_camera_ray *c);
void		get_ray_dir(t_env *e, t_camera_ray *cr, double x, double y);

#endif
