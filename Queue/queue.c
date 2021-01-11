#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    struct Queue *next;
    int data;
} queue;

queue *front, *rear;

int isEmpty()
{
    return front == NULL;
}

void insertQueue(int val)
{
    queue *temp;
    temp = (queue *)malloc(sizeof(queue));
    temp->data = val;
    temp->next = NULL;
    if (isEmpty())
    {
        front = rear = temp;
    }
    else
    {
        rear->next = temp;
        rear = temp;
    }
}

void removeQueue()
{
    if (isEmpty())
    {
        printf("Queue underflow!\n");
        return;
    }
    queue *temp = front;
    front = front->next;
    printf("Deleted node is %d\n", temp->data);
    free(temp);
}

void printQueue()
{
    queue *curr = front;
    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}
void main()
{
    insertQueue(2);
    insertQueue(3);
    insertQueue(4);
    insertQueue(5);
    insertQueue(6);
    removeQueue();
    printQueue();
}