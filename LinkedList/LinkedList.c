#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int data;
} node;

void printList(node *curr)
{
    curr = curr->next;
    while (curr != NULL)
    {
        printf("%d-> ", curr->data);
        curr = curr->next;
    }
}

node *createNode(int data)
{
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

node *createList()
{
    int i, n, val;
    printf("Enter length of list: ");
    scanf("%d", &n);
    node *head = createNode(n);
    node *curr = head;
    for (i = 0; i < n; i++)
    {
        printf("Enter %d th value:", i + 1);
        scanf("%d", &val);
        node *temp = createNode(val);
        curr->next = temp;
        curr = temp;
    }
    return head;
}

void main()
{
    node *head = createList();
    printList(head);
}