/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** move_arrow_attack
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void pos_left_right_arrow(all_t *all, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight && \
    all->fight->pos_arrow.x <= 750){
        all->fight->pos_arrow.x += 255;
        sfSprite_setPosition(all->fight->sp_arrow_box, all->fight->pos_arrow);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft && \
    all->fight->pos_arrow.x >= 650){
        all->fight->pos_arrow.x -= 255;
        sfSprite_setPosition(all->fight->sp_arrow_box, all->fight->pos_arrow);
    }
}

void pos_up_down_arrow(all_t *all, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown && \
    all->fight->pos_arrow.y <= 550){
        all->fight->pos_arrow.y += 80;
        sfSprite_setPosition(all->fight->sp_arrow_box, all->fight->pos_arrow);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp && \
    all->fight->pos_arrow.y >= 600){
        all->fight->pos_arrow.y -= 80;
        sfSprite_setPosition(all->fight->sp_arrow_box, all->fight->pos_arrow);
    }
}