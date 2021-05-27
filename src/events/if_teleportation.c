/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** if_teleportation
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void if_house_player(all_t *all, sfEvent event)
{
    if (check_coll(all, event) == 5){
        all->game->old_hero_pos_text = all->game->hero_pos_text;
        all->game->old_map_pos = all->game->map_pos;
        all->game->hero_pos_text.x = 2503;
        all->game->hero_pos_text.y = 225;
        all->game->map_pos.x = -6930;
        all->game->map_pos.y = -260;
    }
}

void if_labo(all_t *all, sfEvent event)
{
    if (check_coll(all, event) == 6){
        all->game->old_hero_pos_text = all->game->hero_pos_text;
        all->game->old_map_pos = all->game->map_pos;
        all->game->hero_pos_text.x = 2463;
        all->game->hero_pos_text.y = 610;
        all->game->map_pos.x = -6810;
        all->game->map_pos.y = -1420;
    }
}

void if_arene(all_t *all, sfEvent event)
{
    if (check_coll(all, event) == 7){
        all->game->old_hero_pos_text = all->game->hero_pos_text;
        all->game->old_map_pos = all->game->map_pos;
        all->game->hero_pos_text.x = 1445;
        all->game->hero_pos_text.y = 830;
        all->game->map_pos.x = -3758;
        all->game->map_pos.y = -2070;
    }
}

void if_move(all_t *all, sfEvent event)
{
    if (check_coll(all, event) == 0 || check_coll(all, event) == 3){
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
            move_up(all, 9);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
            move_down(all, 9);
        if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft))
            move_left(all, 9);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
            move_right(all, 9);
    }
}

void if_pokemon(all_t *all, sfEvent event)
{
    if (check_coll(all, event) == 3 && all->current_poke[0] != NULL){
        if (rand() % 40 == 0){
            all->scene = FIGHT;
            all->fight->state = INTRO;
            find_rdm_poke(all);
        }
    }
}