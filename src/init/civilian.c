/*
** EPITECH PROJECT, 2024
** init civilian
** File description:
** civilian
*/
#include "my.h"


void add_clothe_civ(assets_t **assets, linked_list_t **lst,
    char *str, civ_t *npc)
{
    img_t *clothe;
    sfFloatRect rect;
    sfVector2f pos = sfSprite_getPosition(npc->civ->sprite);

    clothe = init_image(get_asset(str, assets),
        pos, 1);
    init_animated_img(clothe, 96, 96, pos);
    set_animate_image(clothe, 4, 1, 4);
    clothe->animate->animation_time = npc->civ->animate->animation_time;
    rect = sfSprite_getGlobalBounds(clothe->sprite);
    sfSprite_setOrigin(clothe->sprite,
        (sfVector2f){rect.width / 2, rect.height / 2});
    clothe->animate->rect.top = clothe->animate->rect.height * 4;
    my_insert_back_list(lst, clothe);
}

static void random_hair_civ(assets_t **assets, civ_t *npc)
{
    int hair = rand() % (19 + 1) + 1;
    int cap = rand() % 10;
    char str[20];

    if (hair <= 19) {
        sprintf(str, "Hair_%d", hair);
        add_clothe_civ(assets, &npc->clothes, str, npc);
    }
    if (cap == 1) {
        cap = rand() % 5 + 1;
        sprintf(str, "Cap_%d", cap);
        add_clothe_civ(assets, &npc->clothes, str, npc);
    }
}

static void set_random_clothes_npc(assets_t **assets, civ_t *npc)
{
    sfVector2f pant_shirt = {rand() % 2, rand() % 6};

    add_clothe_civ(assets, &npc->clothes, "Shoes", npc);
    if (pant_shirt.x == 0)
        add_clothe_civ(assets, &npc->clothes, "Pant_1", npc);
    if (pant_shirt.x == 1)
        add_clothe_civ(assets, &npc->clothes, "Pant_1_w", npc);
    if (pant_shirt.y == 0)
        add_clothe_civ(assets, &npc->clothes, "Shirt_1", npc);
    if (pant_shirt.y == 1)
        add_clothe_civ(assets, &npc->clothes, "Shirt_1_w", npc);
    if (pant_shirt.y == 2)
        add_clothe_civ(assets, &npc->clothes, "Shirt_2", npc);
    if (pant_shirt.y == 3)
        add_clothe_civ(assets, &npc->clothes, "Shirt_2_w", npc);
    if (pant_shirt.y == 4)
        add_clothe_civ(assets, &npc->clothes, "Shirt_3", npc);
    if (pant_shirt.y == 5)
        add_clothe_civ(assets, &npc->clothes, "Shirt_3_w", npc);
    random_hair_civ(assets, npc);
}

static void init_img_npc(civ_t *data, game_t *game, sfVector2f position)
{
    data->civ = init_image(get_asset("Hero_Green", game->assets), position, 1);
    init_animated_img(data->civ, 96, 96, position);
    set_animate_image(data->civ, 4, 1, 4);
    data->civ->animate->animation_time = 0.2;
    sfSprite_setOrigin(data->civ->sprite, (sfVector2f){
        data->civ->animate->rect.width / 2, data->civ->
        animate->rect.height / 2});
    set_random_clothes_npc(game->assets, data);
}

entity_t *init_civilian(game_t *game, sfVector2f position)
{
    entity_t *entity = malloc(sizeof(entity_t));
    civ_t *data = malloc(sizeof(civ_t));
    sfVector2f target = position;

    entity->type = CIVILIAN;
    entity->civ = data;
    entity->position = position;
    data->clothes = NULL;
    init_img_npc(data, game, position);
    data->in_combat = false;
    data->time_move_dir = 1;
    data->own_clock = init_time();
    data->vector = (sfVector2f){cos(get_angle(target, position)),
        sin(get_angle(target, position))};
    data->civ->animate->rect.top = 4 * data->civ->animate->rect.height;
    return entity;
}
