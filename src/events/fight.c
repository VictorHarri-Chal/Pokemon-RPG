/*
** EPITECH PROJECT, 2021
** fight.c
** File description:
** fight
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

sfText *init_text_fight(sfText *texte, char *text, sfColor color)
{
    texte = sfText_create();
    sfFont *font = \
    sfFont_createFromFile("assets/dialogue/pokemon_pixel_font.ttf");
    sfText_setFont(texte, font);
    sfText_setColor(texte, color);
    sfText_setPosition(texte, (sfVector2f) { 50, 550 });
    sfText_setCharacterSize(texte, 50);
    sfText_setString(texte, text);
    return (texte);
}

char *init_intro_fight(char *start, char *pokemon, char *end)
{
    int size = (my_strlen(start) + my_strlen(pokemon) + my_strlen(end) + 1);
    char *tmp = malloc(sizeof(char) * (size + 1));
    tmp = my_strcpy(tmp, start);
    tmp = my_strcat(tmp, pokemon);
    tmp = my_strcat(tmp, end);
    tmp[size] = '\0';
    return (tmp);
}

void set_wait(all_t *all)
{
    char *tmp = 0;
    tmp = init_intro_fight("What will\n", all->current_poke[0]->name, " do?");
    all->fight->wait = init_text_fight(all->fight->wait, tmp, sfWhite);
}

void set_intro(all_t *all)
{
    char *tmp = 0;
    tmp = init_intro_fight("Wild ", all->current_poke[1]->name, " appeared!");
    all->fight->text = init_text_fight(all->fight->text, tmp, sfWhite);
}

void destroy_wild(pokemon_t *destroy)
{
    sfSprite_destroy(destroy->sp_back);
    sfSprite_destroy(destroy->sp_front);
    free(destroy);
    destroy = NULL;
}