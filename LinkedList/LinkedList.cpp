#include <iostream>
using namespace std;

class Node
{
    friend class List;
    int data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

class List
{
    Node *head;

public:
    void printList();
    void createList();
    void insertNode(int, int);
    Node *traverse(Node *, int);
    void deleteNode(int);
    void reverse();
};

void List::deleteNode(int pos)
{
    Node *curr = head, *temp;
    curr = traverse(curr, pos - 1);
    temp = curr->next;
    curr->next = curr->next->next;
    head->data--;
    delete temp;
}

Node *List::traverse(Node *curr, int pos)
{
    for (int i = 0; i < pos; i++)
        curr = curr->next;
    return curr;
}

void List::reverse()
{
    Node *curr = head->next, *prev = NULL, *nex;
    while (curr != NULL)
    {
        nex = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nex;
    }
    head->next = prev;
}

void List::insertNode(int pos, int val)
{
    if (pos > head->data || pos < 1)
        return;
    Node *curr = head, *temp;
    temp = new Node(val);
    if (pos == head->data)
        curr = traverse(curr, pos);
    else
        curr = traverse(curr, pos - 1);
    temp->next = curr->next;
    curr->next = temp;
    head->data++;
}

void List::createList()
{
    int n, val;
    Node *curr, *temp;
    cout << "Enter Length: ";
    cin >> n;
    head = new Node(n);
    curr = head;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter " << i + 1 << "th value: ";
        cin >> val;
        temp = new Node(val);
        curr->next = temp;
        curr = temp;
    }
}

void List::printList()
{
    Node *curr = head->next;
    while (curr != NULL)
    {
        cout << curr->data << "->";
        curr = curr->next;
    }
    cout << endl;
}

int main()
{
    List obj;
    obj.createList();
    //obj.insertNode(1, 100);
    //obj.printList();
    //obj.deleteNode(1);
    obj.reverse();
    obj.printList();
    return 0;
}