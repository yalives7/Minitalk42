void send_character(char c , int pid)
{
    int shift;
    shift = 8;
    while(shift -- > 0)
    {
        if((c >> shift) & 1)
            kill(pid,SIGUSR1);
        else
            kill(pid,SIGUSR2);

        usleep(810);
    }

    int main(int argc , char **argv)
    {
        int i;
        int pid ;

        i = -1;
        if(argc == 3)
        {
            pid = ft_atoi(argv[1]);
            while(argv[2][++i])
            {
                send_character(argv[2][i],pid);
            }
        }
        //else
        istersen geçersiz arguman fln yazdırabilirsin
        
    }
}