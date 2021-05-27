/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_all_struct.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void set_string(all_t *all)
{
    all->current_poke[0] = \
    init_pokemon(all->current_poke[0], all->pokedex_index[1]);
    sfText_setString(all->fight->texte_level_player, \
    my_itoa(all->current_poke[0]->level + 1));
    sfText_setString(all->fight->texte_name_player, all->current_poke[0]->name);
    sfText_setString(all->fight->texte_hp_actual, \
    my_itoa(all->current_poke[0]->hp_actual));
    sfText_setString(all->fight->texte_hp_max, \
    my_itoa(all->current_poke[0]->stat[HP]));
    sfText_setString(all->fight->texte_atk1, \
    all->current_poke[0]->all_atk[0]->name);
    sfText_setString(all->fight->texte_atk2, \
    all->current_poke[0]->all_atk[1]->name);
    sfText_setString(all->fight->texte_atk3, \
    all->current_poke[0]->all_atk[2]->name);
    sfText_setString(all->fight->texte_atk4, \
    all->current_poke[0]->all_atk[3]->name);
    sfText_setString(all->fight->texte_ppactual, \
    my_itoa(all->current_poke[0]->all_atk[0]->pp_actual));
}

all_t *init_all_struct(void)
{
    all_t *all = malloc(sizeof(*all));
    if (!all)
        return (NULL);
    all->scene = MENU;
    all->basics = init_basics();
    all->menu = init_menu();
    all->res_menu = init_resume_menu();
    all->game = init_game();
    all->htp = init_how_to_play();
    all->fight = init_fight();
    all->inventory = init_inventory();
    all->attack_index = init_attack_index();
    all->pokedex_index = init_pokedex_index(all->attack_index);
    all->dialogue = init_all_dialogue();
    all->current_poke = init_curent_poke();
    set_string(all);
    sfText_setString(all->fight->texte_ppmax, \
    my_itoa(all->current_poke[0]->all_atk[0]->pp_max));
    all->nb_poke = 1;
    return (all);
}
