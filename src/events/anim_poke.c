/*
** EPITECH PROJECT, 2021
** anim_poke.c
** File description:
** anim_poke
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"
#include <time.h>

void move_rect_poke(sfIntRect *rect, int offset, int max_value, all_t *all)
{
    rect->left += offset;
    if (rect->left >= max_value){
        rect->left = 0;
        rect->top += 96;
    }
    if (rect->top >= all->current_poke[1]->rect_max){
        rect->left = 0;
        rect->top = 0;
    }
}

void anim_poke(all_t *all)
{
    srand(time(NULL));
    if (all->current_poke[1]->rect_poke.top == 0)
        all->current_poke[1]->anim_poke = 0;
    if (all->current_poke[1]->anim_poke != 1)
        all->current_poke[1]->anim_poke = rand() % 4;
    if (all->current_poke[1]->anim_poke == 1 && all->fight->state != OUTRO){
        sfTime time = sfClock_getElapsedTime(all->basics->clock);
        float seconds = time.microseconds / 1000000.0;
        if (seconds > 0.08) {
            move_rect_poke(&all->current_poke[1]->rect_poke, 96, 480, all);
            sfSprite_setTextureRect(all->current_poke[1]->sp_front, \
            all->current_poke[1]->rect_poke);
            sfClock_restart(all->basics->clock);
        }
    }
}