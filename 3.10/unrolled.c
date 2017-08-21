#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int blockSize;  // max numbers of nodes in block

struct ListNode {
    int value;
    struct ListNode *next;
};

struct LinkedBlock {
    struct LinkedBlock *next;
    struct ListNode *head;
    int nodeCount;
};

int main() { return 0; }
