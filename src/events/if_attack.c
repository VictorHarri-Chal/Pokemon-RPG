/*
** EPITECH PROJECT, 2021
** if attack
** File description:
** if_attack
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"
#include <time.h>

void do_attack_ennemies(all_t *all, attack_t *attack, \
pokemon_t *pokemon, pokemon_t *ennemie)
{
    int dmg = attack->dmg;
    dmg = (dmg * pokemon->stat[ATK]) / (ennemie->stat[HP] * 7);
    ennemie->hp_actual -= dmg;
    sfVector2f size = sfRectangleShape_getSize(all->fight->hp_player);
    size.x -= (dmg * 200 / ennemie->stat[HP]);
    if (ennemie->hp_actual == 1 || ennemie->hp_actual == 2) {
        size.x = 10;
    }
    if (size.x <= 255 / 2)
        sfRectangleShape_setFillColor(all->fight->hp_player, sfYellow);
    if (size.x <= 255 / 5)
        sfRectangleShape_setFillColor(all->fight->hp_player, sfRed);
    sfRectangleShape_setSize(all->fight->hp_player, size);
    sfText_setString(all->fight->texte_hp_actual, my_itoa(ennemie->hp_actual));
}

void do_attack(all_t *all, attack_t *attack, \
pokemon_t *pokemon, pokemon_t *ennemie)
{
    int dmg = attack->dmg;
    dmg = (dmg * pokemon->stat[ATK]) / (ennemie->stat[HP] * 7);
    ennemie->hp_actual -= dmg;
    sfVector2f size = sfRectangleShape_getSize(all->fight->hp_ennemi);
    size.x -= (dmg * 200 / ennemie->stat[HP]);
    if (ennemie->hp_actual == 1 || ennemie->hp_actual == 2) {
        size.x = 10;
    }
    if (size.x <= 255 / 2)
        sfRectangleShape_setFillColor(all->fight->hp_ennemi, sfYellow);
    if (size.x <= 255 / 5)
        sfRectangleShape_setFillColor(all->fight->hp_ennemi, sfRed);
    sfRectangleShape_setSize(all->fight->hp_ennemi, size);
}

void check_if_attack(all_t *all, sfEvent event)
{
    int rando = 0;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyZ) {
        first_attack(all);
        second_attack(all);
        third_attack(all);
        fourth_attack(all);
        srand(time(NULL));
        rando = rand() % 3;
        do_attack_ennemies(all, all->current_poke[1]->all_atk[rando], \
        all->current_poke[1], all->current_poke[0]);
        all->current_poke[1]->all_atk[rando]->pp_actual--;
    }
}