#include <stdio.h>
#include <stdlib.h>
#include <zconf.h>
#include <string.h>
#include <sys/resource.h>

int main()
{
    int times = 10;
    int mem = times * 1024 * 1024;
    for (int i = 0; i < times; i++)
    {
        int *ptr = malloc(mem);
        memset(ptr, 0, mem);
        struct rusage rus;
        printf(rus.ru_maxrss);
        sleep(1);
    }
    return 0;
}