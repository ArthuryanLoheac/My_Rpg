/*
** EPITECH PROJECT, 2023
** my str to word array
** File description:
** create an array of string from a string,
** the separator are any non alphanumeric nor space character
*/
#include <stdlib.h>
#include "my.h"

static int isdelim(char const a, char *delimiter)
{
    for (int i = 0; i < my_strlen(delimiter); i++) {
        if (delimiter[i] == a)
            return 0;
    }
    return 1;
}

static int skip_inhibitor92(char *str, int i)
{
    int count = 0;

    while (i > 1 && str[i - 1] == 92) {
        count++;
        i--;
    }
    return count % 2;
}

static int update_inhibition(char *str, int i, int inhibition)
{
    if (skip_inhibitor92(str, i) == 1)
        return inhibition;
    if (str[i] == 34 && ((inhibition / 4) % 4 == 1 || inhibition == 0))
        inhibition += (inhibition / 4) % 4 == 1 ? -4 : 4;
    if (str[i] == 39 && ((inhibition / 8) % 8 == 1 || inhibition == 0))
        inhibition += (inhibition / 8) % 8 == 1 ? -8 : 8;
    if (str[i] == 40 && inhibition == 0)
        inhibition += 16;
    if (str[i] == 41)
        inhibition -= 16;
    if (str[i] == 96 && ((inhibition / 32) % 32 == 1 || inhibition == 0))
        inhibition += (inhibition / 32) % 32 == 1 ? -32 : 32;
    return inhibition;
}

static int is_inhibited(char *str, int i, int inhibition, int inhibitor)
{
    if (skip_inhibitor92(str, i) == 1)
        return 0;
    if (inhibition / 4 % 2 == 1 && inhibitor / 4 % 2 == 1)
        return 0;
    if (inhibition / 8 % 2 == 1 && inhibitor / 8 % 2 == 1)
        return 0;
    if (inhibition / 16 % 2 == 1 && inhibitor / 16 % 2 == 1)
        return 0;
    if (inhibition / 32 % 2 == 1 && inhibitor / 32 % 2 == 1)
        return 0;
    return 1;
}

static int countstr(char *str, char *delimiter, int inhibitor)
{
    int prevsep = 0;
    int count = 0;
    int inhibition = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        inhibition = update_inhibition(str, i, inhibition);
        if (is_inhibited(str, i, inhibition, inhibitor) &&
            isdelim(str[i], delimiter) == 1 && prevsep == 0)
            count++;
        if (is_inhibited(str, i, inhibition, inhibitor))
            prevsep = isdelim(str[i], delimiter);
    }
    return count;
}

static int skip_words(char *str, char *delimiter, int word_to_skip,
    int inhibitor)
{
    int p = 0;
    int z;
    int inhibition = 0;
    int prev = 0;

    for (z = 0; p <= word_to_skip; z++) {
        if (is_inhibited(str, z, inhibition, inhibitor) &&
            isdelim(str[z], delimiter) == 1 && prev == 0)
            p = p + 1;
        if (is_inhibited(str, z, inhibition, inhibitor))
            prev = isdelim(str[z], delimiter);
        inhibition = update_inhibition(str, z, inhibition);
    }
    return z - 1;
}

static char *buildarray(char *str, int i, char *delimiter, int inhibitor)
{
    int end = 0;
    int start = 0;
    char *dest;
    int inhibition = 0;

    start = skip_words(str, delimiter, i, inhibitor);
    end = start;
    inhibition = update_inhibition(str, end, inhibition);
    while (str[end] != '\0' && (isdelim(str[end], delimiter) == 1 ||
        !is_inhibited(str, end, inhibition, inhibitor))) {
        end++;
        inhibition = update_inhibition(str, end, inhibition);
    }
    dest = malloc((end - start + 1) * sizeof(char));
    for (int y = 0; y < end - start; y++) {
        dest[y] = str[y + start];
    }
    dest[end - start] = '\0';
    return dest;
}

char **my_str_to_word_array(char *str, char *delimiter, int inhibitor)
{
    char **dest;
    int len;

    if (!str)
        return NULL;
    str = my_strdup(str);
    len = countstr(str, delimiter, inhibitor);
    dest = malloc((len + 1) * sizeof(char *));
    for (int i = 0; i != len; i++) {
        dest[i] = buildarray(str, i, delimiter, inhibitor);
    }
    dest[len] = NULL;
    free(str);
    return dest;
}
