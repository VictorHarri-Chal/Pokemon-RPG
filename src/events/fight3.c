/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** fight3.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void state_attack(all_t *all, sfEvent event)
{
    check_if_attack(all, event);
    arrow_attack_box(all, event);
    sfSprite_setTextureRect(all->fight->sp_playable_box, \
    (sfIntRect) { 298, 5, 239, 47 });
    sfSprite_setPosition(all->fight->sp_playable_box, (sfVector2f) { 0, 500 });
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB)
        all->fight->state = MAIN;
}

void state_main(all_t *all)
{
    set_playable_box(all->fight);
    set_arrow_box(all->fight);
    all->fight->state = MAIN_WAIT;
}

void move_arrow(all_t *all, sfEvent event)
{
    if (all->fight->pos_arrow.x != 580 && all->fight->pos_arrow.x != 835) {
        all->fight->pos_arrow.x = 580;
        all->fight->pos_arrow.y = 550;
    }
    pos_left_right_arrow(all, event);
    pos_up_down_arrow(all, event);
}

void state_intro(all_t *all)
{
    set_intro(all);
    set_wait(all);
    all->fight->state = MAIN;
}

void fight_event(all_t *all, sfEvent event)
{
    check_imput_main(all, event);
    state_end_fight(all);
    if (all->fight->state == INTRO) {
        state_intro(all);
    }
    else if (all->fight->state == ESCAPE || all->fight->state == OUTRO)
        all->fight->state = END_FIGHT;
    else if (all->fight->state == ATACK)
        state_attack(all, event);
    else if (all->fight->state == MAIN)
        state_main(all);
    else if (all->fight->state == MAIN_WAIT)
        move_arrow(all, event);
    else if (all->fight->state == BAG){
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB)
            all->fight->state = MAIN;
    }
    else if (all->fight->state == POKEMON){
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyB)
            all->fight->state = MAIN;
    }
    if_mewtwo_endfight(all);
}