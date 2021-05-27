/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** game_event.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

sfSprite *cpy_sprite(char *text, int pos)
{
    sfSprite *current = sfSprite_create();
    sfTexture *actual = sfTexture_createFromFile(text, NULL);
    sfSprite_setTexture(current, actual, sfTrue);
    if (pos == 1){
        sfSprite_setTextureRect(current, (sfIntRect) {0, 0, 96, 96});
        sfSprite_setPosition(current, (sfVector2f) { 600, 15 });
    }
    else
        sfSprite_setPosition(current, (sfVector2f) { 150, 300 });
    sfSprite_setScale(current, (sfVector2f) { 4, 4 });
    return (current);
}

attack_t **cpy_all_attack(attack_t **arr)
{
    int j = 0;
    attack_t **all_attack = malloc(sizeof(*all_attack) * 6);
    for (int i = 0; i < 4; i++)
        all_attack[i] = malloc(sizeof(**all_attack));
    all_attack[5] = NULL;
    while (j < 4) {
        all_attack[j] = cpy_attack(arr[j], all_attack[j]);
        j++;
    }
    return (all_attack);
}

pokemon_t *init_pokemon(pokemon_t *pokemon_dest, pokemon_t *pokemon_src)
{
    pokemon_dest->rect_poke = (sfIntRect) {0, 0, 96, 96};
    pokemon_dest->name = malloc(sizeof(char) * \
    (my_strlen(pokemon_src->name) + 1));
    stat_attack_poke(pokemon_dest, pokemon_src);
    pokemon_dest->sp_front = cpy_sprite(pokemon_src->text_front, 1);
    pokemon_dest->sp_back = cpy_sprite(pokemon_src->text_back, 0);
    pokemon_dest->text_back = malloc(sizeof(char) * \
    (my_strlen(pokemon_src->text_back) + 1));
    pokemon_dest->text_back = \
    my_strcpy(pokemon_dest->text_back, pokemon_src->text_back);
    pokemon_dest->text_front = malloc(sizeof(char) * \
    (my_strlen(pokemon_src->text_front) + 1));
    pokemon_dest->text_front = \
    my_strcpy(pokemon_dest->text_front, pokemon_src->text_front);
    pokemon_dest->level = 0;
    pokemon_dest->xp = 0;
    pokemon_dest->rect_max = pokemon_src->rect_max;
    pokemon_dest->anim_poke = 0;
    pokemon_dest->all_atk = cpy_all_attack(pokemon_src->all_atk);
    return (pokemon_dest);
}

void game_event(all_t *all, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyI)
        all->scene = INVENTORY;
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
        all->scene = RESUME_MENU;
    if (all->game->state == 0)
        hero_mouv_event(all, event);
    if (all->current_poke[0] != NULL)
        interact_with_joel(all, event);
    if (all->game->state == 4)
        interact_with_mewtwo(all, event);
}

int check_coll(all_t *all, sfEvent event)
{
    int x = all->game->hero_pos_text.x;
    int y = all->game->hero_pos_text.y;

    if (event.key.code == sfKeyLeft)
        x -= 9;
    if (event.key.code == sfKeyRight)
        x += 3;
    if (event.key.code == sfKeyUp)
        y -= 3;
    if (event.key.code == sfKeyDown)
        y += 6;
    return (detect_text(all, x, y));
}

