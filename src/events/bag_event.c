/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** bag_event.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void bag_event(all_t *all, sfEvent event)
{
    if (all->inventory->bag_state == 0 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
        my_putstr("USING POKEBALL\n");
    if (all->inventory->bag_state == 1 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyEnter)
        my_putstr("USING POTION\n");
    if (all->inventory->bag_state != 0 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        all->inventory->bag_state -= 1;
    if (all->inventory->bag_state != 1 && \
    event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft)
        all->inventory->bag_state += 1;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        all->scene = INVENTORY;
}
