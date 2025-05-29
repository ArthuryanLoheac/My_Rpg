##
## EPITECH PROJECT, 2024
## Makefile
## File description:
## Compile files into a binary
##
GREEN=\033[0;32m
RED=\033[0;31m
YELLOW=\033[01;33m
BLUE=\e[1;34m
NC=\033[0m

.PHONY: clean fclean

APP = ./src/app/

SRC_FOLDER = ./src/

COMPUTE_FOLDER = ./src/compute/

ANALYSE_FOLDER = ./src/analyze/

MAKE_FOLDER = ./src/make/

INIT_FOLDER = ./src/init/

COLOR_FOLDER = ./src/color/

THREE_FOLDER = ./src/all_three/

DESTROY_FOLDER = ./src/destroy/

SAVE_FOLDER = ./src/save/

QUEST_FOLDER = ./src/quests/

APP_FOLDER = ./src/app/

LIB_FOLDER = ./lib/

GAMEPLAY_FOLDER = ./src/gameplay/

STATS_INVENTORY = ./src/inventory_stats/

GAMEPLAY_FOLDER = ./src/gameplay/

NPC_FOLDER = ./src/init/npc/

SCATTER_FOLDER = ./src/init/scatter/

SRC =	$(APP_FOLDER)my_rpg.c \
		$(SRC_FOLDER)analyse_events.c 	\
		$(SRC_FOLDER)check_continue.c 	\
		$(SRC_FOLDER)check_continue2.c	\
		$(SRC_FOLDER)isclicked.c \
		$(SRC_FOLDER)ishover.c \
		$(SRC_FOLDER)set_animate_image.c \
		$(SRC_FOLDER)send_script.c \
		$(SRC_FOLDER)remove_inhibitor.c \
		$(SRC_FOLDER)get_asset.c \
		$(SRC_FOLDER)vector_operation.c \
		$(SRC_FOLDER)vector_operation2.c \
		$(SRC_FOLDER)vector_operation3.c \
		$(SRC_FOLDER)vector_operation_info.c \
		$(SRC_FOLDER)drop_item.c \
		$(SRC_FOLDER)do_dialogue.c \
		$(SRC_FOLDER)get_sprite_entity.c \
		$(SRC_FOLDER)display_shoot.c	\
		$(SRC_FOLDER)display_shoot_init.c	\
		$(SRC_FOLDER)display_shoot_deviation.c	\
		$(SRC_FOLDER)get_nbr_slots_inv.c	\
		$(SRC_FOLDER)get_bg_color.c	\
		$(SRC_FOLDER)splash_screen.c	\
		$(SAVE_FOLDER)save_data.c	\
		$(SAVE_FOLDER)save_options.c	\
		$(SAVE_FOLDER)save_stats.c	\
		$(SAVE_FOLDER)save_quest.c	\
		$(SAVE_FOLDER)save_time.c	\
		$(SAVE_FOLDER)save_map.c	\
		$(SAVE_FOLDER)save_inventory.c	\
		$(SAVE_FOLDER)save_gender.c	\
		$(SAVE_FOLDER)save_hp.c \
		$(SAVE_FOLDER)save_class.c	\
		$(SAVE_FOLDER)save_npc.c	\
		$(SAVE_FOLDER)save_player.c	\
		$(SAVE_FOLDER)save_filepath.c	\
		$(COMPUTE_FOLDER)compute_diag_pipe.c	\
		$(COMPUTE_FOLDER)compute_button_state_escape.c \
		$(COMPUTE_FOLDER)compute_buttons_escape.c \
		$(COMPUTE_FOLDER)compute_buttons_level.c \
		$(COMPUTE_FOLDER)compute_add_hair_from_gender.c \
		$(COMPUTE_FOLDER)compute_echap.c \
		$(COMPUTE_FOLDER)update_position_entity.c \
		$(COMPUTE_FOLDER)set_volume_for_musics.c \
		$(COMPUTE_FOLDER)compute_health_bar.c \
		$(COMPUTE_FOLDER)compute_recap_shop.c \
		$(COMPUTE_FOLDER)compute_recap_inventory.c \
		$(COMPUTE_FOLDER)compute_answer.c	\
		$(COMPUTE_FOLDER)compute_map.c	\
		$(COMPUTE_FOLDER)compute_pc.c	\
		$(COMPUTE_FOLDER)compute_animation_hero.c \
		$(COMPUTE_FOLDER)compute_pause.c	\
		$(COMPUTE_FOLDER)compute_item.c \
		$(COMPUTE_FOLDER)compute_utilities_shop.c \
		$(COMPUTE_FOLDER)compute_keys_and_buttons.c \
		$(COMPUTE_FOLDER)compute_slider_pos.c \
		$(COMPUTE_FOLDER)compute_actual_size_list_shop.c \
		$(COMPUTE_FOLDER)compute_game.c	\
		$(COMPUTE_FOLDER)compute_menu_start.c \
		$(COMPUTE_FOLDER)compute_transfer_every_item_buyed.c \
		$(COMPUTE_FOLDER)compute_guis.c	\
		$(COMPUTE_FOLDER)compute_options.c \
		$(COMPUTE_FOLDER)compute_keybinds.c \
		$(COMPUTE_FOLDER)compute_choose_class.c \
		$(COMPUTE_FOLDER)compute_choose_stats.c \
		$(COMPUTE_FOLDER)compute_info.c	\
		$(COMPUTE_FOLDER)compute_animation_img.c \
		$(COMPUTE_FOLDER)compute_state_buttons_menu.c \
		$(COMPUTE_FOLDER)compute_shop.c \
		$(COMPUTE_FOLDER)compute_default_state_button.c \
		$(COMPUTE_FOLDER)compute_collision.c \
		$(COMPUTE_FOLDER)compute_quest.c \
		$(COMPUTE_FOLDER)compute_final_page.c \
		$(COMPUTE_FOLDER)compute_pos_x_offset.c \
		$(COMPUTE_FOLDER)compute_npc.c \
		$(COMPUTE_FOLDER)compute_scatter.c \
		$(COMPUTE_FOLDER)compute_entity.c \
		$(COMPUTE_FOLDER)compute_talk.c \
		$(COMPUTE_FOLDER)compute_movment.c \
		$(COMPUTE_FOLDER)start_fight.c \
		$(COMPUTE_FOLDER)end_fight.c \
		$(COMPUTE_FOLDER)compute_fight.c \
		$(COMPUTE_FOLDER)compute_fight_player.c \
		$(COMPUTE_FOLDER)compute_button_state_level.c \
		$(COMPUTE_FOLDER)compute_fight_ai.c \
		$(COMPUTE_FOLDER)compute_fight_ai_target.c \
		$(COMPUTE_FOLDER)compute_fight_ai_pos.c \
		$(COMPUTE_FOLDER)compute_fight_btn.c \
		$(COMPUTE_FOLDER)compute_fight_btn2.c \
		$(COMPUTE_FOLDER)compute_fight_gui.c \
		$(COMPUTE_FOLDER)actions.c \
		$(COMPUTE_FOLDER)compute_dead_npc.c \
		$(COMPUTE_FOLDER)compute_button_state.c \
		$(COMPUTE_FOLDER)compute_shoot.c \
		$(COMPUTE_FOLDER)compute_fight_fx.c \
		$(COMPUTE_FOLDER)compute_dice.c \
		$(COMPUTE_FOLDER)compute_view_pos.c \
		$(COMPUTE_FOLDER)compute_inventory.c \
		$(COMPUTE_FOLDER)compute_position_entity.c	\
		$(COMPUTE_FOLDER)compute_items_on_ground.c	\
		$(COMPUTE_FOLDER)compute_check_is_view.c	\
		$(COMPUTE_FOLDER)move_sprite_rectangles.c	\
		$(COMPUTE_FOLDER)compute_civilian.c	\
		$(COMPUTE_FOLDER)compute_bullets.c	\
		$(COMPUTE_FOLDER)compute_exp_player.c	\
		$(COMPUTE_FOLDER)compute_cyberware.c	\
		$(COMPUTE_FOLDER)compute_mana_bar.c	\
		$(COMPUTE_FOLDER)compute_fade.c	\
		$(COMPUTE_FOLDER)compute_shop_in_game.c	\
		$(COMPUTE_FOLDER)compute_quest_ui.c	\
		$(COMPUTE_FOLDER)compute_weather.c	\
		$(COMPUTE_FOLDER)use_drugs.c	\
		$(COMPUTE_FOLDER)character_death.c	\
		$(ANALYSE_FOLDER)analyze_drop_menu.c \
		$(ANALYSE_FOLDER)analyze_gui_obj.c \
		$(ANALYSE_FOLDER)analyze_final_page.c \
		$(ANALYSE_FOLDER)analyze_pages.c \
		$(ANALYSE_FOLDER)analyze_buttons_start_menu.c \
		$(ANALYSE_FOLDER)analyze_slider.c \
		$(ANALYSE_FOLDER)analyze_guis.c \
		$(ANALYSE_FOLDER)analyze_map.c \
		$(ANALYSE_FOLDER)analyze_game.c \
		$(ANALYSE_FOLDER)analyze_diag_pipe.c \
		$(ANALYSE_FOLDER)analyze_drag_drop.c \
		$(ANALYSE_FOLDER)analyze_swap_item.c \
		$(ANALYSE_FOLDER)analyze_reload_weapon.c \
		$(ANALYSE_FOLDER)analyze_use_gears.c \
		$(ANALYSE_FOLDER)change_window.c	\
		$(ANALYSE_FOLDER)analyze_fight.c	\
		$(ANALYSE_FOLDER)analyze_fight_gui.c	\
		$(ANALYSE_FOLDER)analyze_research_slots.c	\
		$(ANALYSE_FOLDER)analyze_shop_in_game.c	\
		$(THREE_FOLDER)get_state_options.c \
		$(THREE_FOLDER)create_grey_line.c \
		$(THREE_FOLDER)update_time.c \
		$(THREE_FOLDER)format_gui_obj.c \
		$(THREE_FOLDER)dup_image.c \
		$(THREE_FOLDER)get_entity.c \
		$(THREE_FOLDER)get_img.c \
		$(THREE_FOLDER)get_npc.c \
		$(THREE_FOLDER)basic_vector.c \
		$(THREE_FOLDER)npc_operation.c \
		$(THREE_FOLDER)chapter_transition.c \
		$(THREE_FOLDER)is_same_color.c \
		$(THREE_FOLDER)point_in_rectangle.c \
		$(MAKE_FOLDER)make_sound.c \
		$(MAKE_FOLDER)make_drop_menu.c \
		$(MAKE_FOLDER)make_menu_start.c \
		$(MAKE_FOLDER)make_gui_obj.c \
		$(MAKE_FOLDER)make_img.c \
		$(MAKE_FOLDER)make_choose_class.c \
		$(MAKE_FOLDER)make_choose_stats.c \
		$(MAKE_FOLDER)make_slider.c \
		$(MAKE_FOLDER)make_inventory.c	\
		$(MAKE_FOLDER)make_game.c	\
		$(MAKE_FOLDER)make_guis.c	\
		$(MAKE_FOLDER)make_map.c	\
		$(MAKE_FOLDER)make_info.c \
		$(MAKE_FOLDER)make_diag_pipe.c \
		$(MAKE_FOLDER)make_options.c \
		$(MAKE_FOLDER)make_entity.c \
		$(MAKE_FOLDER)make_player.c \
		$(MAKE_FOLDER)make_npc.c \
		$(MAKE_FOLDER)make_fight_gui.c \
		$(MAKE_FOLDER)make_shop.c \
		$(MAKE_FOLDER)make_final_page.c \
		$(MAKE_FOLDER)make_dropped_items.c \
		$(MAKE_FOLDER)make_shop_in_game.c	\
		$(INIT_FOLDER)init_inventory_set_slots.c	\
		$(INIT_FOLDER)add_option_drop_menu.c \
		$(INIT_FOLDER)draw_collision.c \
		$(INIT_FOLDER)check_all_houses.c \
		$(INIT_FOLDER)scatter/house.c \
		$(INIT_FOLDER)init_shop.c \
		$(INIT_FOLDER)init_drop_menu.c \
		$(INIT_FOLDER)init_stats.c \
		$(INIT_FOLDER)init_assets.c \
		$(INIT_FOLDER)init_level_menu.c \
		$(INIT_FOLDER)init_weapon_shop.c \
		$(INIT_FOLDER)init_scatters.c \
		$(INIT_FOLDER)init_choose_class.c \
		$(INIT_FOLDER)init_choose_stats.c \
		$(INIT_FOLDER)init_gui_obj.c \
		$(INIT_FOLDER)init_image.c \
		$(INIT_FOLDER)init_obj_outline.c \
		$(INIT_FOLDER)init_label.c \
		$(INIT_FOLDER)init_slider.c \
		$(INIT_FOLDER)init_player.c \
		$(INIT_FOLDER)init_player2.c \
		$(INIT_FOLDER)init_main_menu.c \
		$(INIT_FOLDER)init_start_menu.c \
		$(INIT_FOLDER)init_houses_entity.c \
		$(INIT_FOLDER)init_options.c \
		$(INIT_FOLDER)init_time.c	\
		$(INIT_FOLDER)init_inventory.c	\
		$(INIT_FOLDER)init_game.c	\
		$(INIT_FOLDER)init_keybind.c	\
		$(INIT_FOLDER)init_guis.c	\
		$(INIT_FOLDER)init_class.c \
		$(INIT_FOLDER)init_map.c	\
		$(INIT_FOLDER)init_game_map.c	\
		$(INIT_FOLDER)load_map.c	\
		$(INIT_FOLDER)init_final_page.c \
		$(INIT_FOLDER)init_item.c	\
		$(INIT_FOLDER)init_hp.c \
		$(INIT_FOLDER)init_dialogue.c	\
		$(INIT_FOLDER)init_queue_diag.c \
		$(INIT_FOLDER)init_portrait.c \
		$(INIT_FOLDER)init_txt_stats.c \
		$(INIT_FOLDER)init_quest.c \
		$(INIT_FOLDER)import_from_save.c \
		$(INIT_FOLDER)init_view.c \
		$(INIT_FOLDER)init_entity.c \
		$(INIT_FOLDER)init_npc.c \
		$(INIT_FOLDER)init_fight.c \
		$(INIT_FOLDER)init_fight_gui.c \
		$(INIT_FOLDER)import_inventory_items.c	\
		$(INIT_FOLDER)civilian.c \
		$(INIT_FOLDER)init_money.c \
		$(INIT_FOLDER)init_weather.c	\
		$(INIT_FOLDER)init_quest_ui.c \
		$(INIT_FOLDER)init_night.c \
		$(INIT_FOLDER)init_fade.c \
		$(INIT_FOLDER)init_escape_menu.c \
		$(INIT_FOLDER)init_diag_pipe.c \
		$(INIT_FOLDER)init_gui_obj_img.c \
		$(DESTROY_FOLDER)destroy_drop_menu.c	\
		$(DESTROY_FOLDER)destroy_gui_obj.c	\
		$(DESTROY_FOLDER)destroy_image.c	\
		$(DESTROY_FOLDER)destroy_label.c	\
		$(DESTROY_FOLDER)destroy_slider.c	\
		$(DESTROY_FOLDER)destroy_main_menu.c \
		$(DESTROY_FOLDER)destroy_options.c	\
		$(DESTROY_FOLDER)destroy_keybind.c	\
		$(DESTROY_FOLDER)destroy_game.c	\
		$(DESTROY_FOLDER)destroy_guis.c	\
		$(DESTROY_FOLDER)destroy_current_queued.c \
		$(DESTROY_FOLDER)destroy_map.c \
		$(DESTROY_FOLDER)destroy_player.c \
		$(DESTROY_FOLDER)destroy_time.c	\
		$(DESTROY_FOLDER)destroy_item.c	\
		$(DESTROY_FOLDER)destroy_start_menu.c \
		$(DESTROY_FOLDER)destroy_choose_class_menu.c \
		$(DESTROY_FOLDER)destroy_options_menu.c \
		$(DESTROY_FOLDER)destroy_civilian.c \
		$(DESTROY_FOLDER)destroy_npc.c \
		$(DESTROY_FOLDER)destroy_entity.c \
		$(DESTROY_FOLDER)destroy_fight.c \
		$(DESTROY_FOLDER)destroy_fight_gui.c \
		$(GAMEPLAY_FOLDER)simul_fight.c	\
		$(GAMEPLAY_FOLDER)simul_fight_aoe.c	\
		$(GAMEPLAY_FOLDER)simul_dice.c	\
		$(GAMEPLAY_FOLDER)simul_fight_npc.c	\
		$(GAMEPLAY_FOLDER)simulate_dv.c	\
		$(GAMEPLAY_FOLDER)compute_hit.c	\
		$(GAMEPLAY_FOLDER)compute_hit2.c	\
		$(GAMEPLAY_FOLDER)compute_aoe.c	\
		$(GAMEPLAY_FOLDER)empty_weapon.c	\
		$(STATS_INVENTORY)ammo.c	\
		$(STATS_INVENTORY)armor.c	\
		$(STATS_INVENTORY)weapon.c	\
		$(STATS_INVENTORY)drug.c	\
		$(STATS_INVENTORY)gear.c	\
		$(STATS_INVENTORY)cyberware.c	\
		$(QUEST_FOLDER)quest_function.c \
		$(QUEST_FOLDER)citizen_erazed.c \
		$(QUEST_FOLDER)citizen_erazed2.c \
		$(QUEST_FOLDER)thought_contagion.c \
		$(NPC_FOLDER)cryspi.c \
		$(NPC_FOLDER)dyn.c \
		$(NPC_FOLDER)mook.c \
		$(NPC_FOLDER)init_mook_area.c	\
		$(SCATTER_FOLDER)door.c \
		$(SCATTER_FOLDER)glock.c \
		$(SCATTER_FOLDER)coffin.c \
		$(SCATTER_FOLDER)candy.c \
		$(SCATTER_FOLDER)photo.c \
		$(SCATTER_FOLDER)sat_down.c \
		$(SCATTER_FOLDER)shop.c	\
		$(SCATTER_FOLDER)street_lamp.c	\
		$(SCATTER_FOLDER)street_trash.c	\
		$(SCATTER_FOLDER)init_props_str.c \

SRC_MAIN = $(SRC_FOLDER)main.c \

OBJ = $(SRC:.c=.o)

OBJ_MAIN = $(SRC_MAIN:.c=.o)

NAME	=	my_rpg

CFLAGS	=	-Wextra -Werror -Wall -I./include/	\
			-L./ -lmy -l csfml-graphics -l csfml-system -l csfml-window \
			-l csfml-audio -l m -g

CFLAGS_TEST	=	-Wall -Wextra -I./include/	\
	-L./lib/ -lmy -lcriterion --coverage

NAME_LIB	=	libmy.a

all: $(NAME_LIB) $(NAME)

$(NAME_LIB):
	@make -C lib
	@printf "$(BLUE)[🛼 ] $(NAME_LIB), $(GREEN)Library complete !$(NC)\n"

$(NAME): $(OBJ) $(OBJ_MAIN) $(NAME_LIB)
	@make -C lib
	@make -C lib
	@gcc -o $(NAME) $(OBJ) $(OBJ_MAIN) $(CFLAGS)
	@printf "$(BLUE)[🕹️ ] $(NAME), $(GREEN)Build complete ! $(NC)\n"

clean:
	@make clean -C lib
	@printf "$(RED)[🚫]$(BLUE)Clean$(NC)\n"
	@rm -f $(OBJ)
	@rm -f $(OBJ_MAIN)
	@rm -f $(LIBOBJ)
	@rm -f *.gcno
	@rm -f *.gcda

fclean: clean
	@make fclean -C lib
	@printf "$(RED)[🚫]$(BLUE)Fclean$(NC)\n"
	@rm -f $(NAME)
	@rm -f libmy.a
	@rm -f $(OBJ)
	@rm -f $(OBJ_MAIN)
	@rm -f unit_tests

re: fclean all unzip_assets

run : all clean
	./$(NAME)

unit_tests: re
	@gcc -o unit_tests $(SRC) $(SRC_TESTS) $(CFLAGS_TEST)

tests_run: unit_tests
	./unit_tests --exclude="./lib"

code_line :
	find . -name '*.c' | xargs wc -l

%.o: %.c
	@printf "$(RED)[⚒️ $(YELLOW)]$(BLUE) Compiling, $(GREEN)$@$(NC)\n"
	@gcc -c $(CFLAGS) $< -o $@

koding-style : fclean
	coding-style . .
	cat coding-style-reports.log
	rm -f coding-style-reports.log

zip_assets :
	@zip -r assets.zip assets
	@zip -r music.zip music
	@printf "$(BLUE)[📦] Zipping assets, $(GREEN)complete ! $(NC)\n"

unzip_assets:
	@unzip -o assets.zip -d .
	@unzip -o music.zip -d .
	@printf "$(BLUE)[📦] Unzipping assets, $(GREEN)complete ! $(NC)\n"
