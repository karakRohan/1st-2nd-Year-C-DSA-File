#include<stdio.h>
int main ()
{
  int n,i,j,a=1;
  printf ("Enter How Many Lines : ");
  scanf ("%d",&n);
  for (i=1;i<=n;i++)
  {
    a=1;
    for(j=1;j<=i;j++)
    {
     printf ("%d",a);
     a++;
    }
    printf ("\n");
  }
   

    return 0;
}