/*
** EPITECH PROJECT, 2021
** tools2.c
** File description:
** tools2
*/

#include "my.h"
#include "my_rpg.h"
#include "my_struct.h"

char **my_str_to_wordtab_pokedex(char *str, char prefixe)
{
    int row = get_row(str, prefixe);
    int colums = 0;
    int col = 0;
    int row_start = 0;
    int i = 0;
    char **tmp = malloc(sizeof(char *) * (row + 1));
    for (row_start = 0; row_start < row; row_start++) {
        colums = get_size_wordtab(str, row_start, prefixe);
        tmp[row_start] = malloc(sizeof(char) * (colums + 1));
        for (col = 0; col < colums; col++) {
            tmp[row_start][col] = str[i];
            i++;
        }
        tmp[row_start][col] = '\0';
        i++;
    }
    return (tmp);
}

int get_size_wordtab(char *str, int actual, char prefixe)
{
    int tmp = 0;
    int i = 0;
    int res = 0;
    while (tmp != actual) {
        if (str[i] == prefixe)
            tmp++;
        i++;
    }
    while (str[i] != prefixe && str[i] != '\0' && str[i] != '\n'){
        i++;
        res++;
    }
    return (res);
}

int get_row(char *str, char prefixe)
{
    int res = 0;
    int i = 0;
    for (i = 0; str[i] != '\0'; i++)
        if (str[i] == prefixe)
            res++;
    return (res + 1);
}

int my_getnbr(char const *str)
{
    int a = 0;
    int b = 0;
    int value = 0;

    while (str[a] < '0' || str[a] > '9') {
        if (str[a] == '-')
            b++;
        a++;
    }
    while (str[a] >= '0' && str[a] <= '9') {
        value = value * 10 + (str[a] - 48);
        a++;
    }
    if (b % 2 == 0)
        return (value);
    else
        return (-value);
}

char *my_itoa(int nb_score)
{
    int len_score;
    char *str;
    int tmp;
    tmp = nb_score;
    len_score = 0;
    while (tmp > 0) {
        tmp /= 10;
        len_score++;
    }
    str = malloc(sizeof(*str) * (len_score + 1));
    str[len_score] = '\0';
    while (len_score--) {
        str[len_score] = nb_score % 10  + '0';
        nb_score = nb_score / 10;
    }
    return (str);
}