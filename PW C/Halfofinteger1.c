#include <stdio.h>
int main ()
{
    float x;
    printf ("Enter The value Of X : ");
    scanf ("%f",&x);
    int y=x;
    float z = x-y;
    printf ("Answer : ");
    printf ("%f",z);
    return 0;
}