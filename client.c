#include "minitalk.h"
void send_character(char c , int pid)
{
    int i;
    i = 8;
    while(i -- > 0)
    {
        if((c >> i) & 1)
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);

        usleep(810);
    }
}
    int main(int argc , char **argv)
    {
        int i;
        int pid ;

        i = -1;
        if(argc == 3)
        {
            pid = ft_atoi(argv[1]);

            if(pid > 0)
            {
                while(argv[2][++i])
                {
                    send_character(argv[2][i],pid);
                }
            }
            else
                write(1,"gecersiz pid",12);
           
        }
        else
            write(1,"./client [server_pid] [mesaj]",29);
        
    }
