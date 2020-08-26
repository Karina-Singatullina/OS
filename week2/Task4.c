#include <stdio.h>

void swit4(int* var1, int* var2) {
    int temp = *var1;
    *var1 = *var2;
    *var2 = temp;
}

int main() {

    int var1, var2 = 0;

    printf("Write the first integer");
    scanf("%d", &var1);
    printf("Write the second integer");
    scanf("%d", &var2);

    swit4(&var1, &var2);

    printf("%d", var1);
    printf("\n");
    printf("%d", var2);

    return 0;
}