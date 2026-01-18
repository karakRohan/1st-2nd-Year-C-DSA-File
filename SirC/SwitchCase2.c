#include<stdio.h>
int main ()
{
float a,b,c;
char op;
printf ("Enter Two Values");
scanf ("%f%f",&a,&b);
printf ("Enter Opertor");
scanf ("%c",&op);
switch (op)
{
    case '+' : c = a+b;
               printf ("sum=%f",c);
               break;
    case '-' : c = a-b;
               printf ("substration=%f",c);
               break;
    case '*' : c = a*b;
               printf ("Multipication=%f",c);
               break;
    case '/' : c = a/b;
               printf ("Devicition=%f",c);
               break;
    default : printf("\nWrong Operator");                                      
}
     
}