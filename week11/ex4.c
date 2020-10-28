#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "sys/mman.h"
#include <sys/stat.h>
#include <stdio.h>
int file_old;
int file_new;
int main() {
    file_old = open("./ex1.txt", O_RDWR);
    struct stat* stat_old = malloc(sizeof(struct stat));
    fstat(file_old, stat_old);
    ftruncate(file_old, sizeof(char) * 19); 
    void* mmmap_old = mmap(NULL, stat_old->st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file_old, 0);
    file_new = open("./ex1.memcpy.txt", O_RDWR);

    struct stat* stat_new = malloc(sizeof(struct stat));
    fstat(file_new, stat_new);
    ftruncate(file_new, sizeof(char) * 19); 
    void* mmmap_new = mmap(NULL, stat_new->st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file_new, 0);
    memcpy(mmmap_new, mmmap_old, stat_old->st_size);
    return 0;
}