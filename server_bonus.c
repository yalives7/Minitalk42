#include "minitalkbonus.h"
#include <unistd.h>
#include <signal.h>
#include <stdio.h>

t_data data = {128, 0, 0};

void reset_data(void) {
    data.bit = 128;
    data.c = 0;
}

void handler(int sig, siginfo_t *info, void *ucontext) {
    (void)ucontext;
    if (data.pid != info->si_pid) {
        reset_data();
        data.pid = info->si_pid;
    }
    if (sig == SIGUSR1) {
        data.c += data.bit;
    }
    data.bit /= 2;
    if (data.bit == 0) {
        write(1, &data.c, 1);
        if (data.c == '\0') {
            kill(info->si_pid, SIGUSR2); 
        }
        reset_data();
    }
  kill(info->si_pid, SIGUSR1); 

}

int main(void) {
    struct sigaction sa;
    sa.sa_sigaction = handler;
    sa.sa_flags = SA_SIGINFO;
    ft_putnbr(getpid());
    sigemptyset(&sa.sa_mask);
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);

    while (1) {
        pause();
    }
    return 0;
}

