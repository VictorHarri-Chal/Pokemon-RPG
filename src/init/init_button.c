/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_button.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

button_t *init_button(int x, int y, int width, int height)
{
    button_t *button = malloc(sizeof(*button));

    if (!button)
        return (NULL);
    button->rect = sfRectangleShape_create();
    sfRectangleShape_setPosition(button->rect, init_vector(x, y));
    sfRectangleShape_setSize(button->rect, init_vector(width, height));
    return (button);
}
