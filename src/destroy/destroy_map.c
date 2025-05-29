/*
** EPITECH PROJECT, 2024
** destroy_map
** File description:
** destroy_map
*/

#include "my.h"

static void destroy_diag_pipe(diag_pipe_t *diag_pipe)
{
    destroy_image(diag_pipe->background);
    if (diag_pipe->clock != NULL)
        destroy_time(diag_pipe->clock);
    if (diag_pipe->label != NULL)
        destroy_label(diag_pipe->label);
    if (diag_pipe->text != NULL)
        free(diag_pipe->text);
    if (diag_pipe->portrait != NULL)
        destroy_image(diag_pipe->portrait);
    free(diag_pipe);
}

void destroy_game_map(map_panel_image_t *map)
{
    for (int r = 0; map->map[r]; r++) {
        for (int c = 0; map->map[r][c]; c++) {
            destroy_image(map->map[r][c]->map);
            sfImage_destroy(map->map[r][c]->col);
        }
        free(map->map[r]);
    }
}

void destroy_map(map_t *map)
{
    if (!map)
        return;
    destroy_diag_pipe(map->dialogue_pipeline);
    destroy_entity(map->entity_all);
    destroy_game_map(map->map);
    free(map);
}
