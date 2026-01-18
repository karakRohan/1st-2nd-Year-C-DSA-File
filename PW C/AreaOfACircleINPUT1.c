#include<stdio.h>
#include <math.h>
int main(){
    float radius;
    printf ("Enter radius : ");
    scanf("%f",&radius);
    float pi=3.1415;
    float area = pi*pow(radius,2);
    printf("The Area Circle Is : %f",area);
    return 0;
}