##
## EPITECH PROJECT, 2020
## MUL_my_world_2020
## File description:
## Project Makefile
##

DSRC	=	./src/

SRC	=	$(DSRC)main.c										\
		$(DSRC)constant.c									\
		$(DSRC)utility/math.c								\
		$(DSRC)utility/tool.c								\
		$(DSRC)utility/schr_extension.c						\
		$(DSRC)utility/perlin_noise.c						\
		$(DSRC)utility/read_file.c							\
		$(DSRC)window/window_create_destroy.c				\
		$(DSRC)window/window_reload.c						\
		$(DSRC)window/window_run.c							\
		$(DSRC)window/software_status_init.c				\
		$(DSRC)object/object_create.c						\
		$(DSRC)object/object_lines_create.c					\
		$(DSRC)object/object_2d_matrix_create.c				\
		$(DSRC)object/object_destroy.c						\
		$(DSRC)object/object_display.c						\
		$(DSRC)object/object_project_iso_point.c			\
		$(DSRC)object/object_texture_create.c				\
		$(DSRC)object/object_reload.c						\
		$(DSRC)object/object_tools_view.c					\
		$(DSRC)object/object_on_map.c						\
		$(DSRC)object/object_config.c						\
		$(DSRC)map/filemap/load_map.c						\
		$(DSRC)map/filemap/save_map.c						\
		$(DSRC)map/filemap/load_from_argv.c					\
		$(DSRC)map/filemap/fill_map.c						\
		$(DSRC)map/generator/map_generator.c				\
		$(DSRC)map/generator/map_generator_default.c		\
		$(DSRC)map/generator/map_generator_square.c			\
		$(DSRC)map/generator/map_texture_set_height.c		\
		$(DSRC)map/tool/height/map_tool_edit_height.c		\
		$(DSRC)map/tool/height/tool_mode_area.c				\
		$(DSRC)map/tool/height/tool_mode_corner.c			\
		$(DSRC)map/tool/height/tool_mode_tiles.c			\
		$(DSRC)map/tool/texture/map_tool_edit_texture.c		\
		$(DSRC)map/tool/texture/tool_mode_area.c			\
		$(DSRC)map/tool/texture/tool_mode_corner.c			\
		$(DSRC)map/tool/texture/tool_mode_tiles.c			\
		$(DSRC)map/map_scale.c								\
		$(DSRC)map/map_reset.c								\
		$(DSRC)map/map_tools_view.c							\
		$(DSRC)map/map_vertex_create_destroy.c				\
		$(DSRC)map/map_texture_vertex_create_destroy.c		\
		$(DSRC)map/map_texture_create_destroy.c				\
		$(DSRC)map/map_create_destroy.c						\
		$(DSRC)map/map_3d_create_destroy.c					\
		$(DSRC)map/map_2d_create_destroy.c					\
		$(DSRC)map/map_display.c							\
		$(DSRC)map/map_display_water.c						\
		$(DSRC)map/project_iso_point.c						\
		$(DSRC)map/map_update.c								\
		$(DSRC)map/map_resize.c								\
		$(DSRC)event/event_manager.c						\
		$(DSRC)event/event_init.c							\
		$(DSRC)event/event_mouse.c							\
		$(DSRC)event/event_keyboard.c						\
		$(DSRC)event/event_window.c							\
		$(DSRC)event_action/action_mouse_gui_button.c		\
		$(DSRC)event_action/action_gui_button_left.c		\
		$(DSRC)event_action/action_gui_button_top.c			\
		$(DSRC)event_action/action_resize_shortcut.c		\
		$(DSRC)event_action/action_mouse_clicked.c			\
		$(DSRC)event_action/action_show_click.c				\
		$(DSRC)event_action/action_texture.c				\
		$(DSRC)event_action/action_manager.c				\
		$(DSRC)event_action/action_map_file.c				\
		$(DSRC)event_action/action_update_text_gui.c		\
		$(DSRC)event_action/action_object_move.c			\
		$(DSRC)event_action/action_ui_button_tool.c 		\
		$(DSRC)input/button/button_config_boolean.c			\
		$(DSRC)input/button/button_config_char.c			\
		$(DSRC)input/button/button_config_color.c			\
		$(DSRC)input/button/button_create_destroy.c			\
		$(DSRC)input/button/button_display.c				\
		$(DSRC)input/button/button_get_status.c				\
		$(DSRC)input/button/button_poll_event.c				\
		$(DSRC)input/button/button_set_position.c			\
		$(DSRC)input/button/button_set_size.c				\
		$(DSRC)input/button/button_set_status.c				\
		$(DSRC)input/slider/slider_create_destroy.c			\
		$(DSRC)input/slider/slider_display.c				\
		$(DSRC)input/slider/slider_poll_event.c				\
		$(DSRC)input/slider/slider_get_value.c				\
		$(DSRC)input/text/text_input_create_destroy.c		\
		$(DSRC)input/text/text_input_config_char.c			\
		$(DSRC)input/text/text_input_config.c				\
		$(DSRC)input/text/text_input_get_input.c			\
		$(DSRC)input/text/text_input_run.c					\
		$(DSRC)input/image_viewer/image_viewer_create_destroy.c		\
		$(DSRC)input/texture_menu/texture_menu_create_sprite.c		\
		$(DSRC)input/image_viewer/image_viewer_display.c			\
		$(DSRC)input/image_viewer/image_viewer_update_status.c		\
		$(DSRC)input/texture_menu/texture_menu_create_destroy.c		\
		$(DSRC)input/texture_menu/texture_menu_display.c			\
		$(DSRC)input/texture_menu/texture_menu_update_status.c		\
		$(DSRC)gui/gui_create.c						\
		$(DSRC)gui/gui_destroy.c					\
		$(DSRC)gui/gui_display.c					\
		$(DSRC)gui/gui_label_create.c				\
		$(DSRC)gui/gui_panel_update.c				\
		$(DSRC)gui/button_sizes.c					\
		$(DSRC)gui/gui_shapes_create_destroy.c		\
		$(DSRC)gui/create_leftbar.c					\
		$(DSRC)sound/sound_manager.c				\


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
