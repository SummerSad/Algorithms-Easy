// Generate all the strings of n bits

#include <stdio.h>
#include <stdlib.h>
#define MAX 10

char A[MAX];

void binary(int n)
{
    if (n < 1)
        printf("%s\n", A);
    else {
        A[n - 1] = '0';
        binary(n - 1);
        A[n - 1] = '1';
        binary(n - 1);
    }
}

int main()
{
    binary(MAX);
    return 0;
}
