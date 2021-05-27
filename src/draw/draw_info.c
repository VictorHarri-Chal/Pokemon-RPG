/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** draw_info
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void draw_info_pokemon(all_t *all)
{
    sfRenderWindow_drawRectangleShape(all->basics->window, \
    all->fight->hp_player, NULL);
    sfRenderWindow_drawSprite(all->basics->window, \
    all->fight->sp_info_player, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_level_player, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_name_player, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_hp_actual, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_hp_max, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_slash, NULL);
    sfRenderWindow_drawRectangleShape(all->basics->window, \
    all->fight->xp_player, NULL);
}

void draw_info_ennemie(all_t *all)
{
    sfRenderWindow_drawRectangleShape(all->basics->window, \
    all->fight->hp_ennemi, NULL);
    sfRenderWindow_drawSprite(all->basics->window, \
    all->fight->sp_info_enemie, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_level_enemie, NULL);
    sfRenderWindow_drawText(all->basics->window, \
    all->fight->texte_name_enemie, NULL);
}

void draw_info_poke(all_t *all)
{
    if (all->fight->state != MAIN && all->fight->state != END_FIGHT && \
    all->fight->state != OUTRO && all->fight->state != OUTRO_WAIT) {
        draw_info_pokemon(all);
        draw_info_ennemie(all);
    }
}
