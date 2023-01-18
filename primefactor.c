#include <stdio.h>
#include <math.h>

//find prime factors of a number
int main(void)
{
    long num;
    int i, j;

    printf("Enter a number to find prime factors:\n");
    scanf("%ld", &num);

    for (j = 0; j < num; j++)
    {
        if (num % 2 == 0)
        {
            num /= 2;
            printf("2, ");
        }

        else if (num % 3 == 0)
        {
            num /= 3;
            printf("3, ");
        }

        else
        {
            for (i = 3; i < num; i += 2)
            {
                while (num % i == 0)
                {
                    num /= i;
                    printf("%d, ", i);
                }
            }
        }        
    }

    printf("%ld", num);
}