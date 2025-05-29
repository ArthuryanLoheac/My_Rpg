/*
** EPITECH PROJECT, 2024
** init_player
** File description:
** init_player
*/

#include "my.h"

int init_money(game_t *game, bool new_game)
{
    char *data = NULL;
    char *data_save = NULL;

    if (new_game == true)
        return 650;
    data_save = import_from_save("Money", game->savefilepath);
    if (my_strlen(data_save) == 0)
        wrong_savefile(game->savefilepath, "###Money");
    data = import_from_save("Money", game->savefilepath);
    if (data == NULL)
        return 650;
    data = my_str_to_word_array(data, "\n", 63)[0];
    return atoi(data);
}

info_t *init_info(assets_t **assets)
{
    info_t *info = malloc(sizeof(info_t));

    info->clock = NULL;
    info->label = NULL;
    info->target = 0;
    info->background = init_image(get_asset("info_box", assets),
        vect0(), 1);
    info->text = NULL;
    return info;
}

static sfVideoMode init_video_mode_change(char **args)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    int x = 0;
    int y = 0;
    int bits = 0;

    x = atoi(args[2]);
    y = atoi(args[3]);
    bits = atoi(args[4]);
    if ((x == 1280 || x == 1366 || x == 1920) && (y == 1080 || y == 720
        || y == 768) && bits == 32) {
        video_mode.width = atoi(args[2]);
        video_mode.height = atoi(args[3]);
        video_mode.bitsPerPixel = atoi(args[4]);
    }
    return (video_mode);
}

sfVideoMode init_video_mode(game_t *game)
{
    sfVideoMode video_mode = {1920, 1080, 32};
    char **args = NULL;
    char *data = NULL;

    if (game->saveoptions == -1) {
        return (video_mode);
    }
    data = import_from_save("OPTIONS", game->saveoptionsfilepath);
    if (data)
        args = my_str_to_word_array(data, "\n\0", 0);
    if (args && args[2] && args[3] && args[4]) {
        return init_video_mode_change(args);
    } else {
        return video_mode;
    }
}
