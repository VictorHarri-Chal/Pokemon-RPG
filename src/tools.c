/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** tools.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

sfVector2f init_vector(float width, float height)
{
    sfVector2f vector;

    vector.x = width;
    vector.y = height;
    return (vector);
}

char *my_strcpy(char *dest, char *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

char *my_strcat(char *dest, char const *src)
{
    int i = 0;
    int u = 0;
    while (dest[i] != '\0')
        i++;
    while (src[u] != '\0'){
        dest[i] = src[u];
        u++;
        i++;
    }
    dest[i] = '\0';
    return (dest);
}
