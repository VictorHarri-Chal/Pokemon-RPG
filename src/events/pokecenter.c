/*
** EPITECH PROJECT, 2021
** pokecenter.c
** File description:
** pokeceneter
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void dialogue_w_joel(all_t *all, sfEvent event)
{
    if (all->dialogue->state == 0){
        all->dialogue = init_textt(all->dialogue, \
        "Bonjour, que puis-je pour vous ?\nA:  Soigner vos Pokemons    \
        B:  Rien,  au revoir\n");
        all->dialogue->state = 1;
    }
    if (all->dialogue->state == 1) {
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyB) {
            all->dialogue = init_text(all->dialogue, \
            "Pas de probleme, bonne journee !\n");
            all->game->state = 0;
            all->dialogue->state = 0;
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA) {
            all->current_poke[0]->all_atk[0]->pp_actual = \
            all->current_poke[0]->all_atk[0]->pp_max;
            all->current_poke[0]->all_atk[1]->pp_actual = \
            all->current_poke[0]->all_atk[1]->pp_max;
            all->current_poke[0]->all_atk[2]->pp_actual = \
            all->current_poke[0]->all_atk[2]->pp_max;
            all->current_poke[0]->all_atk[3]->pp_actual = \
            all->current_poke[0]->all_atk[3]->pp_max;
            all->current_poke[0]->hp_actual = all->current_poke[0]->stat[HP];
            sfRectangleShape_setSize(all->fight->hp_player, \
            (sfVector2f) { 200, 20 });
            sfRectangleShape_setFillColor(all->fight->hp_player, sfGreen);
            sfText_setString(all->fight->texte_hp_actual, \
            my_itoa(all->current_poke[0]->hp_actual));
            all->game->state = 0;
            all->dialogue->state = 0;
        }
    }
}

void interact_with_joel(all_t *all, sfEvent event)
{
    (void) event;
    if (all->dialogue->sprite == NULL) {
        all->dialogue = init_bg(all->dialogue);
    }
    if (all->dialogue->state == 2){
        all->dialogue->state = 0;
        all->game->state = 0;
        sfClock_restart(all->basics->clock);
    }
    dialogue_w_joel(all, event);
}
