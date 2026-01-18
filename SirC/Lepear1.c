#include<stdio.h>
int main () 
{
    int year;
    printf ("Enter a Number") ;
    scanf ("%d",&year);
    if ((year%4==0&&year%100!=0)||(year%400==0))
    printf ("%d"" Is Lepear",year);
    else
    printf("%d""Is Not Lepear",year);
    return 0;
}