#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include "sys/mman.h"
#include <sys/stat.h>
int file;
int main() {
    file = open("./ex1.txt", O_RDWR);
    struct stat* file_stat = malloc(sizeof(struct stat));
    fstat(file, file_stat);
    ftruncate(file, sizeof(char) * 19); 
    void* mmmap = mmap(NULL, file_stat->st_size, PROT_READ | PROT_WRITE, MAP_SHARED, file, 0);
    memcpy(mmmap, "This is a nice day", 19);
    return 0;
}