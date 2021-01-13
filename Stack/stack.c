#include <stdio.h>
#include <stdlib.h>

typedef struct Stack
{
  struct Stack *next;
  int data;
} stack;

stack *top;

void init()
{
  top = NULL;
}

int isEmpty()
{
  return top == NULL;
}

void push(int val)
{
  stack *temp = (stack *)malloc(sizeof(stack));
  temp->data = val;
  temp->next = top;
  top = temp;
}

void pop()
{
  if (isEmpty())
  {
    printf("Stack UnderFlow!");
    return;
  }
  stack *temp = top;
  top = top->next;
  temp->next = NULL;
  free(temp);
}

int peek()
{
  return top->data;
}

void printStack()
{
  stack *curr = top;
  while (curr != NULL)
  {
    printf("%d->", curr->data);
    curr = curr->next;
  }
  printf("\n");
}

void main()
{
  init();
  push(20);
  push(30);
  push(40);
  printStack();
  pop();
  printStack();
  printf("%d\n", peek());
}
