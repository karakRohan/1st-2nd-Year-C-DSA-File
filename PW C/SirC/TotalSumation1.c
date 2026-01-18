#include<stdio.h>
int main ()
{
    int n,r,sum=0;
    printf ("Enter a Number : ");
    scanf ("%d",&n);
    while (n>0)
    {
        r = n%10;
        sum = sum+r;
        n = n/10;
    }
    printf ("sumsation=%d",sum);
    return 0;
}