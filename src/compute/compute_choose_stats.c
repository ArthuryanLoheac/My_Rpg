/*
** EPITECH PROJECT, 2024
** analyze_options
** File description:
** analyze_options
*/

#include "my.h"
#include "gui_struct.h"


void update_number(sfText *txt, int nb)
{
    char *str = malloc(sizeof(char) *
        my_strlen("Remaining points : ") + 3);

    sprintf(str, "Remaining points : %d", nb);
    sfText_setString(txt, str);
}

static void assign_data(page_choose_stats_t *page, player_character_t *player)
{
    int moyenne = 0;

    player->stats->DEX = page->DEX->texte[0] - '0';
    player->stats->MOVE = page->MOVE->texte[0] - '0';
    player->stats->TECH = page->TECH->texte[0] - '0';
    player->stats->BODY = page->BODY->texte[0] - '0';
    player->stats->WILL = page->WILL->texte[0] - '0';
    player->stats->REF = page->REF->texte[0] - '0';
    player->stats->LUCK = page->LUCK->texte[0] - '0';
    player->stats->EMP = page->EMP->texte[0] - '0';
    moyenne = (int)floor((player->stats->WILL + player->stats->BODY) / 2.0);
    player->hp->x = 10 + (5 * moyenne);
    player->hp->y = player->hp->x;
    player->stats->HUM = 10 * player->stats->EMP;
}

static void update_state_button_validerr(guis_t *guis,
    page_choose_stats_t *page, player_character_t *player, game_t *game)
{
    sfSprite_setColor(page->Valider->img->sprite, sfWhite);
    if (page->Valider->state == RELEASED) {
        game->guis->shop->ui_content = init_shop(game->assets,
            game->player->class);
        game->guis->shop_in_game->ui_content = init_shop(game->assets,
            game->player->class);
        assign_data(page, player);
        guis->active = PAGE_SHOP;
    }
    if (page->Valider->state == PRESSED)
        page->Valider->img->animate->rect.left =
            page->Valider->img->animate->rect.width;
    else if (page->Valider->state == HOVER)
        page->Valider->img->animate->rect.left =
            page->Valider->img->animate->rect.width * 2;
    else
        page->Valider->img->animate->rect.left = 0;
}

static void update_state_button_plus(gui_obj_t *button, line_stats_t *line,
    int *rest_int, sfText *rest_txt)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        (*rest_int)--;
        line->texte[0] += 1;
        sfText_setString(line->value->txt, line->texte);
        update_number(rest_txt, *rest_int);
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_state_button_moins(gui_obj_t *button, line_stats_t *line,
    int *rest_int, sfText *rest_txt)
{
    sfSprite_setColor(button->img->sprite, sfWhite);
    if (button->state == RELEASED) {
        (*rest_int)++;
        line->texte[0] -= 1;
        sfText_setString(line->value->txt, line->texte);
        update_number(rest_txt, *rest_int);
        button->state = NO_STATE;
    }
    if (button->state == PRESSED)
        button->img->animate->rect.left = button->img->animate->rect.width;
    else if (button->state == HOVER)
        button->img->animate->rect.left = button->img->animate->rect.width * 2;
    else
        button->img->animate->rect.left = 0;
}

static void update_line(line_stats_t *line, int *restants, sfText *rest_txt)
{
    if (line->texte[0] < '8' && *restants > 0)
        update_state_button_plus(line->Plus, line, restants, rest_txt);
    else
        sfSprite_setColor(line->Plus->img->sprite,
            sfColor_fromRGBA(255, 255, 255, 128));
    if (line->texte[0] > '2')
        update_state_button_moins(line->Moins, line, restants, rest_txt);
    else
        sfSprite_setColor(line->Moins->img->sprite,
            sfColor_fromRGBA(255, 255, 255, 128));
}

static void update_recap(recap_t *recap, player_character_t *player)
{
    if (player->class == SOLO)
        sfText_setString(recap->Class->txt, "-- SOLO --\n\n");
    if (player->class == MED)
        sfText_setString(recap->Class->txt, "-- MEDTECH --\n\n");
    if (player->class == TECH)
        sfText_setString(recap->Class->txt, "-- TECH --\n\n");
}

void compute_choose_stats(ui_obj_t *obj, game_t *game)
{
    page_choose_stats_t *options = (page_choose_stats_t *)obj->ui_content;
    int *pts_rest = &options->points_restant;

    if (options->points_restant == 0)
        update_state_button_validerr(game->guis, options, game->player, game);
    else
        sfSprite_setColor(options->Valider->img->sprite,
        sfColor_fromRGBA(255, 255, 255, 128));
    update_line(options->DEX, pts_rest, options->Pts_restant->txt);
    update_line(options->MOVE, pts_rest, options->Pts_restant->txt);
    update_line(options->TECH, pts_rest, options->Pts_restant->txt);
    update_line(options->BODY, pts_rest, options->Pts_restant->txt);
    update_line(options->WILL, pts_rest, options->Pts_restant->txt);
    update_line(options->REF, pts_rest, options->Pts_restant->txt);
    update_line(options->LUCK, pts_rest, options->Pts_restant->txt);
    update_line(options->EMP, pts_rest, options->Pts_restant->txt);
    update_recap(options->recap, game->player);
}
