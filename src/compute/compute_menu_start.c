/*
** EPITECH PROJECT, 2024
** compute_menu_start
** File description:
** compute_menu_start
*/

#include "my.h"

static void compute_drone(img_t *drone)
{
    sfVector2f pos = sfSprite_getPosition(drone->sprite);
    float deltatime = sfClock_getElapsedTime(
        drone->animate->clock_intern->clock).microseconds / 1000000.0;

    sfClock_restart(drone->animate->clock_intern->clock);
    pos.x += 200 * deltatime;
    if (pos.x > 2200) {
        pos.x = -((rand() % 1000) + 3000);
        pos.y = (rand() % 500 + 100);
    }
    sfSprite_setPosition(drone->sprite, pos);
}

static void move_one_cloud(int speed, img_t *cloud)
{
    sfVector2f pos = sfSprite_getPosition(cloud->sprite);
    float deltatime = sfClock_getElapsedTime(
        cloud->animate->clock_intern->clock).microseconds / 1000000.0;

    sfClock_restart(cloud->animate->clock_intern->clock);
    pos.x += speed * deltatime;
    if (pos.x > 1850) {
        pos.x = -(rand() % 200 + 800);
        pos.y = 600 + rand() % 100;
    }
    sfSprite_setPosition(cloud->sprite, pos);
}

static void compute_clouds(img_t **clouds)
{
    move_one_cloud(25, clouds[0]);
    move_one_cloud(20, clouds[1]);
    move_one_cloud(30, clouds[2]);
    move_one_cloud(25, clouds[3]);
    move_one_cloud(50, clouds[4]);
    move_one_cloud(15, clouds[5]);
    move_one_cloud(30, clouds[6]);
    move_one_cloud(50, clouds[7]);
    move_one_cloud(25, clouds[8]);
    move_one_cloud(45, clouds[9]);
    move_one_cloud(40, clouds[10]);
    move_one_cloud(45, clouds[11]);
}

static void next_frame(animated_img_t *image)
{
    move_rect(image, true);
    sfClock_restart(image->clock_animation->clock);
    image->clock_animation->seconds = 0;
}

static void compute_background(animated_img_t *image)
{
    image->clock_animation->time = sfClock_getElapsedTime(
        image->clock_animation->clock);
    image->clock_animation->seconds +=
        image->clock_animation->time.microseconds / 10000000.0;
    if (image->clock_animation->seconds > 400 && image->status_image == 0)
        next_frame(image);
    if (image->clock_animation->seconds > 0.5 && image->status_image == 1)
        next_frame(image);
    if (image->clock_animation->seconds > 0.5 && image->status_image == 2)
        next_frame(image);
    if (image->clock_animation->seconds > 0.1 && image->status_image == 3)
        next_frame(image);
}

void compute_menu_main(ui_obj_t *obj, game_t *game)
{
    main_t *main_menu = (main_t *)obj->ui_content;

    compute_animation_img(main_menu->hero->animate, true);
    compute_animation_img(main_menu->drone->animate, true);
    compute_drone(main_menu->drone);
    compute_clouds(main_menu->clouds);
    compute_background(main_menu->background->animate);
    compute_state_buttons(main_menu, game);
}

void compute_menu_start(ui_obj_t *obj, game_t *game)
{
    start_t *main_menu = (start_t *)obj->ui_content;

    compute_animation_img(main_menu->hero->animate, true);
    compute_animation_img(main_menu->drone->animate, true);
    compute_drone(main_menu->drone);
    compute_clouds(main_menu->clouds);
    compute_background(main_menu->background->animate);
    compute_state_buttons_two(main_menu, game);
}
