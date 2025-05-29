/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to compute a message
*/

#include "my.h"

static void compute_info_pos(sfRenderWindow *window, info_t *info)
{
    sfVector2f pos = add(sfView_getCenter(sfRenderWindow_getView(window)),
        -960, -490);

    if (!info || !(info->label) || !(info->label->txt) ||
        !(info->background) || !(info->background->sprite))
        return;
    sfSprite_move(info->background->sprite, pos);
    sfText_move(info->label->txt, pos);
}

static void get_text_after_time(sfText *txt, char *str, float time)
{
    char *result = my_strndup(str, MAX((int)(time * 25), 0));

    sfText_setString(txt, result);
    free(result);
}

static void compute_info_size(info_t *info, sfFloatRect rect,
    sfFloatRect rect2)
{
    rect2 = sfText_getLocalBounds(info->label_end->txt);
    sfSprite_setPosition(info->background->sprite, (sfVector2f){(1920 -
        rect.width) / 2, 10});
    sfText_setPosition(info->label->txt, (sfVector2f){(1920 -
        rect.width) / 2 + 30, 40});
    sfText_setScale(info->label->txt, (sfVector2f){(rect.height - 95) /
        rect2.height, (rect.height - 95) / rect2.height});
}

static void do_compute_info(info_t *info, sfFloatRect rect, assets_t **assets)
{
    sfFloatRect rect2;

    update_time(info->clock);
    if (info->label == NULL) {
        info->label = init_label("", (sfVector2f){100, 100}, 90,
            get_asset("Font_pixel", assets));
        info->label_end = init_label(my_strdup(info->text), (sfVector2f){100,
            100}, 90, get_asset("Font_pixel", assets));
    }
    get_text_after_time(info->label->txt, info->text, info->clock->seconds);
    if (info->clock->seconds < info->target) {
        compute_info_size(info, rect, rect2);
    } else {
        destroy_time(info->clock);
        destroy_label(info->label);
        info->clock = NULL;
    }
}

void compute_info(sfRenderWindow *window, info_t *info, assets_t **assets)
{
    sfFloatRect rect = sfSprite_getGlobalBounds(info->background->sprite);

    (void) window;
    if (info->clock != NULL) {
        do_compute_info(info, rect, assets);
        compute_info_pos(window, info);
    }
}

void send_info(game_t *game, float time, char *str)
{
    game->info->clock = NULL;
    game->info->label = NULL;
    game->info->label_end = NULL;
    game->info->target = time;
    game->info->text = my_strdup(str);
    game->info->clock = init_time();
}
