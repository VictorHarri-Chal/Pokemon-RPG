/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** game_event2.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

char *tp_forest_hero(all_t *all, int py, int px)
{
    if ((py >= 1503 && py <= 1505) && (px >= 289 && px <= 321)){
        all->game->hero_pos_text.y -= 125;
        all->game->map_pos.y += 125 * 3;
        return (NULL);
    }
    if ((py >= 1386 && py <= 1388) && (px >= 289 && px <= 321)){
        all->game->hero_pos_text.y += 125;
        all->game->map_pos.y -= 125 * 3;
        return (NULL);
    }
    return ("ok");
}

void if_pokecenter(all_t *all, sfEvent event)
{
    if (check_coll(all, event) == 1){
        all->game->old_hero_pos_text = all->game->hero_pos_text;
        all->game->old_map_pos = all->game->map_pos;
        all->game->hero_pos_text.x = 1983;
        all->game->hero_pos_text.y = 555;
        all->game->map_pos.x = -5360;
        all->game->map_pos.y = -1250;
    }
}

void if_pokeshop(all_t *all, sfEvent event)
{
    if (check_coll(all, event) == 2){
        all->game->old_hero_pos_text = all->game->hero_pos_text;
        all->game->old_map_pos = all->game->map_pos;
        all->game->hero_pos_text.x = 1507;
        all->game->hero_pos_text.y = 215;
        all->game->map_pos.x = -3934;
        all->game->map_pos.y = -235;
    }
}

void if_tpback(all_t *all, sfEvent event)
{
    if (check_coll(all, event) == 4){
        all->game->hero_pos_text.x = all->game->old_hero_pos_text.x;
        all->game->hero_pos_text.y = all->game->old_hero_pos_text.y;
        all->game->map_pos.x = all->game->old_map_pos.x;
        all->game->map_pos.y = all->game->old_map_pos.y;
    }
}

void hero_mouv_event(all_t *all, sfEvent event)
{
    int px = all->game->hero_pos_text.x;
    int py = all->game->hero_pos_text.y;
    if (tp_forest_hero(all, py, px) == NULL)
        return;
    if_pokecenter(all, event);
    if_pokeshop(all, event);
    if_tpback(all, event);
    if_house_player(all, event);
    if_labo(all, event);
    if_arene(all, event);
    if_move(all, event);
    if_pokemon(all, event);
    if_precise_event(all, event);
}
