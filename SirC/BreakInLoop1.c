#include<stdio.h>
int main ()
{
    int i;
    for (i=1
    ;i<=5;i++)
    {
        if (i==3)
        break;printf ("\n%d",i);
    }
    printf ("\nA");
    return 0;
}