/*
** EPITECH PROJECT, 2024
** my_rpg
** File description:
** a function to make the label and or image of a gui object in its center
*/

#include "my.h"

void fit_img(gui_obj_t *obj, sfFloatRect *rec)
{
    sfFloatRect rec2 = sfSprite_getLocalBounds(obj->img->sprite);

    sfSprite_setPosition(obj->img->sprite, (sfVector2f){rec->left, rec->top});
    sfSprite_setScale(obj->img->sprite, (sfVector2f){rec->width / rec2.width,
        rec->height / rec2.height});
}

void fit_txt(gui_obj_t *obj, sfFloatRect *rec)
{
    sfText_setPosition(obj->label->txt, (sfVector2f){rec->left, rec->top});
}

void format_gui_obj(struct s_gui_object *obj, sfBool fitimg, sfBool fittxt)
{
    sfFloatRect rect = sfRectangleShape_getGlobalBounds(obj->rect);

    if (fitimg == sfTrue && obj->img != NULL)
        fit_img(obj, &rect);
    if (fittxt == sfTrue && obj->label != NULL)
        fit_txt(obj, &rect);
}
