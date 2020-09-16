#include <pthread.h>
#include <stdio.h>

void* thread_says(int number){
    printf("Tread %d wishes u a good day\n", number);
}

int main()
{
    int N = 13;
    pthread_t thread;
    for (int i = 0; i < N; i++){
        printf("Thread %d is created\n", i);
        pthread_create(&thread, NULL, &thread_says, i);
        pthread_join(thread, NULL);
    }
}