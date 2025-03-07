

#include "minitalkbonus.h"
#include <unistd.h>
#include <stdlib.h>
void handler(int signum)
{
	if(signum == SIGUSR2)
		
        {
            write(1, "message iletildi\n", 17);
            exit(0);    
        }
    
}
void send_character(char c, int pid)
{
	int shift;
	
	shift = 8;
	while(shift-- > 0 )
	{
		if ((c >> shift) & 1)
			kill(pid,SIGUSR1);
		else
			kill(pid,SIGUSR2);
            
		usleep(5000);
        
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
		while(argv[2][++i])
			send_character(argv[2][i],pid);
		send_character('\0',pid);
	}
	else
		write(1,"invalide argument!!\n",20);
    //while(1)
      //  pause();
    usleep(5000);
}
