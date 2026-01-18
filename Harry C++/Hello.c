#include <stdio.h>
int main()
{
    int N, count = 0, num = 2, sum = 0;
    int isPrime;
    // Take user input
    printf("Enter the value of N: ");
    scanf("%d", &N);
    // Find the first N prime numbers and sum them
    while (count < N)
    {
        isPrime = 1; // Assume the number is prime
        // Check if 'num' is prime
        for (int i = 2; i * i <= num; i++)
        {
            if (num % i == 0)
            {
                isPrime = 0; // Not a prime number
                break;
            }
        }
        // If 'num' is prime, add it to the sum
        if (isPrime)
        {
            sum += num;
            count++;
        }
        // Move to the next number
        num++;
    }
    // Display the result
    printf("The sum of the first %d prime numbers is: %d\n", N, sum);
    return 0;
}