/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** stat_poke
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void stat_attack_poke(pokemon_t *pokemon_dest, pokemon_t *pokemon_src)
{
    pokemon_dest->name = my_strcpy(pokemon_dest->name, pokemon_src->name);
    pokemon_dest->type = pokemon_src->type;
    pokemon_dest->stat = malloc(sizeof(int) * 3);
    pokemon_dest->stat[0] = pokemon_src->stat[0];
    pokemon_dest->stat[1] = pokemon_src->stat[1];
    pokemon_dest->stat[2] = pokemon_src->stat[2];
    pokemon_dest->hp_actual = pokemon_dest->stat[0];
}

void if_precise_event(all_t *all, sfEvent event)
{
    if (((all->game->hero_pos_text.x >= 1980 && all->game->hero_pos_text.x \
        <= 2010) && (all->game->hero_pos_text.y >= 485 && \
        all->game->hero_pos_text.y <= 495))) {
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyA) {
            all->game->state = 1;
        }
    }
    if (((all->game->hero_pos_text.x >= 2451 && all->game->hero_pos_text.x \
        <= 2475) && (all->game->hero_pos_text.y >= 487 && \
        all->game->hero_pos_text.y <= 493))) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA) {
        }
    }
    if (((all->game->hero_pos_text.x >= 1436 && all->game->hero_pos_text.x \
        <= 1448) && (all->game->hero_pos_text.y >= 464 && \
        all->game->hero_pos_text.y <= 470)) && all->current_poke[0] != NULL){
        if (event.type == sfEvtKeyReleased && event.key.code == sfKeyA) {
            init_mewtwo(all);
        }
    }
}
