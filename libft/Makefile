NAME = libft.a

SRC =	src/ft_atoi.c		src/ft_bzero.c		src/ft_isalnum.c		\
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
		src/ft_atod.c

OBJ = 	ft_atoi.o		ft_bzero.o		ft_isalnum.o	ft_isalpha.o	\
		ft_isascii.o	ft_isdigit.o	ft_islower.o	ft_isprint.o	\
		ft_isupper.o	ft_itoa.o		ft_memalloc.o	ft_memccpy.o	\
		ft_memchr.o		ft_memcmp.o		ft_memcpy.o		ft_memdel.o		\
		ft_memmove.o	ft_memset.o		ft_putchar.o	ft_putchar_fd.o	\
		ft_putendl.o	ft_putendl_fd.o	ft_putnbr.o		ft_putnbr_fd.o	\
		ft_putstr.o		ft_putstr_fd.o	ft_strcat.o		ft_strchr.o		\
		ft_strclr.o		ft_strcmp.o		ft_strcpy.o		ft_strdel.o		\
		ft_strdup.o		ft_strequ.o		ft_striter.o	ft_striteri.o	\
		ft_strjoin.o	ft_strcat.o		ft_strlen.o		ft_strmap.o		\
		ft_strmapi.o	ft_strncat.o	ft_strncmp.o	ft_strncpy.o	\
		ft_strnequ.o	ft_strnew.o		ft_strnstr.o	ft_strchr.o		\
		ft_strsplit.o	ft_strstr.o		ft_strsub.o		ft_strtrim.o	\
		ft_tolower.o	ft_toupper.o	ft_strrev.o		ft_printf.o		\
		ft_uitoa_base.o	ft_uitoa.o		ft_strtoupper.o	ft_gnl.o		\
		ft_nstrsplit.o	ft_swap.o		ft_atoi_hex.o	ft_memswap.o	\
		ft_float_swap.o	ft_sprintf.o	ft_atod.o

CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME):
	@gcc $(CFLAGS) -I include -c $(SRC)
	@ar cr $(NAME) $(OBJ)
	ranlib $(NAME)
	@mkdir -p build
	@mv *.o build/

clean:
	rm -f *.o
	rm -rf build

fclean: clean
	rm -f $(NAME)

re: fclean all
