#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    struct Node *next;
    int data;
} node;

void printList(node *head)
{
    node *curr = head;
    curr = curr->next;
    while (curr != head)
    {
        printf("%d-> ", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

node *createNode(int val)
{
    node *temp = NULL;
    temp = (node *)malloc(sizeof(node));
    temp->data = val;
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
    curr->next = head;
    return head;
}

node *traverse(node *curr, int pos)
{
    int i;
    for (i = 0; i < pos; i++)
        curr = curr->next;
    return curr;
}

void insertNode(node *head, int pos, int val)
{
    if (pos > head->data || pos < 1)
    {
        return;
    }
    node *curr = head, *temp;
    if (pos == head->data) //last position
        curr = traverse(curr, pos);
    else
        curr = traverse(curr, pos - 1);

    temp = createNode(val);
    temp->next = curr->next;
    curr->next = temp;
    head->data++;
}

void deleteNode(node *head, int pos)
{
    node *curr = head, *temp;
    curr = traverse(curr, pos - 1);
    temp = curr->next;
    curr->next = curr->next->next;
    head->data--;
    free(temp);
}

void reverse(node *head)
{
    node *curr = head->next, *prev = NULL, *nex;
    while (curr != NULL)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head->next = prev;
}

void main()
{
    node *head = createList();
    printList(head);
    insertNode(head, 3, 100);
    printList(head);
    deleteNode(head, 4);
    reverse(head);
    printList(head);
}
