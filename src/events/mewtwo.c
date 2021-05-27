/*
** EPITECH PROJECT, 2021
** mewtwo.c
** File description:
** mewtwo
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void init_mewtwo(all_t *all)
{
    all->scene = FIGHT;
    all->fight->state = INTRO;
    init_pokemon(all->current_poke[1], all->pokedex_index[10]);
    all->current_poke[1]->level = 74;
    sfText_setString(all->fight->texte_level_enemie, \
    my_itoa(all->current_poke[1]->level + 1));
    sfText_setString(all->fight->texte_name_enemie, all->current_poke[1]->name);
    all->current_poke[all->nb_poke + 1] = NULL;
}

void update_info_poke(all_t *all)
{
    sfRectangleShape_setSize(all->fight->xp_player, (sfVector2f) { 0, 9 });
    sfText_setString(all->fight->texte_level_player, \
    my_itoa(all->current_poke[0]->level + 1));
    sfText_setString(all->fight->texte_hp_max, \
    my_itoa(all->current_poke[0]->stat[HP]));
    sfText_setString(all->fight->texte_hp_actual, \
    my_itoa(all->current_poke[0]->hp_actual));
    sfRectangleShape_setSize(all->fight->hp_player, \
    (sfVector2f) { 200, 20 });
    sfRectangleShape_setFillColor(all->fight->hp_player, sfGreen);
}