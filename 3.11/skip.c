// Implement of Skip Lists

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

typedef struct SkipLists {
    Node *head;
    int listLevel;  // current level of lists
} SkipLists;

int main() { return 0; }
