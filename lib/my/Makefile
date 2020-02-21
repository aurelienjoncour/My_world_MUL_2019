##
## EPITECH PROJECT, 2019
## LIBMY_2019
## File description:
## LIBMY Makefile
##

SRC	=	my_compute_power_rec.c			\
		my_compute_square_root.c		\
		convert_base.c					\
		my_factorial_it.c				\
		my_power_rec.c					\
		my_sqrt.c						\
		my_find_prime_sup.c				\
		my_getnbr.c						\
		my_getnbr_base.c				\
		get_next_line.c					\
		my_isneg.c						\
		my_is_prime.c					\
		my_putchar.c					\
		my_putstr_error.c				\
		my_putnbr_base.c				\
		my_putnbr_base_str.c			\
		my_put_nbr.c					\
		my_putstr.c						\
		my_revstr.c						\
		my_showmem.c					\
		my_showstr.c					\
		my_sort_int_array.c				\
		my_advanced_sort_word_array.c 	\
		my_show_word_array.c 			\
		my_sort_word_array.c 			\
		my_str_to_word_array.c 			\
		my_strcapitalize.c				\
		my_strcat.c						\
		my_strcmp.c		\
		my_strcpy.c		\
		my_strdup.c		\
		my_str_isalpha.c	\
		my_str_islower.c	\
		my_str_isnum.c		\
		my_str_isprintable.c	\
		my_str_isupper.c	\
		my_strlen.c		\
		my_strlowcase.c		\
		my_strncat.c		\
		my_strncmp.c		\
		my_strncpy.c		\
		my_strstr.c		\
		my_strupcase.c		\
		my_swap.c		\
		my_printf.c             \
		my_put_double.c         \
		my_printf_display.c     \
		my_printf_disp01.c      \
		my_printf_disp02.c      \
		my_printf_disp03.c	\
		my_printf_disp_misc.c   \
		my_printf_misc.c        \
		my_printf_search.c	\
		quick_sort.c		\
		my_strndup.c		\
		word_array.c		\
		read_entiere_file.c

DINCLUDE = ../../include

OBJ	=	$(SRC:.c=.o)

CFLAGS	=	-Wall -Wextra -I$(DINCLUDE) -g

NAME	=	libmy.a

all:	$(NAME)

$(NAME): $(OBJ)
	@cp my.h $(DINCLUDE)
	@cp my_printf.h $(DINCLUDE)
	@cp get_next_line.h $(DINCLUDE)
	@ar rc $(NAME) $(OBJ)

clean:
	@$(RM) $(OBJ)

fclean:	clean
	@$(RM) $(NAME)

re:	clean all
