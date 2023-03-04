#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void handle_sigusr1(int sig) {
    printf("Received SIGUSR1\n");
}

int main() {
	printf("Server : %d\n", getpid());
    struct sigaction sa;
    sa.sa_handler = handle_sigusr1;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = 0;
    sigaction(SIGUSR1, &sa, NULL);

    // The process will now wait for SIGUSR1 to be received
    while(1) {
        sleep(1);
    }

    return 0;
}
