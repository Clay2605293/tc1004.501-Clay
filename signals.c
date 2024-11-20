#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

volatile sig_atomic_t stop = 0;  // Variable para controlar el ciclo

void no_me_matas(int signum) {
    printf("Recibi la señal %d\n", signum);
    printf("No me puedes matar\n");
}

void me_matas(int signum) {
    printf("Recibi la señal %d\n", signum);
    printf("Me mataron\n");
    stop = 1;  // Cambia el valor para detener el ciclo
}

int main() {
    signal(2, no_me_matas);  // Signal 2 (SIGINT)
    signal(10, me_matas);    // Signal 10 (SIGUSR1)

    while (stop==0) {  // Revisa la variable `stop` en cada iteración
        printf("Trabajando...\n");
        sleep(1);
    }

    printf("Fin del programa.\n");
    return 0;
}
