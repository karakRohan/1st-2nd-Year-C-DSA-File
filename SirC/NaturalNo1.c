#include<stdio.h>
int main () 
{
    int n,i=1,sum=0;
    printf ("Enter Limit : ");
    scanf ("%d",&n);
    while (i<=n)
    {
        sum=sum+i;
        i++;
    }
    printf("summetion=%d",sum);
    // printf ("Rohan");
    return 0;
}