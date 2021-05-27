/*
** EPITECH PROJECT, 2021
** init_curent_poke.c
** File description:
** init_curent_poke
*/

#include "my_rpg.h"
#include "my_struct.h"

pokemon_t **init_curent_poke(void)
{
    pokemon_t **curent = malloc(sizeof(*curent) * 8);
    for (int i = 0; i < 7; i++)
        curent[i] = malloc(sizeof(**curent));
    curent[7] = NULL;
    return (curent);
}