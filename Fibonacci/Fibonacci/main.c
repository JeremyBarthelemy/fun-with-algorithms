#include <stdio.h>

int fibonacci_recursive(int n)
{
    if (n <= 1)
    {
        return n;
    }
    return fibonacci_recursive(n-1) + fibonacci_recursive(n-2);
}

int fibonacci_iterative(int n)
{
    if (n <= 1)
    {
        return n;
    }

    int a = 0;
    int b = 1;
    int next;
    for (int idx = 2; idx <= n; ++idx)
    {
        next = a + b;
        a = b;
        b = next;
    }
    return b;
}

// 0, 1, 1, 2, 3, 5, 8, 13, ...
int main()
{
    int n = 6;
    printf("Fibonacci Recursive(%d) = %d\n", n, fibonacci_recursive(n));
    printf("Fibonacci Iterative(%d) = %d\n", n, fibonacci_iterative(n));

    return 0;
}
