#include <stdlib.h>
#include <zconf.h>
#include <string.h>

int main()
{
    int times = 10;
    int mem = times * 1024 * 1024;
    for (int i = 0; i < times; i++)
    {
        int * ptr = (int*)malloc(mem);
        memset(ptr, 0, mem);
        sleep(1);
    }

    return 0;
}
