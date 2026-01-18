#include<stdio.h>
int main () {
    int a,b; // a > b
    printf("Enter Divident : ");
    scanf("%d",&a);
    printf("Enter Divisor : ");
    scanf("%d",&b);
    int q = a/b;
    int r = a - b*q; //Divisor * Quotient + Remainder = Dividend 
    printf("The Remainder When %d Is Divided By %d Is : %d",a,b,r);
    return 0;
}