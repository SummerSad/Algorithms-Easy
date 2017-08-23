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

Node *newNode(int value) {
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->value = value;
    temp->next = NULL;
    return temp;
}

Block *newBlock() {
    Block *temp = (Block *)malloc(sizeof(Block));
    temp->next = NULL;
    temp->head = NULL;
    temp->nodeCount = 0;
    return temp;
}

int main() {
    printf("Hello World\n");
    return 0;
}
