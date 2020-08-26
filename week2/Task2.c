include <stdio.h>
#include <string.h>
int main()
{
    int start, end;
    char s1[100], s2[100];

    printf("Write some string here\n");
    gets(s1);

    end = strlen(s1) - 1;

    for (start = 0; start < strlen(s1); start++) {
        s2[start] = s1[end];
        end--;
    }

    s2[start] = '\0';
    printf("%s\n", s2);

    return 0;
}