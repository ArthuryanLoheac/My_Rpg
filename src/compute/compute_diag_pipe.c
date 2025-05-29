/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to compute a message
*/

#include "my.h"

static void get_text_after_time(sfText *txt, char *str, float time)
{
    char *result = my_strndup(str, MAX((int)(time * 25), 0));

    sfText_setString(txt, result);
    free(result);
}

static void init_1_answer(diag_pipe_t *diag_pipe, int i, assets_t **assets)
{
    sfFloatRect rect;
    sfFloatRect rect2;

    diag_pipe->answer_btn[i] = init_gui_obj((sfVector2f){1330, 830 -
        (180 * i)}, (sfVector2f){480, 135});
    diag_pipe->answer_btn[i]->img = dup_image(diag_pipe->answer_bg);
    sfSprite_setPosition(diag_pipe->answer_btn[i]->img->sprite,
        (sfVector2f){1330, 830 - (180 * i)});
    diag_pipe->answer_btn[i]->label = init_label(diag_pipe->answer[i],
        (sfVector2f){1365, 870 - (180 * i)}, 20,
        get_asset("Font_pixel", assets));
    rect = sfSprite_getGlobalBounds(diag_pipe->answer_btn[i]->img->sprite);
    rect2 = sfText_getLocalBounds(diag_pipe->answer_btn[i]->label->txt);
    sfText_setCharacterSize(diag_pipe->answer_btn[i]->label->txt, MIN(20 *
    ((rect.height - 75) / rect2.height), 30));
}

static void init_answer(diag_pipe_t *diag_pipe, assets_t **assets)
{
    int i = 0;

    diag_pipe->answer_btn = malloc(sizeof(gui_obj_t *) *
        (my_pointlen(diag_pipe->answer) + 1));
    for (; diag_pipe->answer[i] != NULL; i++) {
        init_1_answer(diag_pipe, i, assets);
    }
    diag_pipe->answer_btn[i] = NULL;
}

void free_answer(char **array)
{
    int len = my_pointlen(array);

    for (int i = 0; i < len; i++) {
        free(array[i]);
    }
    free(&array[-1]);
}

static void clean_diag_pipe(diag_pipe_t *diag_pipe)
{
    destroy_time(diag_pipe->clock);
    destroy_label(diag_pipe->label);
    destroy_label(diag_pipe->label_n);
    diag_pipe->clock = NULL;
    diag_pipe->text = NULL;
    diag_pipe->label = NULL;
    diag_pipe->label_n = NULL;
    diag_pipe->close = sfFalse;
    if (diag_pipe->answer != NULL) {
        free_answer(diag_pipe->answer);
        for (int i = 0; diag_pipe->answer_btn[i] != NULL; i++) {
            destroy_gui_obj(diag_pipe->answer_btn[i]);
        }
        free(diag_pipe->answer_btn);
        diag_pipe->answer_btn = NULL;
        diag_pipe->answer = NULL;
    }
}

static void do_compute_diag_pipe(diag_pipe_t *diag_pipe, assets_t **assets)
{
    update_time(diag_pipe->clock);
    if (diag_pipe->label == NULL) {
        diag_pipe->label = init_label("", (sfVector2f){230, 790}, 30,
            get_asset("Font_pixel", assets));
        diag_pipe->label_n = init_label(diag_pipe->name, (sfVector2f){70, 980},
            15, get_asset("Font_pixel", assets));
    }
    if (diag_pipe->answer_btn == NULL)
        init_answer(diag_pipe, assets);
    else
        compute_answer(diag_pipe);
    get_text_after_time(diag_pipe->label->txt, diag_pipe->text,
        diag_pipe->clock->seconds);
    if (diag_pipe->close == sfTrue)
        clean_diag_pipe(diag_pipe);
}

static void compute_diag_pipe_answer_pos(diag_pipe_t *diag_pipe,
    sfVector2f pos, int i)
{
    sfSprite_setPosition(diag_pipe->answer_btn[i]->img->sprite,
        (sfVector2f){pos.x + 1330, pos.y + 830 - (180 * i)});
    sfText_setPosition(diag_pipe->answer_btn[i]->label->txt,
        (sfVector2f){pos.x + 1365, pos.y + 870 - (180 * i)});
    sfRectangleShape_setPosition(diag_pipe->answer_btn[i]->rect,
        (sfVector2f){pos.x + 1330, pos.y + 830 - (180 * i)});
}

static void compute_diag_pipe_pos(sfRenderWindow *window,
    diag_pipe_t *diag_pipe)
{
    sfVector2f pos = sfView_getCenter(sfRenderWindow_getView(window));

    pos = add(pos, -960, -480);
    sfSprite_setPosition(diag_pipe->background->sprite, (sfVector2f){pos.x +
        20, pos.y + 730});
    sfSprite_setPosition(diag_pipe->portrait->sprite, (sfVector2f){pos.x + 65,
        pos.y + 770});
    if (diag_pipe->label != NULL) {
        sfText_setPosition(diag_pipe->label->txt, (sfVector2f){pos.x + 230,
            pos.y + 790});
        sfText_setPosition(diag_pipe->label_n->txt, (sfVector2f){pos.x + 70,
            pos.y + 915});
    }
    if (diag_pipe->answer_btn != NULL) {
        for (int i = 0; diag_pipe->answer_btn[i] != NULL; i++) {
            compute_diag_pipe_answer_pos(diag_pipe, pos, i);
        }
    }
}

void compute_diag_pipe(sfRenderWindow *window, diag_pipe_t *diag_pipe,
    assets_t **assets, player_character_t *player)
{
    (void) window;
    if (diag_pipe->clock != NULL) {
        do_compute_diag_pipe(diag_pipe, assets);
        compute_diag_pipe_pos(window, diag_pipe);
    } else if (diag_pipe->ll != NULL) {
        init_dialogue(((diag_queue_t *)(diag_pipe->ll->data)), diag_pipe,
            player->name, player->gender);
        destroy_current_queued(diag_pipe);
        do_compute_diag_pipe(diag_pipe, assets);
    }
}
