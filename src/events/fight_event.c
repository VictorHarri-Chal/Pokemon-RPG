/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** fight_event
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void pos_arrow_left(all_t *all)
{
    if (all->fight->pos_arrow.x == 30 && all->fight->pos_arrow.y == 550) {
        sfText_setString(all->fight->texte_ppmax, \
        my_itoa(all->current_poke[0]->all_atk[0]->pp_max));
        sfText_setString(all->fight->texte_ppactual, \
        my_itoa(all->current_poke[0]->all_atk[0]->pp_actual));
        sfText_setString(all->fight->texte_type, \
        get_type(all->current_poke[0]->all_atk[0]->type));
    }
}

void pos_arrow_right(all_t *all)
{
    if (all->fight->pos_arrow.x == 360 && all->fight->pos_arrow.y == 550) {
        sfText_setString(all->fight->texte_ppmax, \
        my_itoa(all->current_poke[0]->all_atk[1]->pp_max));
        sfText_setString(all->fight->texte_ppactual, \
        my_itoa(all->current_poke[0]->all_atk[1]->pp_actual));
        sfText_setString(all->fight->texte_type, \
        get_type(all->current_poke[0]->all_atk[1]->type));
    }
}

void pos_arrow_leftdown(all_t *all)
{
    if (all->fight->pos_arrow.x == 30 && all->fight->pos_arrow.y == 635) {
        sfText_setString(all->fight->texte_ppmax, \
        my_itoa(all->current_poke[0]->all_atk[2]->pp_max));
        sfText_setString(all->fight->texte_ppactual, \
        my_itoa(all->current_poke[0]->all_atk[2]->pp_actual));
        sfText_setString(all->fight->texte_type, \
        get_type(all->current_poke[0]->all_atk[2]->type));
    }
}

void pos_arrow_rightdown(all_t *all)
{
    if (all->fight->pos_arrow.x == 360 && all->fight->pos_arrow.y == 635) {
        sfText_setString(all->fight->texte_ppmax, \
        my_itoa(all->current_poke[0]->all_atk[3]->pp_max));
        sfText_setString(all->fight->texte_ppactual, \
        my_itoa(all->current_poke[0]->all_atk[3]->pp_actual));
        sfText_setString(all->fight->texte_type, \
        get_type(all->current_poke[0]->all_atk[3]->type));
    }
}

void detect_arrow(sfEvent event, all_t *all)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight && \
    all->fight->pos_arrow.x <= 200){
        all->fight->pos_arrow.x += 330;
        sfSprite_setPosition(all->fight->sp_arrow_box, all->fight->pos_arrow);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft && \
    all->fight->pos_arrow.x >= 100){
        all->fight->pos_arrow.x -= 330;
        sfSprite_setPosition(all->fight->sp_arrow_box, all->fight->pos_arrow);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown && \
    all->fight->pos_arrow.y <= 550){
        all->fight->pos_arrow.y += 85;
        sfSprite_setPosition(all->fight->sp_arrow_box, all->fight->pos_arrow);
    }
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp && \
    all->fight->pos_arrow.y >= 600){
        all->fight->pos_arrow.y -= 85;
        sfSprite_setPosition(all->fight->sp_arrow_box, all->fight->pos_arrow);
    }
}