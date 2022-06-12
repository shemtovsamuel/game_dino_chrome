/*
** EPITECH PROJECT, 2020
** my_hunter
** File description:
** lib.c
*/

#include "../include/my_runner.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int a = 0; str[a] != '\0'; a++)
        my_putchar(str[a]);
    return (0);
}

static int m_gestion(long number)
{
    int tmp = 0;

    if (number >= 10) {
        tmp = number % 10;
        number = (number - tmp) / 10;
        m_gestion(number);
        my_putchar(tmp + '0');
    } else if (number < 10)
        my_putchar(number + '0');
    return (0);
}

int my_put_nbr(int nb)
{
    long number = nb;

    if (nb < 0) {
        my_putchar('-');
        number = number * -1;
        m_gestion(number);
    } else
        m_gestion(number);
    return (0);
}

char *int_to_string(int num)
{
    int len = 0;
    int n = 0;
    int is_neg = 0;
    char *str = malloc(sizeof(char) * 100);

    if (num < 0) {
        num *= -1;
        is_neg = 1;
        str[0] = '-';
    }
    n = num;
    while (n != 0) {
        len++;
        n /= 10;
    }
    for (int i = 0; i < len; i++) {
        str[len - (i + 1 - is_neg)] = (num % 10) + '0';
        num = num / 10;
    }
    str[len + is_neg] = '\0';
    return (str);
}