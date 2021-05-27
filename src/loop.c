/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** loop.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

int loop(all_t *all)
{
    while (sfRenderWindow_isOpen(all->basics->window)) {
        while (all->scene == MENU) {
            analyse_event(all);
            draw_menu(all);
        }
        while (all->scene == RESUME_MENU) {
            analyse_event(all);
            draw_resume_menu(all);
        }
        while (all->scene == GAME) {
            analyse_event(all);
            draw_game(all);
        }
        loop_continue(all);
    }
    destroy_all(all);
    return (0);
}

void loop_continue(all_t *all)
{
    while (all->scene == HTP) {
            analyse_event(all);
            draw_htp(all);
    }
    while (all->scene == FIGHT) {
        analyse_event(all);
        anim_poke(all);
        draw_fight(all);
    }
    while (all->scene == INVENTORY) {
        analyse_event(all);
        draw_inventory(all);
    }
    while (all->scene == INV_BAG) {
        analyse_event(all);
        draw_bag(all);
    }
}
