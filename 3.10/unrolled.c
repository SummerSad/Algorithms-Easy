#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int value;
    struct Node *next;
} Node;

typedef struct Block {
    struct Block *next;
    Node *head;
    int nodeCount;
} Block;

int main() { return 0; }
