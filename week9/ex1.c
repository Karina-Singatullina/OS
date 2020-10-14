#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <zconf.h>

int *address;
int *state;

int Aging(int frames, int a_vrt) {

    for (int i = 0; i < frames; i++) {
        if (state[i] != INT_MAX)
            state[i]++;
        if (a_vrt == address[i])
            state[i] = 0;
    }

    int prev_age = 0;
    int prev_ind = 0;

    for (int i = 0; i < frames; i++) {
        if (state[i] > prev_age)
        {
            prev_ind = i;
            prev_age = state[i];
        }
    }
    
    state[prev_ind] = 0;
    address[prev_ind] = a_vrt;
    
    return 1;
}

void Prepare()
{
    int numb_frames;
    FILE *file;
    scanf("%d", &numb_frames);

    address = malloc(sizeof(int) * numb_frames);
    state = malloc(sizeof(int) * numb_frames);

    for (int i = 0; i < numb_frames; i++) {
        address[i] = -1;
        state[i] = INT_MAX;
    }

    file = fopen("Lab09input.txt", "r");

    int seq[1000];

    int i = 0;
    int hit = 0;
    int miss = 0;

    while (fscanf(file, "%i", &(seq[i])) != EOF)
    {
        if (Aging(numb_frames, seq[i]) == 0)
            hit++;
        else
            miss++;
        i++;
    }

    fclose(file);

    printf("Hit: %d\numb_frames", hit);
    printf("Miss: %d\numb_frames", miss);
}

int main() {
    Prepare();
    return 0;
}