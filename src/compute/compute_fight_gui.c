/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to compute a message
*/

#include "my.h"

static void default_mode(fight_gui_t *gui, sfVector2f pos, sfVector2f size,
    sfVector2f size2)
{
    sfSprite_setPosition(gui->autofire->img->sprite, add(pos, 935, 905));
    sfSprite_setPosition(gui->fire->img->sprite, add(pos, 805, 900));
    sfRectangleShape_setPosition(gui->autofire->rect, add(pos, 935, 905));
    sfRectangleShape_setPosition(gui->fire->rect, add(pos, 805, 900));
    sfRectangleShape_setSize(gui->fire->rect, size);
    sfRectangleShape_setSize(gui->autofire->rect, size2);
    format_gui_obj(gui->autofire, sfTrue, sfFalse);
    format_gui_obj(gui->fire, sfTrue, sfFalse);
}

static void compute_autofire(fight_gui_t *gui, sfVector2f pos)
{
    sfVector2f size = {120, 120};
    sfVector2f size2 = {50, 50};

    if (gui->mode == true) {
        sfSprite_setPosition(gui->fire->img->sprite, add(pos, 935, 905));
        sfSprite_setPosition(gui->autofire->img->sprite, add(pos, 805, 900));
        sfRectangleShape_setPosition(gui->fire->rect, add(pos, 935, 905));
        sfRectangleShape_setPosition(gui->autofire->rect, add(pos, 805, 900));
        sfRectangleShape_setSize(gui->fire->rect, size2);
        sfRectangleShape_setSize(gui->autofire->rect, size);
        format_gui_obj(gui->autofire, sfTrue, sfFalse);
        format_gui_obj(gui->fire, sfTrue, sfFalse);
    } else {
        default_mode(gui, pos, size, size2);
    }
}

void compute_fight_gui_icon_pos(sfRenderWindow *window, fight_gui_t *gui)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(window));

    pos = add(pos, -960, -490);
    sfSprite_setPosition(gui->mana_img->sprite, add(pos, 0, 30));
    sfSprite_setPosition(gui->bg->sprite, add(pos, 655, 880));
    sfSprite_setPosition(gui->dodge->img->sprite, add(pos, 675, 900));
    sfSprite_setPosition(gui->shell->img->sprite, add(pos, 805, 900));
    sfSprite_setPosition(gui->expl->img->sprite, add(pos, 805, 900));
    sfSprite_setPosition(gui->unarmd->img->sprite, add(pos, 805, 900));
    sfSprite_setPosition(gui->melee->img->sprite, add(pos, 805, 900));
    sfSprite_setPosition(gui->bow->img->sprite, add(pos, 805, 900));
    sfSprite_setPosition(gui->dash->img->sprite, add(pos, 995, 900));
    sfSprite_setPosition(gui->done->img->sprite, add(pos, 1125, 900));
}

void compute_fight_gui_pos(sfRenderWindow *window, fight_gui_t *gui)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(window));

    pos = add(pos, -960, -490);
    compute_fight_gui_icon_pos(window, gui);
    sfRectangleShape_setPosition(gui->dodge->rect, add(pos, 675, 900));
    sfRectangleShape_setPosition(gui->shell->rect, add(pos, 805, 900));
    sfRectangleShape_setPosition(gui->expl->rect, add(pos, 805, 900));
    sfRectangleShape_setPosition(gui->unarmd->rect, add(pos, 805, 900));
    sfRectangleShape_setPosition(gui->melee->rect, add(pos, 805, 900));
    sfRectangleShape_setPosition(gui->bow->rect, add(pos, 805, 900));
    sfRectangleShape_setPosition(gui->dash->rect, add(pos, 995, 900));
    sfRectangleShape_setPosition(gui->done->rect, add(pos, 1125, 900));
    compute_autofire(gui, pos);
}
