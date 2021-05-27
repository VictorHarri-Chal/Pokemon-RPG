/*
** EPITECH PROJECT, 2021
** init_pokemon_index.c
** File description:
** init_pokedex_index
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

char *read_index(char *filepath)
{
    int fd = open(filepath, O_RDONLY);
    char *buffer;
    struct stat buff;
    stat(filepath, &buff);
    buffer = malloc(sizeof(char) * buff.st_size + 1);
    read(fd, buffer, buff.st_size);
    buffer[buff.st_size] = '\0';
    close(fd);
    return (buffer);
}

char *find_line(char *buffer, int i)
{
    int len = get_size(buffer, i);
    int j = 0;
    char *tmp = malloc(sizeof(char) * (len + 2));
    while (j <= len){
        tmp[j] = buffer[i];
        i++;
        j++;
    }
    tmp[j] = '\0';
    return (tmp);
}

int get_size(char *buffer, int i)
{
    int len = 0;
    while (buffer[i] != '\n' && buffer[i] != '\0'){
        i++;
        len++;
    }
    return (len);
}

sfSprite *create_pokesprite(sfSprite *sprite, char *text, int pos)
{
    sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(text, NULL);
    sfSprite_setTexture(sprite, texture, sfTrue);
    if (pos == 1){
        sfSprite_setTextureRect(sprite, (sfIntRect) {0, 0, 96, 96});
        sfSprite_setPosition(sprite, (sfVector2f) { 600, 15 });
    }
    else
        sfSprite_setPosition(sprite, (sfVector2f) { 150, 300 });
    sfSprite_setScale(sprite, (sfVector2f) { 4, 4 });
    return (sprite);
}

attack_t *cpy_attack(attack_t *src, attack_t *dest)
{
    dest->name = malloc(sizeof(char) * (my_strlen(src->name) + 1));
    dest->name = my_strcpy(dest->name, src->name);
    dest->pp_max = src->pp_max;
    dest->pp_actual = dest->pp_max;
    dest->stat = malloc(sizeof(int) * 3);
    dest->stat[HP] = src->stat[HP];
    dest->stat[ATK] = src->stat[ATK];
    dest->stat[SPEED] = src->stat[SPEED];
    dest->type = src->type;
    dest->dmg = src->dmg;
    return (dest);
}