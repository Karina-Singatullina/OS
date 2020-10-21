#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <dirent.h>
#include <sys/stat.h>

struct stat *buff;
DIR *dirp;
char path[255];
char path1[255];
long nodes[255];
char names[31][255];
int count [255];

int main()
{
    int size = 0;
    buff = malloc(sizeof(struct stat) * 32);
    strcpy(path, "/home/runner/GhostwhiteSecretTags/week10/tmp/");
    dirp = opendir(path);
    struct dirent *dp;
    if(dirp == NULL){
        return -1;
    }

    //check information about every file in tmp directory and if it has more than 1 hardlink, then remember its i-node, name and hardlinks count
    while ((dp = readdir(dirp)) != NULL){
        strcpy(path1, path);
        strcat(path1, dp->d_name);
        stat(path1, buff);

        if(buff->st_nlink > 1)
        {
            nodes[size] =  buff->st_ino;
            strcpy(names[size], dp->d_name);
            count[size] = buff->st_nlink;
            size++;
        }
    }

    //for every i-node that we remembered earlier we find the corresponding remembered hardlinks count and file names
    for(int i = 0; i < size; i++){
        printf("inode %ld has %d links: ", nodes[i], count[i]);
        for(int j = 0; j < size; j++){
            if( nodes[j] == nodes[i])
                printf("%s, ", names[j]);
        }
        printf("\n");
    }

    return 0;
}