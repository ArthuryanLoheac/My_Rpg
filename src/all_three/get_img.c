/*
** EPITECH PROJECT, 2023
** my
** File description:
** our own version of printf
*/

#include "my.h"

img_t *get_img(char *name, linked_list_t *img)
{
    while (img != NULL) {
        if (my_strcmpstart(((img_t *)(img->data))->name, name) == 0) {
            return ((img_t *)(img->data));
        }
        img = img->next;
    }
    return NULL;
}
