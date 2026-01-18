#include<stdio.h>
int main ()
{
    int x=0,y=1,z,i,n;
    printf ("Enter How many Terms : ");
    scanf ("%d",&n);
    if (n==1)
    printf ("%d",x);
    else if (n==2)
    printf ("%d%d",x,y);
    else
    {
        printf ("%d%d",x,y);
        for (i=3;i<=n;i++)
        {
            z=x+y;
            printf ("%d",z);
            x=y;
            y=z; 
        }
    }
    return 0;
}