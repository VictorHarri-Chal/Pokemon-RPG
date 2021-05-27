/*
** EPITECH PROJECT, 2020
** B-MUL-200-NAN-2-1-myrpg-simon.le-fourn
** File description:
** init_map.c
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

char *load_file_in_mem(char const *filepath)
{
    int fd = open(filepath, O_RDONLY);
    int filesize;
    struct stat file_stat;
    char *buffer;

    stat(filepath, &file_stat);
    filesize = file_stat.st_size;
    if (filesize == 0)
        return (NULL);
    if (!(buffer = malloc(sizeof(char) * filesize + 1)))
        return (NULL);
    buffer[filesize] = '\0';
    read(fd, buffer, filesize);
    close(fd);
    return (buffer);
}

int count_lines(char *str)
{
    int i = 0;
    int row = 0;

    while (str[i] != '\0') {
        if (str[i] == '\n') {
            row++;
        }
        i++;
    }
    row++;
    return (row);
}

void my_str_to_wordtab(game_t *game, char *str)
{
    int reel_row = count_lines(str);
    int row = 0;
    int col = 0;
    int i = 0;
    int columns = 0;

    game->map = malloc(sizeof(char *) * (reel_row) + 1);
    for (row = 0; row < reel_row; row++)
    {
        columns = cols(str, i);
        game->map[row] = malloc(sizeof(char) * columns + 1);
        for (col = 0; col < columns; col += 1) {
            game->map[row][col] = str[i];
            i++;
        }
        i++;
    }
}

int cols(char *str, int i)
{
    int j = 0;

    while (str[i] != '\n' && str[i] != '\0') {
        i++;
        j++;
    }
    return (j);
}