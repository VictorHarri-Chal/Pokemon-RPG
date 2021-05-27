/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** draw_inventory.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void draw_inventory(all_t *all)
{
    sfRenderWindow_clear(all->basics->window, sfTransparent);
    sfSprite_setPosition(all->game->sp_gamebg, all->game->map_pos);
    sfSprite_setPosition(all->game->sp_hero, all->game->hero_pos);
    sfRenderWindow_drawSprite(all->basics->window, all->game->sp_gamebg, NULL);
    sfRenderWindow_drawSprite(all->basics->window, all->game->sp_hero, NULL);
    sfRenderWindow_drawSprite(all->basics->window, \
    all->inventory->sp_inv[all->inventory->inventory_state], NULL);
    sfRenderWindow_display(all->basics->window);
}
