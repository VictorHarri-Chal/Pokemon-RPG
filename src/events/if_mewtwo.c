/*
** EPITECH PROJECT, 2021
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** if_mewtwo
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

void dialogue_w_mewtwo(all_t *all, sfEvent event)
{
    if (all->dialogue->state == 0){
        all->dialogue = init_text(all->dialogue, \
        "GOD :\tCongratualation! You are the new god of the earth! \
        \n\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tKEEP SAFE");
        all->dialogue->state = 4;
    }
    if (all->dialogue->state == 4) {
        if (event.type == sfEvtKeyReleased && \
        (event.key.code == sfKeyB || event.key.code == sfKeySpace)) {
            sleep(20);
            all->game->state = 0;
            all->dialogue->state = 0;
        }
    }
}

void interact_with_mewtwo(all_t *all, sfEvent event)
{
    (void) event;
    if (all->dialogue == NULL)
        all->dialogue = init_bg(all->dialogue);
    if (all->dialogue->state == 4){
        all->dialogue->state = 0;
        all->game->state = 0;
        sfClock_restart(all->basics->clock);
    }
    dialogue_w_mewtwo(all, event);
}

void if_mewtwo_endfight(all_t *all)
{
    if (all->dialogue->sprite == NULL) {
        all->dialogue = init_bg(all->dialogue);
    }
    if (all->fight->state == END_FIGHT) {
        if (((all->game->hero_pos_text.x >= 1436 && all->game->hero_pos_text.x \
        <= 1448) && (all->game->hero_pos_text.y >= 464 && \
        all->game->hero_pos_text.y <= 470)) && all->current_poke[0] != NULL) {
            all->game->state = 4;
        }
    }
}