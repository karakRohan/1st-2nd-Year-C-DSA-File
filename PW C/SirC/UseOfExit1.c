#include<stdio.h>
#include<stdlib.h>
int main ()
{
    int i;
    for (i=1;i<5;i++)
    {
        if (i==3)
        exit (0);
        printf ("%d",i);
    }
    printf ("A");
    return 0;
}