##
## EPITECH PROJECT, 2024
## lib
## File description:
## Makefile
##

.PHONY: clean fclean

GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[01;33m
BLUE=\e[1;34m
NC=\033[0m

LIB_FOLDER = ./src/

LIB = 	$(LIB_FOLDER)my_pointlen.c \
		$(LIB_FOLDER)my_put_nbr.c \
		$(LIB_FOLDER)my_putstr.c \
		$(LIB_FOLDER)my_strcmpstart.c \
		$(LIB_FOLDER)my_strlen.c \
		$(LIB_FOLDER)my_putchar.c \
		$(LIB_FOLDER)my_strcpy.c \
		$(LIB_FOLDER)my_strdup.c \
		$(LIB_FOLDER)my_strndup.c \
		$(LIB_FOLDER)my_strndup.c \
		$(LIB_FOLDER)concat_params.c \
		$(LIB_FOLDER)my_show_word_array.c \
		$(LIB_FOLDER)append_to_all.c \
		$(LIB_FOLDER)my_strcat.c \
		$(LIB_FOLDER)append_list.c \
		$(LIB_FOLDER)remove_insert_list.c \
		$(LIB_FOLDER)my_strcmp.c \
		$(LIB_FOLDER)my_del_list_current.c \
		$(LIB_FOLDER)my_apply_on_matching_nodes.c \
		$(LIB_FOLDER)my_apply_on_nodes.c \
		$(LIB_FOLDER)my_concat_list.c \
		$(LIB_FOLDER)my_delete_nodes.c \
		$(LIB_FOLDER)my_find_node.c \
		$(LIB_FOLDER)my_list_size.c \
		$(LIB_FOLDER)my_invert_list.c \
		$(LIB_FOLDER)my_params_to_list.c \
		$(LIB_FOLDER)my_rev_list.c \
		$(LIB_FOLDER)my_show_linked_list.c \
		$(LIB_FOLDER)my_insert_back_list.c \
		$(LIB_FOLDER)my_insert_front_list.c \
		$(LIB_FOLDER)my_getnbr.c \
		$(LIB_FOLDER)overflow_add.c \
		$(LIB_FOLDER)overflow_mult.c \
		$(LIB_FOLDER)my_nbrlen.c \
		$(LIB_FOLDER)my_strstr.c \
		$(LIB_FOLDER)my_int_to_str.c \
		$(LIB_FOLDER)my_revstr.c \
		$(LIB_FOLDER)create_window.c \
		$(LIB_FOLDER)close_window.c \
		$(LIB_FOLDER)my_str_to_word_array.c \
		$(LIB_FOLDER)absolue.c \
		$(LIB_FOLDER)free_array.c \
		$(LIB_FOLDER)get_filesize.c \
		$(LIB_FOLDER)my_strcat_assets.c \
		$(LIB_FOLDER)open_file.c \
		$(LIB_FOLDER)str_to_word_array.c \
		$(LIB_FOLDER)swap_node.c \
		$(LIB_FOLDER)my_strcpy_str_word_array.c	\

APP = ./src/app/

OBJ = $(SRC:.c=.o)

NAME	=	../libmy.a

CFLAGS	=	-Werror -Wall -Wextra -I../include/	\

CFLAGS_LIB 	=	-I./include/ -Wall -Wextra

OBJ = $(LIB:.c=.o)

all:	$(OBJ)
	@ar rc $(NAME) $(OBJ)

clean:
	@rm -f *.gcda
	@rm -f *.gcno
	@rm -f $(OBJ)
	@printf "$(RED)[🚫]$(BLUE)Clean LIBRARY$(NC)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(RED)[🚫]$(BLUE)Fclean LIBRARY$(NC)\n"

%.o: %.c
	@printf "$(RED)[⚒️ $(YELLOW)]$(BLUE) Compiling, $(GREEN)$@$(NC)\n"
	@gcc -c $(CFLAGS) $< -o $@
