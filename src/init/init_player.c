/*
** EPITECH PROJECT, 2024
** init_player
** File description:
** init_player
*/

#include "my.h"

static int init_gender(game_t *game, bool new_game, player_character_t *player)
{
    char *data = NULL;
    int gender = 0;

    if (new_game == true)
        return 0;
    data = import_from_save("Gender", game->savefilepath);
    if (data == NULL)
        return 0;
    data = my_str_to_word_array(data, "\n", 63)[0];
    gender = atoi(data);
    compute_add_hair_from_gender(gender, game, player);
    return gender;
}

static char *init_name(game_t *game, bool new_game)
{
    char *data = NULL;

    if (new_game == true)
        return NULL;
    data = import_from_save("Name", game->savefilepath);
    if (data == NULL) {
        return NULL;
    }
    data = my_str_to_word_array(data, "\n", 63)[0];
    return strdup(data);
}

void add_clothe(assets_t **assets, linked_list_t **lst,
    char *str, sfVector2f pos)
{
    img_t *clothe;
    sfFloatRect rect;

    clothe = init_image(get_asset(str, assets),
        pos, 1);
    init_animated_img(clothe, 96, 96, pos);
    set_animate_image(clothe, 4, 1, 4);
    clothe->animate->animation_time = 0.2;
    rect = sfSprite_getGlobalBounds(clothe->sprite);
    sfSprite_setOrigin(clothe->sprite,
        (sfVector2f){rect.width / 2, rect.height / 2});
    clothe->animate->rect.top = clothe->animate->rect.height * 4;
    my_insert_back_list(lst, clothe);
    clothe->name = my_strdup(str);
}

void add_clothe_npc(assets_t **assets, linked_list_t **lst,
    char *str, npc_t *npc)
{
    img_t *clothe;
    sfFloatRect rect;
    sfVector2f pos = sfSprite_getPosition(npc->npc->sprite);

    clothe = init_image(get_asset(str, assets),
        pos, 1);
    init_animated_img(clothe, 96, 96, pos);
    set_animate_image(clothe, 4, 1, 4);
    clothe->animate->animation_time = npc->npc->animate->animation_time;
    rect = sfSprite_getGlobalBounds(clothe->sprite);
    sfSprite_setOrigin(clothe->sprite,
        (sfVector2f){rect.width / 2, rect.height / 2});
    clothe->animate->rect.top = clothe->animate->rect.height * 4;
    my_insert_back_list(lst, clothe);
}

static void init_clothes(player_character_t *player, game_t *game,
    sfVector2f start_pos)
{
    add_clothe(game->assets, &player->sprite->clothes,
        "Shoes", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Pant_1", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Shirt_Player", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Leather_Armor", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Kevlar_Armor", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Light_Armorjack", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Medium_Armorjack", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Heavy_Armorjack", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Flak_Armor", start_pos);
    add_clothe(game->assets, &player->sprite->clothes,
        "Metalgear_Armor", start_pos);
}

static void get_data_save_xp(game_t *game,
    int *actual_level, int *actual_xp)
{
    char *data_save = import_from_save("PLAYER", game->savefilepath);
    char **data = str_to_word_array(data_save, " \n");
    int nbr_len = my_pointlen(data);
    char **data_level;

    if (nbr_len == 2) {
        data_level = str_to_word_array(data[1], ",");
        if (my_pointlen(data_level) == 2){
            *actual_level = atoi(data_level[0]);
            *actual_xp = atoi(data_level[1]);
        } else {
            fprintf(stderr, "Error in save file\n");
            exit(84);
        }
    } else {
        fprintf(stderr, "Error in save file\n");
        exit(84);
    }
}

static xp_data_t *init_xp(game_t *game, bool newgame)
{
    xp_data_t *data = malloc(sizeof(xp_data_t));
    int actual_level = 0;
    int actual_xp = 0;

    if (!newgame)
        get_data_save_xp(game, &actual_level, &actual_xp);
    data->level = actual_level;
    data->background = sfRectangleShape_create();
    sfRectangleShape_setFillColor(data->background, GREY);
    sfRectangleShape_setSize(data->background, (sfVector2f){260, 20});
    data->xp_player = (sfVector2i){actual_xp, 100};
    data->xp_bg = sfRectangleShape_create();
    sfRectangleShape_setFillColor(data->xp_bg, LIGHT_BLUE);
    sfRectangleShape_setSize(data->xp_bg, (sfVector2f){(260 *
        (data->xp_player.x / data->xp_player.y)), 20});
    data->niv_label = init_text("0", get_asset("Font_pixel", game->assets),
        (sfVector2f){60, 750}, 0.4);
    return data;
}

static void get_data_pos_save(sfVector2f *start_pos, bool newgame,
    game_t *game)
{
    char *data_save = NULL;
    char **data = NULL;
    char **data_pos;

    if (!newgame) {
        data_save = import_from_save("PLAYER", game->savefilepath);
        if (my_strlen(data_save) == 0)
            wrong_savefile(game->savefilepath, "###PLAYER");
        data = str_to_word_array(data_save, " \n");
        if (my_pointlen(data) != 2)
            wrong_savefile(game->savefilepath, "###PLAYER");
        data_pos = str_to_word_array(data[0], ",");
        if (my_pointlen(data_pos) != 2)
            wrong_savefile(game->savefilepath, "###PLAYER");
        start_pos->x = atof(data_pos[0]);
        start_pos->y = atof(data_pos[1]);
    }
}

static void init_player2(player_character_t *player)
{
    player->invincible = false;
    player->movmult = 1;
    player->mov = init_time();
    player->range_trigger = sfRectangleShape_create();
    sfRectangleShape_setSize(player->range_trigger, (sfVector2f){500, 500});
    sfRectangleShape_setFillColor(player->range_trigger, sfTransparent);
}

player_character_t *init_player(game_t *game, bool new_game)
{
    player_character_t *player = malloc(sizeof(player_character_t));
    sfVector2f start_pos = (sfVector2f){13400, 9400};

    init_player2(player);
    get_data_pos_save(&start_pos, new_game, game);
    player->hp = init_hp(game);
    player->class = init_class(game);
    player->name = init_name(game, new_game);
    player->stats = init_stats(game, new_game);
    player->bonus_stats = NULL;
    player->sprite = init_player_sprite(game->assets, start_pos);
    player->sprite->clothes = NULL;
    player->xp_data = init_xp(game, new_game);
    player->euro_dollars = init_money(game, new_game);
    player->id_active_armor = -1;
    init_clothes(player, game, start_pos);
    player->gender = init_gender(game, new_game, player);
    return player;
}
