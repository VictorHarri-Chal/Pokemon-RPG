/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** draw_menu.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void draw_menu(all_t *all)
{
    sfRenderWindow_clear(all->basics->window, sfTransparent);
    sfSprite_setPosition(all->menu->sp_play, all->menu->play_pos);
    sfSprite_setPosition(all->menu->sp_htp, all->menu->htp_pos);
    sfSprite_setPosition(all->menu->sp_quit, all->menu->quit_pos);
    sfRenderWindow_drawSprite(all->basics->window, all->menu->sp_menubg, NULL);
    sfRenderWindow_drawSprite(all->basics->window, all->menu->sp_play, NULL);
    sfRenderWindow_drawSprite(all->basics->window, all->menu->sp_htp, NULL);
    sfRenderWindow_drawSprite(all->basics->window, all->menu->sp_quit, NULL);
    sfRenderWindow_display(all->basics->window);
}
