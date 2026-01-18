#include<stdio.h>
int main ()
{
    int n,i,j;
    char ch;
    printf ("Enter How Many Lines : ");
    scanf ("%d",&n);
    for (i=1;i<=n;i++)
    {
        ch='a';
        for (j=1;j<=i;j++)
        {
            printf ("%c",ch);
            ch++;
        }
        printf(" \n");
    
    }
    return 0;
}