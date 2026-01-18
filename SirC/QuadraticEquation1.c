#include <stdio.h>
#include <math.h>
int main()
{
    float a, b, c, root1, root2;
    printf("Enter Co.Effcients : ");
    scanf("%f%f%f", &a, &b, &c);
    if (a == 0 && b == 0)
        printf("No Solution");
    else if (a == 0)
    {
        root1 = -c / b;
        printf("Root Is %f", root1);
    }
    else if ((b * b - 4 * a * c) < 0)
        printf("No Real Roots");
    else
    {
        root1 = (-b + sqrt(b * b - 4 * a * c)) / (2 * a);
        root2 = (-b - sqrt(b * b - 4 * a * c)) / (2 * a);
        printf("Roots Are %f and %f", root1, root2);
    }
    return 0;
}