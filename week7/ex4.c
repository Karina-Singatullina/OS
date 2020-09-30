#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void* own_realloc(int size, void *ptr) {

    if (size == 0)
    {
        free(ptr);
        return NULL;
    }

    if (ptr == NULL)
        return malloc(size);

    void* temp_ptr = ptr;
    ptr = malloc(size * sizeof(void*));
    memcpy(ptr, temp_ptr, size);

    return ptr;
}

int main(){
    int n = 5;
    int* ptr = calloc(n, sizeof(int));

    for (int i = 0; i < n; i++)
    {
        ptr[i] = i;
        printf("%d ", ptr[i]);
    }

    own_realloc(7, ptr);
    printf("\n");
    for (int i = 0; i < 7; i++)
        printf("%d ", ptr[i]);

    return 0;
}