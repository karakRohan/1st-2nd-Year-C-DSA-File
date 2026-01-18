#include<stdio.h>
int main ()
{
    int n,i,count=0;
    printf ("Enter A Number : ");
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
    {
        if (n%i==0);
        count++;
    }
    if (count==2)
    printf ("%d Is Prime",n);
    else
    printf ("%d Is Not Prime",n);
    return 0;
}