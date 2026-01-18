#include <stdio.h>

int main() {
    int term;

    printf("A.P. series: ");
    for (term = 100; term > 0; term -= 3) {
        printf("%d ", term);
    }

    printf("\n");
    return 0;
}
