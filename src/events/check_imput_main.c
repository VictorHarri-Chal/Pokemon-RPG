/*
** EPITECH PROJECT, 2021
** check_imput_main.c
** File description:
** check_imput_main
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void print_end_fight(all_t *all)
{
    char *tmp = 0;
    sfVector2f size = sfRectangleShape_getSize(all->fight->hp_ennemi);
    size.x = 200;
    tmp = init_intro_fight("Wild ", all->current_poke[1]->name, " fainted!");
    all->fight->wait = init_text_fight(all->fight->wait, tmp, sfWhite);
    sfRectangleShape_setSize(all->fight->hp_ennemi, size);
    sfRectangleShape_setFillColor(all->fight->hp_ennemi, sfGreen);
    all->current_poke[all->nb_poke]->hp_actual = \
    all->current_poke[all->nb_poke]->stat[HP];
    calc_xp(all);
}

void print_end_fight_player(all_t *all)
{
    sfVector2f size = sfRectangleShape_getSize(all->fight->hp_ennemi);
    size.x = 200;
    all->fight->wait = \
    init_text_fight(all->fight->wait, "You lose bro...", sfWhite);
    sfRectangleShape_setSize(all->fight->hp_player, size);
    sfRectangleShape_setFillColor(all->fight->hp_player, sfGreen);
    all->current_poke[0]->hp_actual = all->current_poke[0]->stat[HP];
    all->current_poke[1]->hp_actual = all->current_poke[1]->stat[HP];
    sfText_setString(all->fight->texte_hp_actual, \
    my_itoa(all->current_poke[0]->hp_actual));
    sfRectangleShape_setSize(all->fight->hp_ennemi, size);
    sfRectangleShape_setFillColor(all->fight->hp_ennemi, sfGreen);
    all->game->hero_pos_text.x = 2400;
    all->game->hero_pos_text.y = 190;
    all->game->map_pos.x = -6620;
    all->game->map_pos.y = -155;
    all->game->old_hero_pos_text.x = 2138;
    all->game->old_hero_pos_text.y = 2643;
    all->game->old_map_pos.x = -5835;
    all->game->old_map_pos.y = -7520;
}

void check_arrow_attack(all_t *all, sfEvent event)
{
    if ((all->fight->pos_arrow.x) == 580 && (all->fight->pos_arrow.y) == 550){
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA){
            all->fight->pos_arrow.x = 30;
            all->fight->pos_arrow.y = 550;
            all->fight->state = ATACK;
            return;
        }
    }
}

void check_imput_main(all_t *all, sfEvent event)
{
    check_arrow_attack(all, event);
    if (all->current_poke[all->nb_poke]->hp_actual <= 0 && \
    all->fight->state != OUTRO && all->fight->state != OUTRO_WAIT) {
        print_end_fight(all);
        all->fight->state = OUTRO_WAIT;
    }
    if (all->current_poke[0]->hp_actual <= 0 && \
    all->fight->state != OUTRO && all->fight->state != OUTRO_WAIT) {
        print_end_fight_player(all);
        all->fight->state = OUTRO_WAIT;
    }
    if ((all->fight->pos_arrow.x - 255) == 580 && \
    (all->fight->pos_arrow.y - 80) == 550){
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA){
            all->fight->state = ESCAPE;
            return;
        }
    }
    check_imput_main2(all, event);
}

void check_imput_main2(all_t *all, sfEvent event)
{
    if ((all->fight->pos_arrow.x) == 580 && \
    (all->fight->pos_arrow.y - 80) == 550){
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA){
            all->fight->state = POKEMON;
            return;
        }
    }
    if ((all->fight->pos_arrow.x - 255) == 580 && \
    (all->fight->pos_arrow.y) == 550){
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyA){
            all->fight->state = BAG;
            return;
        }
    }

}