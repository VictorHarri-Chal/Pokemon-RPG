/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** draw_resume_menu.c
*/

#include "my_rpg.h"
#include "my_struct.h"

void draw_resume_menu(all_t *all)
{
    sfRenderWindow_clear(all->basics->window, sfTransparent);
    sfSprite_setPosition(all->res_menu->sp_res, all->res_menu->res_pos);
    sfSprite_setPosition(all->res_menu->sp_menu, all->res_menu->menu_pos);
    sfSprite_setPosition(all->res_menu->sp_quit, all->res_menu->quit_pos);
    sfSprite_setPosition(all->res_menu->sp_soundoff, all->res_menu->sound_pos);
    sfSprite_setPosition(all->res_menu->sp_soundon, all->res_menu->sound_pos);
    sfRenderWindow_drawSprite(all->basics->window, all->res_menu->sp_resbg, \
    NULL);
    sfRenderWindow_drawSprite(all->basics->window, all->res_menu->sp_res, NULL);
    sfRenderWindow_drawSprite(all->basics->window, \
    all->res_menu->sp_menu, NULL);
    sfRenderWindow_drawSprite(all->basics->window, \
    all->res_menu->sp_quit, NULL);
    if (all->res_menu->music_state == 1) {
        sfRenderWindow_drawSprite(all->basics->window, \
        all->res_menu->sp_soundoff, NULL); }
    if (all->res_menu->music_state == 0) {
        sfRenderWindow_drawSprite(all->basics->window, \
        all->res_menu->sp_soundon, NULL); }
    sfRenderWindow_display(all->basics->window);
}
