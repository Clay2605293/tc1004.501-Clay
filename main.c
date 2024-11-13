#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void no_me_matas(int signum) {
    printf("Recibi la señal %d\n", signum);
    printf("No me puedes matar\n");
}

void me_matas(int signum) {
    printf("Recibi la señal %d\n", signum);
    printf("Me mataron\n");
    exit(0);
}

int main() {
    signal(2, no_me_matas);
    signal(10, me_matas);

    while (1) {
        printf("Trabajando...\n");
        sleep(1);
    }

    return 0;
}
