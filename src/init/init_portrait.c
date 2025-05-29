/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a button
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

portrait_t *init_portrait(assets_t **assets)
{
    portrait_t *portrait = malloc(sizeof(portrait_t));

    portrait->protagonist =
        init_image(get_asset("Portraits_test1", assets),
        vect0(), 1);
    portrait->alter =
        init_image(get_asset("Portraits_test2", assets),
        vect0(), 1);
    portrait->cryspi =
        init_image(get_asset("Portraits_cryspi", assets),
        vect0(), 1);
    portrait->dyn =
        init_image(get_asset("Portraits_dyn", assets),
        vect0(), 1);
    portrait->puddle = NULL;
    portrait->queen = NULL;
    portrait->man =
        init_image(get_asset("Portraits_man", assets),
        vect0(), 1);
    return portrait;
}
