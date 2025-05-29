/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to destroy the guis struct
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../../include/my.h"
#include "../../include/lib.h"
#include <time.h>
#include <string.h>

static void destroy_main_menu_ui(ui_obj_t *main_menu_ui)
{
    destroy_main_menu(main_menu_ui->ui_content);
}

static void destroy_start_menu_ui(ui_obj_t *start_menu_ui)
{
    destroy_start_menu(start_menu_ui->ui_content);
}

static void destroy_options_menu_ui(ui_obj_t *options_menu_ui)
{
    destroy_options_menu(options_menu_ui->ui_content);
}

static void destroy_choose_class_menu_ui(ui_obj_t *choose_class_menu_ui)
{
    destroy_choose_class_menu(choose_class_menu_ui->ui_content);
}

static void destroy_map_ui(ui_obj_t *map_ui)
{
    destroy_map(map_ui->ui_content);
}

void destroy_guis(struct s_guis *guis)
{
    destroy_main_menu_ui(guis->main_menu);
    destroy_start_menu_ui(guis->start_menu);
    destroy_choose_class_menu_ui(guis->choose_class);
    destroy_options_menu_ui(guis->options_page);
    destroy_map_ui(guis->map);
    free(guis);
}
