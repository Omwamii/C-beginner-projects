#include <stdio.h>
#include <stdlib.h>
//this code converts a binary number to a decimal

int main(void)
{
    int n, nsave, rem, d;
    int j = 1;
    int dec = 0;

    printf("Enter binary number..\n");
    scanf("%d", &n);
    nsave = n;

    while (n > 0)
    {
        rem = n % 10; //grab last digit to mult it to 2^(x) in next code
        d = rem * j;
        dec += d;
        j *= 2; //since its binary, mults of 2
        n /= 10; //skips the last digit already added, converts to decimal due to int
    }

    printf("Binary : %d\t\t Decimal: %d\n", nsave, dec);
}