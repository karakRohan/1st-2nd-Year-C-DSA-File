// #include<stdio.h>
// #include<math.h>
// int main(){
//     float a, b, c;
//     scanf("%f\n", &a);
//     scanf("%f\n", &b);
//     scanf("%f\n", &c);
//     float det= b*b - 4*a*c;
//     if (det<0){    
//         printf("No real roots present");
//     }
//     else{
//         if(det==0){
//             printf("roots are equal.\n");
//             printf("the roots are: %f and %f", (-b/(2*a)));
//         }
//         else{
//             float r1= (-b + sqrt(det))/(2*a);
//             float r2= (-b - sqrt(det))/(2*a);
//             printf("The roots are: %f and %f", r1, r2);
//   }}

// }

#include <stdio.h>
#include <math.h>

int main() {
    float a, b, c;
    
    printf("Enter a: ");
    scanf("%f", &a);
    
    printf("Enter b: ");
    scanf("%f", &b);
    
    printf("Enter c: ");
    scanf("%f", &c);
    
    float det = b * b - 4 * a * c;
    
    if (det < 0) {    
        printf("No real roots present");
    } else {
        if (det == 0) {
            printf("Roots are equal.\n");
            printf("The root is: %f", (-b / (2 * a)));
        } else {
            float r1 = (-b + sqrt(det)) / (2 * a);
            float r2 = (-b - sqrt(det)) / (2 * a);
            printf("The roots are: %f and %f", r1, r2);
        }
    }

    return 0;
}
