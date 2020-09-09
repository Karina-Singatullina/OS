#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char inp[100] = {0};
    while (strcmp(inp, "exit"))
    {
        scanf("%s", inp);
        system(inp);
    }
}