// Generate all the strings of length n drawn from 0..k-1
#include <stdio.h>
#define MAX 5
char A[MAX];

void kstring(int n, int k)
{
    if (n < 1) {
        printf("%s\n", A);
    }
    else {
        for (int i = 0; i < k; i++) {
            A[n - 1] = '0' + i;
            kstring(n - 1, k);
        }
    }
}

int main()
{
    kstring(MAX, 3);
    return 0;
}
