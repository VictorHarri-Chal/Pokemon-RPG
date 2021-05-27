/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** resume_menu_event.c
*/

#include "my_rpg.h"
#include "my_struct.h"

void resume_menu_event(all_t *all, sfEvent event)
{   
    btn_scale_resume_menu_event(all, event);
    if (event.type == sfEvtMouseButtonPressed)
        analyse_mouse_event_resume_menu(all, event);
}

void analyse_mouse_event_resume_menu(all_t *all, sfEvent event)
{
    if (is_btn_clicked(event.mouseButton, all->res_menu->res_btn))
        all->scene = GAME;
    if (is_btn_clicked(event.mouseButton, all->res_menu->menu_btn)) {
        all->scene = MENU;
    }
    if (is_btn_clicked(event.mouseButton, all->res_menu->quit_btn)) {
        sfRenderWindow_close(all->basics->window);
        all->scene = END;
    }
    music_btn_event(all, event);
}

void music_btn_event(all_t *all, sfEvent event)
{
    if (is_btn_clicked(event.mouseButton, all->res_menu->sound_btn)) {
        switch (all->res_menu->music_state) {
        case (1) :
            sfMusic_pause(all->basics->music);
            all->res_menu->music_state = 0;
            break;
        case (0):
            sfMusic_play(all->basics->music);
            sfMusic_setLoop(all->basics->music, sfTrue);
            all->res_menu->music_state = 1;
            break;
        }
    }
}

void btn_scale_resume_menu_event(all_t *all, sfEvent event)
{
    sfVector2f big_scale = {1.05, 1.05};
    sfVector2f small_scale = { 1.0, 1.0};
    if (is_mouse_on_btn(event.mouseMove, all->res_menu->res_btn)) {
        sfSprite_setScale(all->res_menu->sp_res, big_scale);
        all->res_menu->res_pos.x = 327;
    }
    else if (!is_mouse_on_btn(event.mouseMove, all->res_menu->res_btn)) {
        sfSprite_setScale(all->res_menu->sp_res, small_scale);
        all->res_menu->res_pos.x = 335;
    }
    if (is_mouse_on_btn(event.mouseMove, all->res_menu->menu_btn)) {
        sfSprite_setScale(all->res_menu->sp_menu, big_scale);
        all->res_menu->menu_pos.x = 327;
    }
    else if (!is_mouse_on_btn(event.mouseMove, all->res_menu->menu_btn)) {
        sfSprite_setScale(all->res_menu->sp_menu, small_scale);
        all->res_menu->menu_pos.x = 335;
    }
    if (is_mouse_on_btn(event.mouseMove, all->res_menu->quit_btn)) {
        sfSprite_setScale(all->res_menu->sp_quit, big_scale);
        all->res_menu->quit_pos.x = 327;
    }
    else if (!is_mouse_on_btn(event.mouseMove, all->res_menu->quit_btn)) {
        sfSprite_setScale(all->res_menu->sp_quit, small_scale);
        all->res_menu->quit_pos.x = 335;
    }
    if (is_mouse_on_btn(event.mouseMove, all->res_menu->sound_btn))
        sfSprite_setScale(all->res_menu->sp_soundon, big_scale);
    else if (!is_mouse_on_btn(event.mouseMove, all->res_menu->sound_btn))
        sfSprite_setScale(all->res_menu->sp_soundon, small_scale);
    if (is_mouse_on_btn(event.mouseMove, all->res_menu->sound_btn))
        sfSprite_setScale(all->res_menu->sp_soundoff, big_scale);
    else if (!is_mouse_on_btn(event.mouseMove, all->res_menu->sound_btn))
        sfSprite_setScale(all->res_menu->sp_soundoff, small_scale);
}