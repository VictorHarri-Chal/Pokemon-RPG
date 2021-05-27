/*
** EPITECH PROJECT, 2021
** rdm_poke.c
** File description:
** rdm_poke
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"
#include <time.h>

void find_rdm_poke(all_t *all)
{
    int rdm = rand() % 6;
    while (my_strcmp(all->current_poke[0]->name, \
    all->pokedex_index[rdm]->name) == 0)
        rdm = rand() % 6;
    init_pokemon(all->current_poke[all->nb_poke], all->pokedex_index[rdm]);
    sfText_setString(all->fight->texte_level_enemie, \
    my_itoa(all->current_poke[1]->level + 1));
    sfText_setString(all->fight->texte_name_enemie, all->current_poke[1]->name);
    all->current_poke[all->nb_poke + 1] = NULL;
}