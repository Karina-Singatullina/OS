#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>

int main() {
    int chars = 20;
    char arr[chars];
    FILE *file_random = fopen("/dev/random", "r");
    FILE *file_write = fopen("ex1.txt", "w");
    fread(&arr, 1, chars, file_random);
    fwrite(&arr, chars*sizeof(char), 1, file_write);
    return 0;
}