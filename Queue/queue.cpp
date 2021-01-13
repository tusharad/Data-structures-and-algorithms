#include <iostream>
using namespace std;

class Node
{
  Node *next, *front, *rear;
  int data;

public:
  Node()
  {
    front = rear = NULL;
  }
  int isEmpty();
  void insert(int);
  void printQueue();
  void removeQueue();
};

int Node::isEmpty()
{
  return front == NULL;
}

void Node::insert(int val)
{
  Node *temp = new Node();
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

void Node::removeQueue()
{
  if (isEmpty())
  {
    cout << "Queue underflow!" << endl;
    return;
  }
  Node *temp = front;
  front = front->next;
  cout << "Deleted element is " << temp->data << endl;
  delete temp;
}

void Node::printQueue()
{
  cout << "Queue:" << endl;
  Node *curr = front;
  while (curr != NULL)
  {
    cout << curr->data << "->";
    curr = curr->next;
  }
  cout << endl;
}

int main()
{
  Node obj;
  obj.insert(10);
  obj.insert(20);
  obj.insert(30);
  obj.insert(40);
  obj.printQueue();
  obj.removeQueue();
  obj.printQueue();
}
