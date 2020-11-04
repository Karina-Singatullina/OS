#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#define TRUE 1
#define FALSE 0
int size = 12000;
int file;


int main(int argc, char *argv[]) {
    char buffer[size];
    char one_char[1];
    int output_size = 0;
    int a = FALSE;
    while (read(STDIN_FILENO, one_char, 1) > 0){
        buffer[output_size] = one_char[0];
        output_size++;
        if (output_size == size){
           break;
        }
    }
    write(STDOUT_FILENO, &buffer, output_size);
    
    for (int i = 0; i < argc; ++i) {
        if (strcmp(argv[i], "-a") == 0){
            a = TRUE;
            continue;
        }
        if (a == TRUE){
            file = open(argv[i], O_WRONLY | O_APPEND);
            write(file, &buffer, output_size);
            a = FALSE;
            close(file);
        }
        else {
            file = open(argv[i], O_WRONLY);
            write(file, &buffer, output_size);
            close(file);
        }
    }
    return 0;
}

