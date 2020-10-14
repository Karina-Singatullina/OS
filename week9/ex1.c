#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <zconf.h>

int *address;
int *state;

int Aging(int a_vrt, int frames_number) {

    for (int i = 0; i < frames_number; i++) {
        if (state[i] != INT_MAX)
            state[i]++;
    }

    for (int i = 0; i < frames_number; i++) {
        if (address[i] == a_vrt)
            state[i] = 0;
    }

    int old_page_index = 0;
    int old_page_age = 0;

    for (int i = 0; i < frames_number; i++) {
        if (state[i] > old_page_age)
        {
            old_page_age = state[i];
            old_page_index = i;
        }
    }

    address[old_page_index] = a_vrt;
    state[old_page_index] = 0;
    return 1;
}

void readFile()
{
    FILE *file_input;
    int N;
    printf("%s", "Number of page frames: ");
    scanf("%d", &N);

    address = malloc(sizeof(int) * N);
    state = malloc(sizeof(int) * N);

    for (int i = 0; i < N; i++)
    {
        address[i] = -1;
        state[i] = INT_MAX;
    }

    file_input = fopen("Lab09input.txt", "r");

    int arr[1000];
    int i = 0;

    int hit = 0;
    int miss = 0;

    while (fscanf(file_input, "%i", &(arr[i])) != EOF)
    {
        if (Aging(arr[i], N) == 0)
        {
            hit++;
        }
        else {miss++;}

        i++;
    }

    fclose(file_input);

    printf("Hit: %d\n", hit);
    printf("Miss: %d\n", miss);
}

int main() {
    readFile();
    return 0;
}