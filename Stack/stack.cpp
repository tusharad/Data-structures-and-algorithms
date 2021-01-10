#include <iostream>
using namespace std;

class Stack
{
    Stack *next, *top;
    int data;

public:
    void init();
    int isEmpty();
    void push(int);
    void pop();
    int peek();
    void printStack();
};

void Stack::init()
{
    top = NULL;
}

int Stack::isEmpty()
{
    return top == NULL;
}

void Stack::push(int val)
{
    Stack *temp = new Stack();
    temp->data = val;
    temp->next = top;
    top = temp;
}

void Stack::pop()
{
    if (isEmpty())
    {
        printf("Stack UnderFlow!");
        return;
    }
    Stack *temp = top;
    top = top->next;
    temp->next = NULL;
    free(temp);
}

int Stack::peek()
{
    return top->data;
}

void Stack::printStack()
{
    Stack *curr = top;
    while (curr != NULL)
    {
        printf("%d->", curr->data);
        curr = curr->next;
    }
    printf("\n");
}

int main()
{
    Stack obj;
    obj.init();
    obj.push(19);
    obj.push(120);
    obj.push(21);
    obj.push(22);
    obj.printStack();
    obj.pop();
    obj.pop();
    printf("%d\n", obj.peek());
    obj.printStack();
}