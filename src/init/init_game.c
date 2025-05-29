/*
** EPITECH PROJECT, 2024
** my_paint
** File description:
** a function to create a button
*/

#include "my.h"
#include "gui_struct.h"
#include <stdlib.h>

static void load_sound_and_mutefrom_save(game_t *game,
    music_t *music, char **args)
{
    if (args && args[1]) {
        music->mute_volume = atoi(args[1]);
        if (music->mute_volume == 1) {
            music->mute_volume = sfTrue;
            set_volume_for_musics(music, 0);
        } else
            music->mute_volume = sfFalse;
    }
    if (args && args[5]) {
        game->sounds->sound_volume = atoi(args[5]);
        if (game->sounds->sound_volume == -1) {
            game->sounds->sound_volume = 100;
            set_volume_for_sounds(game->sounds, 100);
        }
    }
}

static void load_musics(game_t *game, music_t *music)
{
    char *data = import_from_save("OPTIONS", game->saveoptionsfilepath);
    char **args = NULL;

    if (data)
        args = my_str_to_word_array(data, "\n\0", 0);
    if (args && args[0]) {
        music->music_volume = atoi(args[0]);
        if (music->music_volume == -1) {
            music->music_volume = 100;
            set_volume_for_musics(music, 100);
        }
    }
    load_sound_and_mutefrom_save(game, music, args);
}

static under_sound_t *init_under_sound(assets_t **assets, char *name)
{
    under_sound_t *sounds = malloc(sizeof(under_sound_t));

    sounds = malloc(sizeof(under_sound_t));
    sounds->sound = sfSound_create();
    sounds->buffer = sfSoundBuffer_createFromFile(get_asset(name, assets));
    sfSound_setBuffer(sounds->sound, sounds->buffer);
    return sounds;
}

sounds_t *init_sounds(assets_t **assets, game_t *game)
{
    sounds_t *sounds = malloc(sizeof(sounds_t));

    (void)game;
    sounds->pistolet = init_under_sound(assets, "PISTOLET_SOUND");
    sounds->shotgun = init_under_sound(assets, "SHOTGUN_SOUND");
    sounds->assault_rifle = init_under_sound(assets, "ASSAULT_RIFFLE_SOUND");
    sounds->sniper = init_under_sound(assets, "SNIPER_SOUND");
    sounds->smg = init_under_sound(assets, "SMG_SOUND");
    sounds->rocket_l = init_under_sound(assets, "ROCKET_LAUNCHER_SOUND");
    sounds->nadl = init_under_sound(assets, "NADL_SOUND");
    sounds->bullet_hit = init_under_sound(assets, "BULLET_HIT_SOUND");
    sounds->explosion = init_under_sound(assets, "EXPLOSION_SOUND");
    sounds->assault_rifle_rafale = init_under_sound(assets,
        "ASSAULT_RIFFLE_RAFALE");
    sounds->smg_rafale = init_under_sound(assets, "SMG_RAFALE");
    sounds->melee = init_under_sound(assets, "MELEE_SOUND");
    sounds->sound_volume = 100;
    if (game->saveoptions == -1)
        set_volume_for_sounds(sounds, sounds->sound_volume);
    return sounds;
}

music_t *init_music(assets_t **assets, game_t *game)
{
    music_t *music = malloc(sizeof(music_t));

    music->menu_theme = sfMusic_createFromFile(get_asset("Menu_music",
        assets));
    music->combat_music = NULL;
    music->main_theme = sfMusic_createFromFile(
        get_asset("Main_theme", game->assets));
    sfMusic_play(music->menu_theme);
    sfMusic_setLoop(music->menu_theme, sfTrue);
    sfMusic_setLoop(music->main_theme, sfTrue);
    if (game->saveoptions != -1)
        load_musics(game, music);
    else {
        music->music_volume = 100;
        music->mute_volume = sfFalse;
    }
    if (game->saveoptions == -1)
        set_volume_for_musics(music, music->music_volume);
    return music;
}

static int check_open_savefile(game_t *game)
{
    int fd = open(game->savefilepath, O_RDWR);
    struct stat buf;
    char *file = NULL;

    if (fd == -1)
        return -1;
    fstat(fd, &buf);
    if (buf.st_size <= 10)
        return -1;
    file = malloc(sizeof(char) * (buf.st_size + 1));
    read(fd, file, buf.st_size);
    file[buf.st_size] = '\0';
    if (check_here(file, game) == -1) {
        return -1;
    }
    lseek(fd, SEEK_SET, 0);
    return fd;
}

void load_game(game_t *game)
{
    game->keybinds = init_keybind();
    game->savefilepath = last_filepath_choose();
    game->savefile = check_open_savefile(game);
    game->saveoptionsfilepath = my_strdup("./save/Save_file_options.rtb");
    game->saveoptions = open(game->saveoptionsfilepath, O_RDWR);
    game->music = init_music(game->assets, game);
    game->sounds = init_sounds(game->assets, game);
    game->info = init_info(game->assets);
    game->quests = NULL;
    game->view = init_view(game->window);
    game->player = init_player(game, false);
    game->espace_active = false;
    game->level_up_active = false;
}

static void set_up_game(game_t *game)
{
    game->quests = NULL;
    game->window_state = sfDefaultStyle;
    game->player = NULL;
    game->savefilepath = last_filepath_choose();
    game->savefile = check_open_savefile(game);
    game->saveoptionsfilepath = my_strdup("./save/Save_file_options.rtb");
    game->saveoptions = open(game->saveoptionsfilepath, O_RDWR);
    game->sounds = init_sounds(game->assets, game);
    game->video_mode = init_video_mode(game);
    game->window = create_window(game->video_mode.width,
        game->video_mode.height, game->assets);
    game->view = init_view(game->window);
}

game_t *init_game(sfEvent *event)
{
    game_t *game = malloc(sizeof(game_t));

    game->events = event;
    game->keybinds = init_keybind();
    game->assets = init_assets();
    check_assets(game);
    set_up_game(game);
    game->music = init_music(game->assets, game);
    game->guis = init_guis(game->assets);
    game->info = init_info(game->assets);
    game->keybinds->wait_for_key = 0;
    game->espace_active = false;
    game->retour_options_in_game = sfFalse;
    game->level_up_active = false;
    return game;
}
