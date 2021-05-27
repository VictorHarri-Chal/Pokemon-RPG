/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** my_rpg.c
*/

#include "my_rpg.h"
#include "my_struct.h"

int my_rpg(void)
{
    all_t *all = all = init_all_struct();

    sfMusic_play(all->basics->music);
    loop(all);
    return (0);
}
