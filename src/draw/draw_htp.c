/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** draw_htp.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void draw_htp(all_t *all)
{
    sfRenderWindow_clear(all->basics->window, sfTransparent);
    sfSprite_setPosition(all->htp->sp_quit, all->htp->quit_pos);
    sfRenderWindow_drawSprite(all->basics->window, all->htp->sp_htpbg, NULL);
    sfRenderWindow_drawSprite(all->basics->window, all->htp->sp_quit, NULL);
    sfRenderWindow_display(all->basics->window);
}