#ifndef MINITALKBONUS_H
#define MINITALKBONUS_H
#include <signal.h>
#include <unistd.h>
typedef struct s_data
{
    int bit;
    int c;
} t_data;

int ft_atoi(char *str);
void ft_putnbr(int nbr);
void ft_putstr(char *str);

#endif