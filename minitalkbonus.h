#ifndef MINITALKBONUS_H
#define MINITALKBONUS_H
#include <signal.h>

typedef struct s_data
{
    int bit;
    int c;
    int pid;
} t_data;

int ft_atoi(char *str);
void ft_putnbr(int nbr);
void ft_putstr(char *str);

#endif