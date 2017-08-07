// Towers of Hanoi puzzle
// | | |
// | | |
// _ _ _
// 1 2 3

#include <stdio.h>

void solveHanoi(int n, char from, char to, char temp)
{
    if (n == 1) {
        printf("Move %c to %c\n", from, to);
    }
    else {
        solveHanoi(n - 1, from, temp, to);
        printf("Mode %c to %c\n", from, to);
        solveHanoi(n - 1, temp, to, from);
    }
}

int main()
{
    solveHanoi(50, 'A', 'C', 'B');
    return 0;
}
