# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adippena <angusdippenaar@gmail.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/08/26 18:13:07 by adippena          #+#    #+#              #
#    Updated: 2016/08/27 11:34:04 by adippena         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
INCLUDE	=	-I include
CFLAGS	=	-Wall -Wextra -Werror -Ofast -Wno-unused-result

#SRC		=	src/ft_atoi.c		src/ft_bzero.c		src/ft_isalnum.c		\
			src/ft_isalpha.c	src/ft_isascii.c	src/ft_isdigit.c		\
			src/ft_islower.c	src/ft_isprint.c	src/ft_isupper.c		\
			src/ft_itoa.c		src/ft_memalloc.c	src/ft_memccpy.c		\
			src/ft_memchr.c		src/ft_memcmp.c		src/ft_memcpy.c			\
			src/ft_memdel.c		src/ft_memmove.c	src/ft_memset.c			\
			src/ft_putchar.c	src/ft_putchar_fd.c	src/ft_putendl.c		\
			src/ft_putendl_fd.c	src/ft_putnbr.c		src/ft_putnbr_fd.c		\
			src/ft_putstr.c		src/ft_putstr_fd.c	src/ft_strcat.c			\
			src/ft_strchr.c		src/ft_strclr.c		src/ft_strcmp.c			\
			src/ft_strcpy.c		src/ft_strdel.c		src/ft_strdup.c			\
			src/ft_strequ.c		src/ft_striter.c	src/ft_striteri.c		\
			src/ft_strjoin.c	src/ft_strlcat.c	src/ft_strlen.c			\
			src/ft_strmap.c		src/ft_strmapi.c	src/ft_strncat.c		\
			src/ft_strncmp.c	src/ft_strncpy.c	src/ft_strnequ.c		\
			src/ft_strnew.c		src/ft_strnstr.c	src/ft_strrchr.c		\
			src/ft_strsplit.c	src/ft_strstr.c		src/ft_strsub.c			\
			src/ft_strtrim.c	src/ft_tolower.c	src/ft_toupper.c		\
			src/ft_strrev.c		src/ft_printf.c		src/ft_uitoa_base.c		\
			src/ft_uitoa.c		src/ft_strtoupper.c	src/ft_gnl.c			\
			src/ft_nstrsplit.c	src/ft_swap.c		src/ft_atoi_hex.c		\
			src/ft_memswap.c	src/ft_float_swap.c	src/ft_sprintf.c		\
			src/ft_atod.c		src/ft_free_split.c	src/ft_dtoa.c			\
			src/ft_itoa_base.c	src/ft_btrue.c

INC		=	$(shell find include -name "*.h")
SRC		=	$(shell find src -name "*.c")
OBJ		=	$(SRC:src/%.c=build/%.o)

all: $(NAME)

build/%.o: src/%.c include/libft.h
	@echo "\033[94mLFT CC    $@\033[0m"
	@mkdir -p $(dir $@)
	@gcc $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	@echo "\033[94mLFT AR    $@\033[0m"
	@ar cr $@ $^
	@ranlib $@

clean:
	@echo "\033[94mLFT RM    object files\033[0m"
	@rm -rf build

fclean: clean
	@echo "\033[94mLFT RM    $(NAME)\033[0m"
	@rm -f $(NAME)

re: fclean all
