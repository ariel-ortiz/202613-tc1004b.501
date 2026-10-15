#include <stdio.h>
#include <unistd.h>
#include <signal.h>

#define FOREVER while (1)

int num_elephants = 1;

void handle_sigterm(int sig)
{
    num_elephants = 1;
}

int main()
{
    struct sigaction sa_int = { .sa_handler = SIG_IGN };
    sigaction(SIGINT, &sa_int, NULL);

    struct sigaction sa_term = { .sa_handler = &handle_sigterm };
    sigaction(SIGTERM, &sa_term, NULL);

    FOREVER {
        printf("%d elefantes se columpiaban sobre la tela de una araña\n", num_elephants);
        printf("     Como veían que resistía fueron a llamar otro elefante.\n\n");
        fflush(stdout);
        num_elephants++;
        sleep(1);
    }

    return 0;
}
