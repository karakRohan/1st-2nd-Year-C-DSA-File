#include<stdio.h>
int main ()
{
    int n,i,j,k;
    printf("Enter How Many Lines : ");
    scanf("%d", &n);
    for (i = 1; i <= n; i++)//Line
    {
        for (j = 1; j <= n - i; j++)//gap
     {
            printf(" ");
    }
        for (k = 1; k <= i; k++)//star
     {
        printf("* ");
    }
        printf("\n");
    }

   return 0;
}