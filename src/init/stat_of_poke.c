/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** stat_of_poke
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void stat_of_poke(pokemon_t *index, char **tmp_arr)
{
    index->stat[HP] = my_getnbr(tmp_arr[2]);
    index->stat[ATK] = my_getnbr(tmp_arr[3]);
    index->stat[SPEED] = my_getnbr(tmp_arr[4]);
}