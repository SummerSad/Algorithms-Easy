// Circular Linked Lists

#include <stdio.h>
#include <stdlib.h>

struct CNode {
    int data;
    struct CNode *next;
};

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

void delEnd(struct CNode **head)
{
    if (*head != NULL) {
        struct CNode *cur = *head;
        struct CNode *prev;
        while (cur->next != *head) {
            prev = cur;
            cur = cur->next;
        }
        prev->next = *head;
        free(cur);
    }
}

void delFront(struct CNode **head)
{
    if (*head != NULL) {
        struct CNode *cur = *head;
        while (cur->next != *head) {
            cur = cur->next;
        }
        struct CNode *temp = *head;
        *head = (*head)->next;
        cur->next = *head;
        free(temp);
    }
}

int main()
{
    struct CNode *head = NULL;
    insertEnd(&head, 1);
    insertEnd(&head, 2);
    insertEnd(&head, 3);

    delFront(&head);

    printf("Count: %d\n", countCNode(head));
    printCNode(head);

    return 0;
}
