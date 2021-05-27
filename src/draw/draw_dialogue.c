/*
** EPITECH PROJECT, 2021
** draw_dialoge.c
** File description:
** draw_dialoge
*/

#include "my_rpg.h"
#include "my_struct.h"

void draw_dialogue(all_t *all)
{
    sfSprite_setPosition(all->dialogue->sprite, all->dialogue->pos);
    sfRenderWindow_drawSprite(all->basics->window, all->dialogue->sprite, NULL);
    if (all->game->state == 1)
        sfRenderWindow_drawText(all->basics->window, \
        all->dialogue->text2, NULL);
    if (all->game->state == 4)
        sfRenderWindow_drawText(all->basics->window, all->dialogue->text, NULL);
}