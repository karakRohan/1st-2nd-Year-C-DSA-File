#include <stdio.h>
#include <math.h>

int main() {
    int n, m, p, r, len = 0, sum = 0;
    printf("Enter A Number : ");
    scanf("%d",&n);
    m = n;
    p = n;
    while (m > 0) {
        len++;
        m = m / 10;
    }
    while (p > 0) {
        r = p % 10;
        sum = sum + pow(r, len);
        p = p / 10;
    }
    if (n == sum)
        printf("%d Armstrong Number IS : \n", n);
    else
        printf("%d Not Armstrong Number IS : \n", n);
    // return 0;
}
