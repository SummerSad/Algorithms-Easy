#include <stdio.h>

int isSort(int *A, int size)
{
    if (size == 1) return 1;
    return (A[size - 1] < A[size - 2]) ? 0 : isSort(A, size - 1);
}

int main()
{
    int A[] = {1, 2, 3, 10, 5, 6, 7, 8};
    int size = sizeof(A) / sizeof(A[0]);
    if (isSort(A, size))
        printf("A is sorted\n");
    else
        printf("NO\n");
    return 0;
}
