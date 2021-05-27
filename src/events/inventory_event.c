/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** inventory_event.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void inventory_event(all_t *all, sfEvent event)
{
    if (all->inventory->inventory_state != 6 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        all->inventory->inventory_state += 1;
    if (all->inventory->inventory_state != 0 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        all->inventory->inventory_state -= 1;
    inventory_button_event(all, event);
}

void inventory_button_event(all_t *all, sfEvent event)
{
    if (all->inventory->inventory_state == 2 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
        all->scene = INV_BAG;
    if (all->inventory->inventory_state == 5 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
        all->scene = RESUME_MENU;
    if (all->inventory->inventory_state == 6 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
        all->scene = GAME;
}