##
## EPITECH PROJECT, 2020
## MUL_my_world_2020
## File description:
## Project Makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.c								\
		$(DSRC)constant.c							\
		$(DSRC)map_tools.c							\
		$(DSRC)window_create_destroy.c				\
		$(DSRC)map/map_vertex_create_destroy.c		\
		$(DSRC)map/map_create_destroy.c				\
		$(DSRC)map/map-3d_create_destroy.c			\
		$(DSRC)map/map-2d_create_destroy.c			\
		$(DSRC)map/map_display.c					\
		$(DSRC)map/project_iso_point.c				\
		$(DSRC)map/map_update.c						\
		$(DSRC)event/event_manager.c				\
		$(DSRC)event/event_mouse.c					\


SRC_UT = $(DSRC)main.c								\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_world

CFLAGS	+= -Wall -Wextra -I./include -g

all:	$(NAME)

$(NAME):	LIB $(OBJ)
	gcc -o $(NAME) $(OBJ) -L./lib/my -lmy -lm -lcsfml-graphics -lcsfml-audio -lcsfml-window -lcsfml-system

LIB:
	make -C ./lib/my

clean:
	rm -f  $(OBJ)
	rm -f *.gcda
	rm -f *.gcno

fclean:	clean
	rm -f $(NAME)

re:	fclean all

#tests_run:
#gcc -o $(NAME) $(SRC_UT) tests/test_project.c -I./include -L./lib -lmy -lcriterion --coverage && ./$(NAME)

.PHONY :        clean fclean re
