#include <stdio.h>
#include <stdlib.h>

// Stack with dynamically arr
// Everytime the stack is full, we double
// to prevent O(n^2) copy

typedef struct StackArr {
    int top;
    int size;
    int *arr;
} StackArr;

StackArr *createStack() {
    StackArr *S = (StackArr *)malloc(sizeof(StackArr));
    if (!S) return NULL;
    S->top = -1;  // the index of top
    S->size = 1;  // make size init to 1
    S->arr = (int *)malloc(sizeof(int) * S->size);
    return S;
}

void freeStack(StackArr **S) {
    free((*S)->arr);
    free(*S);
}

int isEmpty(StackArr *S) { return S->top == -1; }

int isFull(StackArr *S) { return S->top == S->size - 1; };

void doubleStack(StackArr **S) {
    (*S)->size *= 2;
    (*S)->arr = (int *)realloc((*S)->arr, (*S)->size);
}

void push(StackArr **S, int val) {
    if (isFull(*S)) {
        doubleStack(S);
    }
    (*S)->arr[++(*S)->top] = val;
}

int pop(StackArr **S) {
    if (!isEmpty(*S)) {
        return (*S)->arr[(*S)->top--];
    }
}

int main() {
    StackArr *S = createStack();
    push(&S, 2);
    push(&S, 3);
    push(&S, 14);
    pop(&S);
    printf("%d\n", pop(&S));
    freeStack(&S);
    return 0;
}
