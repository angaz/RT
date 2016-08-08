# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/09 12:47:08 by adippena          #+#    #+#              #
#    Updated: 2016/08/08 16:28:30 by adippena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	RT
LIBFT		=	-I libft/include -L libft -lft
SDL2		=	$(shell sdl2-config --cflags --libs)
INCLUDE		=	-I include
CFLAGS		=	-Wall -Wextra -Werror -Wuninitialized -pthread
LIBS		=	-lm

## PLEASE TRY AND KEEP THE SOURCE FILES IN ALPHABETICAL ORDER ##

INTERSECT	=	src/intersect/intersect_scene.c		\
				src/intersect/intersect_sphere.c	\
				src/intersect/intersect_plane.c		\
				src/intersect/intersect_cylinder.c	\
				src/intersect/intersect_cone.c		\
				src/intersect/intersect_triangle.c

READ_SCENE	=	src/read_scene/camera_values.c		\
				src/read_scene/light_values.c		\
				src/read_scene/material_values.c	\
				src/read_scene/object_values.c		\
				src/read_scene/read_colour.c		\
				src/read_scene/read_scene.c			\
				src/read_scene/read_vector.c		\
				src/read_scene/read_triangle.c

MATHS		=	src/vector_maths/colour_to_unit.c	\
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

SRC			=	$(INTERSECT)						\
				$(MATHS)							\
				$(READ_SCENE)						\
				src/camera_setup.c					\
				src/diffuse.c						\
				src/draw.c							\
				src/error.c							\
				src/init_env.c						\
				src/loop.c							\
				src/main.c							\
				src/shadow.c

all: $(NAME)

$(NAME):
	make -C libft all
	gcc $(CFLAGS) $(INCLUDE) $(SRC) $(SDL2) $(LIBFT) $(LIBS) -o $(NAME)

clean:
	make -C libft clean

fclean:
	make -C libft fclean
	rm -f $(NAME)
	rm -rf $(NAME).dSYM

re: fclean all

run:
	rm -f $(NAME)
	@$(MAKE) all
	@clear
	@./$(NAME) scene
