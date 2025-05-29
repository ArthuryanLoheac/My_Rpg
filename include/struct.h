/*
** EPITECH PROJECT, 2023
** my
** File description:
** our own version of printf
*/

#pragma once
#include <stdarg.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>
#include "lib.h"

enum gui_state_e {
    NO_STATE,
    HOVER,
    PRESSED,
    RELEASED
};

typedef struct s_time {
    sfClock *clock;
    sfTime time;
    float seconds;
    float offset;
} time2_t;

typedef struct s_animated_img {
    sfIntRect rect;
    time2_t *clock_animation;
    time2_t *clock_intern;
    float animation_time;
    int nb_images_width;
    int nb_images_height;
    int nb_images;
    int status_image;
    int state;
} animated_img_t;

typedef struct s_img {
    sfSprite *sprite;
    sfTexture *texture;
    animated_img_t *animate;
    char *name;
} img_t;

typedef struct s_label {
    sfFont *font;
    sfText *txt;
} label_t;

typedef struct s_gui_object {
    sfRectangleShape *rect;
    label_t *label;
    img_t *img;
    sfBool (*is_clicked) (struct s_gui_object *, sfRenderWindow *);
    sfBool (*is_hover) (struct s_gui_object *, sfRenderWindow *);
    enum gui_state_e state;
    sfBool outline;
} gui_obj_t;

typedef struct s_button {
    gui_obj_t *gui_obj;
    label_t *text;
} button_t;

typedef struct s_gui_slider {
    sfRectangleShape *background;
    gui_obj_t *cursor;
    float value_per_pixel;
    sfVector2f mouse_pos;
    sfBool vertical;
} gui_slider_t;

typedef struct s_gui_options {
    gui_obj_t *option;
    void *tab_content;
    struct s_gui_options *next;
} gui_opt_t;

typedef struct s_gui_drop_menu {
    struct s_gui_object *button;
    struct s_gui_options *options;
} gui_drp_t;

typedef struct s_gui_tab_menu {
    img_t *content_bg;
    struct s_gui_options *options;
    int active;
} gui_tab_t;
