#include <unistd.h>
#include <signal.h>

t_data data = {128,0};

void reset_data(void)
{
    data.bit = 128;
    data.c=0;

}

void handler(int sig)
{
    if(sig == SIGUSR1)
    {
        data.c += data.bit;
    }
    data.bit /= 2;
    if(data.bit == 0)
    {
        write(1,&data.c,1);
        reset_data();
    }
}

int main(void)
{
     ft_putnbr(get_pid());
     signal (SIGUSR1,handler);
     signal(SIGUSR2,handler);
    while(1)
    {
        pause();
    }
    return 0;

}