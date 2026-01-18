#include<stdio.h>
int main ()
{
    int i,n,fact=1;
    printf ("Enter A Number : ");
    scanf ("%d",&n);
    for(i=n;i>=1;i--)
    {
        fact = fact*i;
    }
    printf ("Factorial = %d",fact);
    return 0 ;
}