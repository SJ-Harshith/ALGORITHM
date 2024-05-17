#include <stdio.h>
#include<math.h>
void SieveOfEratosthenes(int n)
{
    int a[n+1];
    //
    int i, j;

    // Initialize all entries with their index values. A value in a[i] will
    // finally be zero if i is Not a prime, else it will remain its index value.
    for (i = 2; i <= n; i++)
        a[i] = i;

    // Sieve process begins
    for (i = 2; i<=floor(sqrt(n)); i++)
    {
        // If a[i] is not zero, then it is a prime
        if (a[i] != 0)
        {
            // Mark all multiples of i as not prime by setting them to zero
            for (j = i * i; j <= n; j += i)
                a[j] = 0;
        }
    }

    // Print all prime numbers
    for (i = 2; i <= n; i++)
    {
        // If the value at index i is not zero, then it is a prime number
        if (a[i] != 0)
            printf("%d ", a[i]);
    }
}

int main()
{
    int n = 50; // Change this value to n for which you want to find all a <= n
    SieveOfEratosthenes(n);
    return 0;
}
