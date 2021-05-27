/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** fight2.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

char *get_type(type_t type)
{
    switch (type) {
        case 0:
            return ("Fire");
            break;
        case 1:
            return ("Water");
            break;
        case 2:
            return ("Grass");
            break;
        case 3:
            return ("Normal");
            break;
        case 4:
            return ("Rock");
            break;
        case 5:
            return ("Psy");
            break;
        case 6:
            return ("Ground");
            break;
    }
    return (NULL);
}

void update_info(all_t *all)
{
    pos_arrow_left(all);
    pos_arrow_right(all);
    pos_arrow_leftdown(all);
    pos_arrow_rightdown(all);
}

void arrow_attack_box(all_t *all, sfEvent event)
{
    detect_arrow(event, all);
    update_info(all);
}

void calc_xp(all_t *all)
{
    all->current_poke[0]->xp += 5;
    sfVector2f xp_actual = sfRectangleShape_getSize(all->fight->xp_player);
    xp_actual.x += (all->current_poke[0]->xp * 256 / 30);
    sfRectangleShape_setSize(all->fight->xp_player, xp_actual);
    if (all->current_poke[0]->xp >= 20) {
        all->current_poke[0]->level++;
        all->current_poke[0]->xp = 0;
        all->current_poke[0]->stat[HP] += 2;
        all->current_poke[0]->hp_actual = all->current_poke[0]->stat[HP];
        all->current_poke[0]->stat[ATK] += 1;
        all->current_poke[0]->stat[SPEED] += 1;
        update_info_poke(all);
    }
}

void state_end_fight(all_t *all)
{
    if (all->fight->state == END_FIGHT){
        all->scene = GAME;
        all->fight->state = NO_FIGHT;
        draw_game(all);
    }
}
