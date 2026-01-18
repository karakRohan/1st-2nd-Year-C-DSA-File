#include<stdio.h>
int main ()
{
    float marks;
    printf ("Enter Total Marks : ");
     scanf ("%f",&marks);
    if (marks<=100&&marks>=90)
       printf("Grade O");
    else if (marks<=90&&marks>=80)
       printf("Grade E");
    else if (marks<=80&&marks>=70)
       printf("Grade A");
    else if (marks<=70&&marks>=60)
       printf("Grade B");
    else
       printf ("Fail");
        return 0;
}