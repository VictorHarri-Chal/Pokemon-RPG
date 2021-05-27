/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** draw_game.c
*/

#include "my_rpg.h"
#include "my_struct.h"

void draw_game(all_t *all)
{
    sfRenderWindow_clear(all->basics->window, sfTransparent);
    sfSprite_setPosition(all->game->sp_gamebg, all->game->map_pos);
    sfRenderWindow_drawSprite(all->basics->window, all->game->sp_gamebg, NULL);
    sfSprite_setPosition(all->game->sp_hero, all->game->hero_pos);
    sfRenderWindow_drawSprite(all->basics->window, all->game->sp_hero, NULL);
    sfSprite_setTextureRect(all->game->sp_hero, all->game->rect_hero);
    if (all->game->state != 0)
        draw_dialogue(all);
    sfRenderWindow_display(all->basics->window);
    if (all->dialogue && all->dialogue->state == 2)
        sleep(30);
}
