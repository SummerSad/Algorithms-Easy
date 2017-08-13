// Circular Linked Lists

#include <stdio.h>
#include <stdlib.h>

typedef struct CNode {
    int data;
    struct CNode *next;
} CNode;

int countCNode(struct CNode *head)
{
    if (head == NULL) return 0;
    struct CNode *cur = head;
    int count = 0;
    do {
        count++;
        cur = cur->next;
    } while (cur != head);
    return count;
}

void printCNode(struct CNode *head)
{
    if (head == NULL)
        printf("NULL\n");
    else {
        struct CNode *cur = head;
        do {
            printf("%d->", cur->data);
            cur = cur->next;
        } while (cur != head);
        printf("head\n");
    }
}

void insertEnd(struct CNode **head, int data)
{
    struct CNode *endNode = (struct CNode *)malloc(sizeof(struct CNode));
    if (endNode == NULL) {
        printf("Memory error\n");
        return;
    }
    endNode->data = data;
    endNode->next = endNode;

    if (*head == NULL) {
        *head = endNode;
    }
    else {
        struct CNode *cur = *head;
        while (cur->next != *head) {
            cur = cur->next;
        }
        cur->next = endNode;
        endNode->next = *head;
    }
}

void insertFront(struct CNode **head, int data)
{
    struct CNode *frontNode = (struct CNode *)malloc(sizeof(struct CNode));
    if (frontNode == NULL) {
        printf("Memory Eror\n");
        return;
    }
    frontNode->data = data;
    frontNode->next = frontNode;
    if (*head == NULL) {
        *head = frontNode;
    }
    else {
        struct CNode *cur = *head;
        while (cur->next != *head) {
            cur = cur->next;
        }
        frontNode->next = *head;
        cur->next = frontNode;
        *head = frontNode;
    }
}

int main()
{
    struct CNode *head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertFront(&head, 3);

    printf("Count: %d\n", countCNode(head));
    printCNode(head);

    return 0;
}
