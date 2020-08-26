
#include <zconf.h>
#include <float.h>
#include <stdio.h>

extern int var1;
extern float var2;
extern double  var3;

int main() {

    int var1 = INT_MAX;
    float var2 = FLT_MAX;
    double var3 = DBL_MAX;

    printf("\nSize of var1: %d", sizeof(var1));
    printf("\nvar1= %d", INT_MAX);
    printf("\nSize of var2: %d", sizeof(var2));
    printf("\nvar2= %f", FLT_MAX);
    printf("\nSize of var3: %d", sizeof(var3));
    printf("\nvar3= %lf", DBL_MAX);

    return 0;
}
