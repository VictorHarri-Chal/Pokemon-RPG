/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** fight_poke
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void first_attack(all_t *all)
{
    if (all->fight->pos_arrow.x == 30 && all->fight->pos_arrow.y == 550 && \
    all->current_poke[0]->all_atk[0]->pp_actual > 0) {
        do_attack(all, all->current_poke[0]->all_atk[0], \
        all->current_poke[0], all->current_poke[1]);
        all->current_poke[0]->all_atk[0]->pp_actual--;
        sfText_setString(all->fight->texte_ppactual, \
        my_itoa(all->current_poke[0]->all_atk[1]->pp_actual));
    }
}

void second_attack(all_t *all)
{
    if (all->fight->pos_arrow.x == 360 && all->fight->pos_arrow.y == 550 \
    && all->current_poke[0]->all_atk[1]->pp_actual > 0) {
        do_attack(all, all->current_poke[0]->all_atk[1], \
        all->current_poke[0], all->current_poke[1]);
        all->current_poke[0]->all_atk[1]->pp_actual--;
        sfText_setString(all->fight->texte_ppactual, \
        my_itoa(all->current_poke[0]->all_atk[1]->pp_actual));
    }
}

void third_attack(all_t *all)
{
    if (all->fight->pos_arrow.x == 30 && all->fight->pos_arrow.y == 635 \
    && all->current_poke[0]->all_atk[2]->pp_actual > 0) {
        do_attack(all, all->current_poke[0]->all_atk[2], \
        all->current_poke[0], all->current_poke[1]);
        all->current_poke[0]->all_atk[2]->pp_actual--;
        sfText_setString(all->fight->texte_ppactual, \
        my_itoa(all->current_poke[0]->all_atk[1]->pp_actual));
    }
}

void fourth_attack(all_t *all)
{
    if (all->fight->pos_arrow.x == 360 && all->fight->pos_arrow.y == 635 \
    && all->current_poke[0]->all_atk[3]->pp_actual > 0) {
        do_attack(all, all->current_poke[0]->all_atk[3], \
        all->current_poke[0], all->current_poke[1]);
        all->current_poke[0]->all_atk[3]->pp_actual--;
        sfText_setString(all->fight->texte_ppactual, \
        my_itoa(all->current_poke[0]->all_atk[1]->pp_actual));
    }
}