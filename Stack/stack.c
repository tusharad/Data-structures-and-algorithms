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

void insert_at_bottom(int val){
  if(isEmpty()){
    push(val);
  }
  else{
    int x = peek();
    pop();
    insert_at_bottom(val);
    push(x);
  }
}

void reverse(){
  if(!isEmpty()){
    int x = peek();
    pop();
    reverse();
    insert_at_bottom(x);
  }
}

void printStack()
{
  stack *curr = top;
  while (curr != NULL)
  {
    printf("%d->", curr->data);
    curr = curr->next;
  }
    printf("Hello World!");
}

int main()
{
  init();
  push(20);
  push(30);
  push(40);
  //reverse();
  printStack();
  pop();
  printStack();
  printf("%d\n", peek());
  return 0;
}
