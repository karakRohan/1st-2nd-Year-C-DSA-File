#include<stdio.h>
int main() 
{
  char ch = 'A';
  while (ch <= 'Z')
  {
    printf ("\n%c->%d",ch,ch);
    ch++;
  }
    return 0;
}