/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_dialogue.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

dialogue_t *init_bg(dialogue_t *dialogue)
{
    dialogue->rect = sfRectangleShape_create();
    dialogue->size = (sfVector2f) { 200, 900 };
    dialogue->pos = (sfVector2f) { 0, 500 };
    dialogue->filepath = "assets/dialogue/dialogue_box.png";
    dialogue->sprite = sfSprite_create();
    dialogue->texture = sfTexture_createFromFile \
    (dialogue->filepath, NULL);
    sfSprite_setTexture(dialogue->sprite, dialogue->texture, sfTrue);
    sfSprite_setPosition(dialogue->sprite, dialogue->pos);
    sfRectangleShape_setPosition(dialogue->rect, dialogue->pos);
    sfRectangleShape_setSize(dialogue->rect, dialogue->size);
    sfSprite_setScale(dialogue->sprite, (sfVector2f) { 1.36, 0.9 });
    dialogue->state = 0;
    return (dialogue);
}

dialogue_t *init_text(dialogue_t *dialogue, char *text)
{
    dialogue->text = sfText_create();
    dialogue->font = \
    sfFont_createFromFile("assets/dialogue/pokemon_pixel_font.ttf");
    sfText_setFont(dialogue->text, dialogue->font);
    sfText_setColor(dialogue->text, sfBlack);
    sfText_setPosition(dialogue->text, (sfVector2f) { 50, 550 });
    sfText_setCharacterSize(dialogue->text, 50);
    sfText_setString(dialogue->text, text);
    return (dialogue);
}

dialogue_t *init_textt(dialogue_t *dialogue, char *text)
{
    dialogue->text2 = sfText_create();
    dialogue->font = \
    sfFont_createFromFile("assets/dialogue/pokemon_pixel_font.ttf");
    sfText_setFont(dialogue->text2, dialogue->font);
    sfText_setColor(dialogue->text2, sfBlack);
    sfText_setPosition(dialogue->text2, (sfVector2f) { 50, 550 });
    sfText_setCharacterSize(dialogue->text2, 50);
    sfText_setString(dialogue->text2, text);
    return (dialogue);
}

dialogue_t *init_all_dialogue(void)
{
    dialogue_t *dialogue = malloc(sizeof(*dialogue));
    dialogue = init_text(dialogue, NULL);
    dialogue = init_bg(dialogue);
    return (dialogue);
}
