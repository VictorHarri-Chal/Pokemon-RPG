/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** update_hero.c
*/

#include "my_rpg.h"
#include "my_struct.h"

void move_rect(sfIntRect *rect, int offset, int max_value)
{
    rect->left += offset;
    if (rect->left >= max_value)
        rect->left = 0;
}

void move_up(all_t *all, int speed)
{
    sfTime time = sfClock_getElapsedTime(all->basics->clock);
    float seconds = time.microseconds / 1000000.0;
    all->game->rect_hero.top = 0;

    if (seconds > 0.03) {
        move_rect(&all->game->rect_hero, 67, 201);
        all->game->map_pos.y += speed;
        all->game->hero_pos_text.y -= speed / 3;
        sfSprite_setTextureRect(all->game->sp_hero, all->game->rect_hero);
        sfClock_restart(all->basics->clock);
    }
}

void move_down(all_t *all, int speed)
{
    sfTime time = sfClock_getElapsedTime(all->basics->clock);
    float seconds = time.microseconds / 1000000.0;
    all->game->rect_hero.top = 70.5;

    if (seconds > 0.03) {
        move_rect(&all->game->rect_hero, 67, 201);
        all->game->map_pos.y -= speed;
        all->game->hero_pos_text.y += speed / 3;
        sfSprite_setTextureRect(all->game->sp_hero, all->game->rect_hero);
        sfClock_restart(all->basics->clock);
    }
}

void move_left(all_t *all, int speed)
{
    sfTime time = sfClock_getElapsedTime(all->basics->clock);
    float seconds = time.microseconds / 1000000.0;
    all->game->rect_hero.top = 139;

    if (seconds > 0.03) {
        move_rect(&all->game->rect_hero, 67, 201);
        all->game->map_pos.x += speed;
        all->game->hero_pos_text.x -= speed / 3;
        sfSprite_setTextureRect(all->game->sp_hero, all->game->rect_hero);
        sfClock_restart(all->basics->clock);
    }
}

void move_right(all_t *all, int speed)
{
    sfTime time = sfClock_getElapsedTime(all->basics->clock);
    float seconds = time.microseconds / 1000000.0;
    all->game->rect_hero.top = 208.5;
    if (seconds > 0.03) {
        move_rect(&all->game->rect_hero, 67, 201);
        all->game->map_pos.x -= speed;
        all->game->hero_pos_text.x += speed / 3;
        sfSprite_setTextureRect(all->game->sp_hero, all->game->rect_hero);
        sfClock_restart(all->basics->clock);
    }
}
