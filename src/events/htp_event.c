/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** htp_event.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void htp_event(all_t *all, sfEvent event)
{
    if (event.type == sfEvtMouseButtonPressed)
        analyse_mouse_event_htp(all, event);
}

void analyse_mouse_event_htp(all_t *all, sfEvent event)
{
    if (is_btn_clicked(event.mouseButton, all->htp->quit_btn)) {
        all->scene = MENU;
    }
}
