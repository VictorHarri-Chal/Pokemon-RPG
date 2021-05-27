/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** draw_bag.c
*/

#include "my_rpg.h"
#include "my_struct.h"

void draw_bag(all_t *all)
{
    sfRenderWindow_clear(all->basics->window, sfTransparent);
    if (all->inventory->bag_state == 0)
        sfRenderWindow_drawSprite(all->basics->window, \
        all->inventory->sp_bag1, NULL);
    if (all->inventory->bag_state == 1)
        sfRenderWindow_drawSprite(all->basics->window, \
        all->inventory->sp_bag2, NULL);
    sfRenderWindow_display(all->basics->window);
}

