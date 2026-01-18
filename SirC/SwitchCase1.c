#include<stdio.h>
int main ()
{
    int a = 3;
    switch (a)
    {
        case 5 : printf ("five");
                 break;
        case 3 : printf ("three");
                break;
        case 9 : printf ("nine");
                 break;
                 defalut : printf ("Other");        
    }
    return 0;
}