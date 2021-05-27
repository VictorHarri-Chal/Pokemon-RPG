/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** hero_mouv_event
*/

#include "my_rpg.h"
#include "my_struct.h"

void hero_mouv_event(all_t *all, sfEvent event)
{
    int px = all->game->hero_pos_text.x;
    int py = all->game->hero_pos_text.y;
    bool npc = false;

    if (is_hero_at_teleport_up(py, px))
        teleport_up(all->game);
    if (is_hero_at_teleport_down(py, px))
        teleport_down(all->game);
    update_hero(all, event);
    npc = is_in_front_of_npc(all->game);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyE &&
        npc == true) {
        all->game->state = 1;
    }
}

void update_hero(all_t *all, sfEvent event)
{
    if (check_coll(all->game, event) == POKEDEX)
        teleport_to_pokedex(all->game);
    if (check_coll(all->game, event) == MART)
        teleport_to_mart(all->game);
    if (check_coll(all->game, event) == PREVIOUS)
        teleport_to_previous_pos(all->game);
    if (check_coll(all->game, event) == HOUSE)
        teleport_to_house(all->game);
    if (check_coll(all->game, event) == GREEN_HOUSE)
        teleport_to_green_house(all->game);
    if (check_coll(all->game, event) == OUTSIDE || \
    check_coll(all->game, event) == BUSH)
        move_player(all, event);
    if (check_coll(all->game, event) == BUSH) {
        if (rand() % 1 == 0) {
            all->scene = FIGHT;
            all->fight->state = INTRO;
        }
    }
}

int check_coll(game_t *game, sfEvent event)
{
    int x = game->hero_pos_text.x;
    int y = game->hero_pos_text.y;

    if (event.key.code == sfKeyLeft)
        x -= 9;
    if (event.key.code == sfKeyRight)
        x += 3;
    if (event.key.code == sfKeyUp)
        y -= 3;
    if (event.key.code == sfKeyDown)
        y += 6;
    return (check_emplacement(game->map[y][x]));
}

int check_emplacement(char emplacement)
{
    if (emplacement == '1')
        return (OUTSIDE);
    if (emplacement == '2')
        return (POKEDEX);
    if (emplacement == '3')
        return (MART);
    if (emplacement == '4')
        return (BUSH);
    if (emplacement == '5')
        return (PREVIOUS);
    if (emplacement == '6')
        return (HOUSE);
    if (emplacement == '7')
        return (GREEN_HOUSE);
    return (-1);
}

void move_player(all_t *all, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyUp)
        move_up(all, 9);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyDown)
        move_down(all, 9);
    if ((event.type == sfEvtKeyPressed && event.key.code == sfKeyLeft))
        move_left(all, 9);
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyRight)
        move_right(all, 9);
}


