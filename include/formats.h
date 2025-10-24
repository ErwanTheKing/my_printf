/*
** EPITECH PROJECT, 2025
** printf_project
** File description:
** formats
*/

#ifndef FORMAT_H
    #define FORMAT_H
typedef struct  formats_s {
    long flag1;
    long flag2;
    long flag3;
    long flag4;
    long flag5;
    long length;
    int width;
    int point;
    int precision;
    char specifier;
    char trigger;
} formats_t;
#endif
