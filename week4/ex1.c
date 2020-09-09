#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

//Strings with "child" and "parent" (together) are displayed mixed because multiple cores execute the processes at the same time.
int main(){
    int n = 10;
    if (fork()){
        int pid = getpid();
        printf("Hello from parent [%d-%d]\n", pid, n);
    } else {
        int pid = getpid();
        printf("Hello from child [%d-%d]\n", pid, n);
    }
    return 0;
}
