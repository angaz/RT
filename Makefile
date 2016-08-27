# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/08/27 11:03:18 by adippena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RT
LIBFT		=	-I libft/include -L libft -lft
SDL2		=	$(shell sdl2-config --cflags --libs)
INCLUDE		=	-I include
LIBS		=	-lm
CFLAGS		=	-Wall -Wextra -Werror -pthread -Ofast $(INCLUDE) $(SDL2) $(LIBFT) $(LIBS)
LFLAGS		=	-pthread $(INCLUDE) $(SDL2) $(LIBFT) $(LIBS)
CC			=	gcc
LD			=	gcc

## PLEASE TRY AND KEEP THE SOURCE FILES IN ALPHABETICAL ORDER ##

FREE		=	src/free/free_light.c				\
				src/free/free_material.c			\
				src/free/free_obj_vert.c			\
				src/free/free_object.c				\
				src/free/free_prim.c

INTERSECT	=	src/intersect/intersect_box.c		\
				src/intersect/intersect_scene.c		\
				src/intersect/intersect_sphere.c	\
				src/intersect/intersect_plane.c		\
				src/intersect/intersect_cylinder.c	\
				src/intersect/intersect_cone.c		\
				src/intersect/intersect_triangle.c	\
				src/intersect/intersect_object.c	\
				src/intersect/intersect_disk.c

READ_SCENE	=	src/read_scene/camera_values.c		\
				src/read_scene/light_values.c		\
				src/read_scene/material_values.c	\
				src/read_scene/object_values.c		\
				src/read_scene/primitive_values.c	\
				src/read_scene/read_colour.c		\
				src/read_scene/read_scene.c			\
				src/read_scene/read_obj.c			\
				src/read_scene/read_vector.c

MATHS		=	src/vector_maths/colour_to_unit.c	\
				src/vector_maths/vector_comp.c		\
				src/vector_maths/vector_add.c		\
				src/vector_maths/vector_cross.c		\
				src/vector_maths/vector_div.c		\
				src/vector_maths/vector_dot.c		\
				src/vector_maths/vector_mult.c		\
				src/vector_maths/vector_normalize.c	\
				src/vector_maths/vector_project.c	\
				src/vector_maths/vector_rot.c		\
				src/vector_maths/vector_sub.c		\
				src/vector_maths/vector_unit.c

SAVE		=	src/save/save.c						\
				src/save/save_lights.c				\
				src/save/save_materials.c			\
				src/save/save_objects.c				\
				src/save/save_prims.c				\
				src/save/write_coord.c

USER_INPUT	=	src/user_input/mouse_click.c		\
				src/user_input/key_press.c			\
				src/user_input/grab.c				\
				src/user_input/cam_move.c

SRC			=	$(FREE)								\
				$(INTERSECT)						\
				$(MATHS)							\
				$(READ_SCENE)						\
				$(SAVE)								\
				$(USER_INPUT)						\
				src/camera_setup.c					\
				src/diffuse.c						\
				src/draw.c							\
				src/error.c							\
				src/init_env.c						\
				src/loop.c							\
				src/main.c							\
				src/shadow.c						\
				src/get_normal.c					\
				src/reflect.c						\
				src/refract.c						\
				src/find_colour_struct.c			\
				src/copy_env.c

INC			=	include/defines.h					\
				include/diffuse.h					\
				include/draw.h						\
				include/in_shadow.h					\
				include/intersect_cone.h			\
				include/intersect_cylinder.h		\
				include/intersect_object.h			\
				include/intersect_triangle.h		\
				include/prototypes.h				\
				include/rt.h						\
				include/structs.h

all: lft rt

OBJ = $(SRC:.c=.o)

%.o: %.c $(INC)
	@echo "\033[92m    CC    $@\033[0m"
	@$(CC) $(CFLAGS) -c $< -o $@

rt: $(OBJ)
	@echo "\033[92m    LD    $(NAME)\033[0m"
	@$(LD) $^ $(LFLAGS) -o $(NAME)

lft:
	@make -s -C libft all

clean:
	@echo "\033[92m    RM    object files\033[0m"
	@rm -f $(OBJ)
	@make -s -C libft clean

fclean: clean
	@echo "\033[92m    RM    $(NAME)\033[0m"
	@rm -f $(NAME)
	@rm -rf $(NAME).dSYM
	@make -s -C libft fclean

re: fclean all
