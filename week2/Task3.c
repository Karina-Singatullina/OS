#include <stdio.h>

void triangle(int n) {
    int rows = 1;
    while (rows <= n) {
        for (int i = 0; i < n - rows; i++)
            printf(" ");
        for (int i = 0; i < rows * 2 - 1; i++)
            printf("*");
        rows++;
        printf("\n");
    }
}

int main(int argc, char *argv[]) {

    int n;
    sscanf(argv[1], "%d", &n);
    triangle(n);

    return 0;
}