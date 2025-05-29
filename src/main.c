/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** the main file
*/

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../include/my.h"
#include "../include/lib.h"
#include <time.h>
#include <string.h>

static int help(void)
{
    printf("HELP\n");
    return 0;
}

int main(int ac, char **argv)
{
    sfEvent event;

    if (ac == 2 && !strcmp(argv[1], "-h"))
        return help();
    if (ac != 1)
        return 84;
    srand(time(NULL));
    return my_rpg(&event);
}
