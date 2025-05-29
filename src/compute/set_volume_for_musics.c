/*
** EPITECH PROJECT, 2024
** analyze_options
** File description:
** analyze_options
*/
#include "my.h"
#include "gui_struct.h"
#include <stdlib.h>

static void set_volume_for_firearms(sounds_t *sounds, float volume)
{
    if (sounds->rocket_l)
        sfSound_setVolume(sounds->rocket_l->sound, volume);
    if (sounds->assault_rifle_rafale)
        sfSound_setVolume(sounds->assault_rifle_rafale->sound, volume);
    if (sounds->smg_rafale)
        sfSound_setVolume(sounds->smg_rafale->sound, volume);
    if (sounds->pistolet)
        sfSound_setVolume(sounds->pistolet->sound, volume);
    if (sounds->shotgun)
        sfSound_setVolume(sounds->shotgun->sound, volume);
    if (sounds->assault_rifle)
        sfSound_setVolume(sounds->assault_rifle->sound, volume);
    if (sounds->sniper)
        sfSound_setVolume(sounds->sniper->sound, volume);
    if (sounds->smg)
        sfSound_setVolume(sounds->smg->sound, volume);
    if (sounds->nadl)
        sfSound_setVolume(sounds->nadl->sound, volume);
}

void set_volume_for_sounds(sounds_t *sounds, float volume)
{
    volume = volume * 2.3;
    if (volume > 100)
        volume = 100;
    if (sounds->explosion)
        sfSound_setVolume(sounds->explosion->sound, volume);
    if (sounds->bullet_hit)
        sfSound_setVolume(sounds->bullet_hit->sound, volume);
    if (sounds->melee)
        sfSound_setVolume(sounds->melee->sound, volume);
    set_volume_for_firearms(sounds, volume);
}

void set_general_volume(game_t *game)
{
    if (game->music->mute_volume == true) {
        set_volume_for_sounds(game->sounds, 0);
        set_volume_for_musics(game->music, 0);
    } else {
        set_volume_for_sounds(game->sounds, game->sounds->sound_volume);
        set_volume_for_musics(game->music, game->music->music_volume);
    }
}

void set_volume_for_musics(music_t *music, float volume)
{
    volume = volume * 0.5;
    if (music->main_theme)
        sfMusic_setVolume(music->main_theme, volume);
    if (music->menu_theme) {
        sfMusic_setVolume(music->menu_theme, volume);
    }
    if (music->combat_music) {
        sfMusic_setVolume(music->combat_music, volume / 2);
    }
}
