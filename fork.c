#include <stdio.h>
#include <unistd.h>

int main(){
    int a=5;
    int pid = fork();
    if (pid==0) {
        a = 10;
        printf("Soy el proceso hijo; variable a = %d\n",a);
        sleep(5);
        return 0;
    }
    
    printf("Soy el proceso padre; variable a = %d\n",a);
    sleep(5);
    return 0;
}