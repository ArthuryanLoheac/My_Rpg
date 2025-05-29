/*
** EPITECH PROJECT, 2024
** init_txt_stats
** File description:
** init_txt_stats
*/

#include "my.h"

static char *check_techs(enum class_e class, char *str, char *str_2)
{
    if (class == TECH) {
        str_2 = malloc(sizeof(char) * (my_strlen(str) +
            my_strlen("\t\t-- TECH --\n\n") + 1));
        strcpy(str_2, "\t\t-- TECH --\n\n");
        strcat(str_2, str);
    }
    if (class == MED) {
        str_2 = malloc(sizeof(char) * (my_strlen(str) +
            my_strlen("\t-- MEDTECH --\n\n") + 2));
        strcpy(str_2, "\t-- MEDTECH --\n\n");
        strcat(str_2, str);
    }
    return str_2;
}

static void init_class_txt(sfText *txt, enum class_e class, char *str)
{
    char *str_2 = NULL;

    if (class == SOLO) {
        str_2 = malloc(sizeof(char) * (my_strlen(str) +
            my_strlen("\t\t-- SOLO --\n\n") + 1));
        strcpy(str_2, "\t\t-- SOLO --\n\n");
        strcat(str_2, str);
    }
    str_2 = check_techs(class, str, str_2);
    if (class == NO_CLASS) {
        str_2 = malloc(sizeof(char) * (my_strlen(str) +
            my_strlen("\t-- NO CLASS --\n\n") + 1));
        strcpy(str_2, "\t-- NO CLASS --\n\n");
        strcat(str_2, str);
    }
    sfText_setString(txt, str_2);
}

void init_txt_stats(sfText *txt, stats_t *stats, enum class_e class)
{
    char str[200];

    sprintf(str, "Dex : \t%d\tTech : \t%d\n\nMov : \t%d\tBody : "
    "\t%d\n\nRef : \t%d\tWill : \t%d\n\nEmp : \t%d\tLuck : \t%d\n\n"
    "Hum : \t%d",
    stats->DEX, stats->TECH, stats->MOVE, stats->BODY, stats->REF,
    stats->WILL, stats->EMP, stats->LUCK, stats->HUM);
    init_class_txt(txt, class, str);
}
