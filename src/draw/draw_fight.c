/*
** EPITECH PROJECT, 2021
** draw_fight.c
** File description:
** draw_fight
*/

#include "my_rpg.h"
#include "my_struct.h"

void draw_sprite_poke(all_t *all)
{
    if (all->current_poke[all->nb_poke]->sp_front != NULL){
        sfRenderWindow_drawSprite(all->basics->window, \
        all->current_poke[0]->sp_back, NULL);
        sfRenderWindow_drawSprite(all->basics->window, \
        all->fight->sp_bg_box, NULL);
        sfRenderWindow_drawSprite(all->basics->window, \
        all->current_poke[1]->sp_front, NULL);
    }
}

void draw_attack_text(all_t *all)
{
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_atk1, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_atk2, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_atk3, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_atk4, NULL);
}

void draw_attack_poke(all_t *all)
{
    if (all->fight->state == ATACK){
        sfRenderWindow_drawSprite(all->basics->window, \
        all->fight->sp_playable_box, NULL);
        draw_attack_text(all);
        sfRenderWindow_drawText(all->basics->window, \
        all->fight->texte_ppmax, NULL);
        sfRenderWindow_drawText(all->basics->window, \
        all->fight->texte_ppactual, NULL);
        sfRenderWindow_drawText(all->basics->window, \
        all->fight->texte_type, NULL);
        if (all->fight->pos_arrow.x == 30 || all->fight->pos_arrow.x == 360) {
            sfRenderWindow_drawSprite(all->basics->window, \
            all->fight->sp_arrow_box, NULL);
        }
    }
}

void info_state(all_t *all)
{
    if (all->fight->state == MAIN)
        sfRenderWindow_drawText(all->basics->window, all->fight->text, NULL);
    if (all->fight->state == MAIN_WAIT){
        sfRenderWindow_drawSprite(all->basics->window, \
        all->fight->sp_playable_box, NULL);
        sfRenderWindow_drawSprite(all->basics->window, \
        all->fight->sp_arrow_box, NULL);
        sfRenderWindow_drawText(all->basics->window, all->fight->wait, NULL);
    }
}

void draw_fight(all_t *all)
{
    sfRenderWindow_clear(all->basics->window, sfTransparent);
    sfRenderWindow_drawSprite(all->basics->window, \
    all->fight->sp_bg_fight, NULL);
    draw_sprite_poke(all);
    draw_info_poke(all);
    info_state(all);
    draw_attack_poke(all);
    if (all->fight->state == OUTRO)
        sfRenderWindow_drawText(all->basics->window, all->fight->wait, NULL);
    sfRenderWindow_display(all->basics->window);
    if (all->fight->state == MAIN)
        sleep(3);
    if (all->fight->state == OUTRO_WAIT) {
        all->fight->state = OUTRO;
        sleep(3);
    }
}