

#include "minitalkbonus.h"
#include <stdlib.h>
void handler(int signum)
{
	if(signum == SIGUSR2)
		
        {
            write(1, "mesaj iletildi\n", 14);
            exit(0);    
        }
    
}
void send_character(char c, int pid)
{
	int i;
	
	i = 8;
	while(i-- > 0 )
	{
		if ((c >> i) & 1)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
            
		usleep(700);
        
	}
}
int main(int argc, char **argv)
{
	int i;
	int pid;

	i = -1;
	signal(SIGUSR2, &handler);
    signal(SIGUSR1, &handler);
	if(argc == 3)
	{
       
        
		pid = ft_atoi(argv[1]);
		if(pid > 0)
		{
		while(argv[2][++i])
			send_character(argv[2][i],pid);
		send_character('\0',pid);
		}
		else
			write(1,"gecersiz pid",12);
		
	}
	else
		write(1,"./client_bonus [server_bonus pid] [mesaj]",41);
}
