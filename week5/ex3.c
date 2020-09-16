#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>

int max = 10;
int content = 0;
int producerSleeps = 0;
int consumerSleeps = 1;
pthread_t producer;
pthread_t consumer;

void produce(int *buffer){
    while (1){
        if (producerSleeps == 0){
            buffer[content] = 1;
            content++;
            printf("Produced, buffer: %d\n", content);
        }
        else {
            printf("Producer sleeps\n");
        }

        if (max < content) {
            producerSleeps = 1;
        } else {
            producerSleeps = 0;
        }

        if (content <= 0) {
            consumerSleeps = 1;
        } else {
            consumerSleeps = 0;
        }

        sleep(1);
    }
}

void consume(int *buffer){
    while (1){
        if (consumerSleeps == 0){
            content--;
            buffer[content] = 0;
            printf("Consumed, buffer: %d\n", content);
        }
        else {
            printf("Consumer sleeps\n");
        }

        if (max < content) {
            producerSleeps = 1;
        } else {
            producerSleeps = 0;
        }

        if (content <= 0) {
            consumerSleeps = 1;
        } else {
            consumerSleeps = 0;
        }

        sleep(2);
    }
}

int main(){
    int *buffer = malloc(max);
    pthread_create(&producer, NULL, produce, buffer);
    pthread_create(&consumer, NULL, consume, buffer);
    pthread_join(producer, NULL);
}
