#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define sizeBlock 10

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

void findEle(int k, Block *headBlock, Block **posBlock, Node **posNode) {
    int i = k / sizeBlock;  // kth Node in ith Block
    *posBlock = headBlock;
    while (i > 0) {
        *posBlock = (*posBlock)->next;
        i--;
    }
    int j = k % sizeBlock;  // kth Node is jth Node in Block
    *posNode = (*posBlock)->head;
    while (j > 0) {
        *posNode = (*posNode)->next;
        j--;
    }
}

int main() {
    printf("Hello World\n");
    return 0;
}
