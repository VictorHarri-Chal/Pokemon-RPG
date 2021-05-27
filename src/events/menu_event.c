/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** menu_event.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void menu_event(all_t *all, sfEvent event)
{
    btn_scale_menu_event(all, event);
    if (event.type == sfEvtMouseButtonPressed)
        analyse_mouse_event_menu(all, event);
}

void analyse_mouse_event_menu(all_t *all, sfEvent event)
{
    if (is_btn_clicked(event.mouseButton, all->menu->play_btn))
        all->scene = GAME;
    if (is_btn_clicked(event.mouseButton, all->menu->htp_btn))
        all->scene = HTP;
    if (is_btn_clicked(event.mouseButton, all->menu->quit_btn)) {
        sfRenderWindow_close(all->basics->window);
        all->scene = END;
    }
}

void btn_scale_menu_event(all_t *all, sfEvent event)
{
    sfVector2f big_scale = {1.05, 1.05};
    sfVector2f small_scale = { 1.0, 1.0};
    if (is_mouse_on_btn(event.mouseMove, all->menu->play_btn)) {
        sfSprite_setScale(all->menu->sp_play, big_scale);
        all->menu->play_pos.x = 327;
    }
    else if (!is_mouse_on_btn(event.mouseMove, all->menu->play_btn)) {
        sfSprite_setScale(all->menu->sp_play, small_scale);
        all->menu->play_pos.x = 335;
    }
    if (is_mouse_on_btn(event.mouseMove, all->menu->htp_btn)) {
        sfSprite_setScale(all->menu->sp_htp, big_scale);
        all->menu->htp_pos.x = 327;
    }
    else if (!is_mouse_on_btn(event.mouseMove, all->menu->htp_btn)) {
        sfSprite_setScale(all->menu->sp_htp, small_scale);
        all->menu->htp_pos.x = 335;
    }
    if (is_mouse_on_btn(event.mouseMove, all->menu->quit_btn)) {
        sfSprite_setScale(all->menu->sp_quit, big_scale);
        all->menu->quit_pos.x = 327;
    }
    else if (!is_mouse_on_btn(event.mouseMove, all->menu->quit_btn)) {
        sfSprite_setScale(all->menu->sp_quit, small_scale);
        all->menu->quit_pos.x = 335;
    }
}