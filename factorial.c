#include <stdio.h>
//this program finds the factorial of a num by *recursion*

long fact(int n);

int main(void)
{
    int n;

    printf("Enter a number to find its factorial...\n");
    scanf("%d", &n);
    printf("Factorial of %d is %d", n, fact(n));
}

long fact(int n)
{
    if (n == 0)//factorial of 0 is 1
        return (1);
    else
        return (n * fact(n-1));// recursion call until n == 0 
}