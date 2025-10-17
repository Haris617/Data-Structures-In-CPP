#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node* previous;
};

node* head = nullptr;
node* tail = nullptr;

void insertAtStart(int val)
{
    node* n = new node;
    n->data = val;
    n->previous = nullptr;
    n->next = nullptr;

    if (head == nullptr)
    {
        head = tail = n;
    }

    else 
    {
        n->next = head;
        head->previous = n;
        head = n;
    }
}

void insertAtEnd(int val)
{
    node* n = new node;
    n->data = val;
    n->previous = nullptr;
    n->next = nullptr;

    if (head == nullptr)
    {
        head = tail = n;
    }

    else
    {
        tail->next = n;
        n->previous = tail;
        tail = n;
    }
}

void displayForward()
{
    node* temp = head;

    if (head == nullptr) 
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Displaying Forward" << endl;

    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

void displayBackward()
{
    node* temp = tail;

    if (tail == nullptr)
    {
        cout << "List is empty" << endl;
        return;
    }

    cout << "Displaying Backward" << endl;

    while (temp != nullptr) 
    {
        cout << temp->data << " ";
        temp = temp->previous;
    }

    cout << endl;
}

void insertAtSpecificPosition(int val, int pos)
{
    node* n = new node;
    n->data = val;
    n->previous = nullptr;
    n->next = nullptr;

    if (head == nullptr) 
    {
        head = tail = n;
        return;
    }

    else if (pos == 1)
    {
        n->next = head;
        head->previous = n;
        head = n;
        return;
    }

    node* Previous = head;
    for (int i = 1; i < pos - 1 && Previous->next != nullptr; i++) 
    {
        Previous = Previous->next;
    }

    if (Previous == tail) 
    {
        tail->next = n;
        n->previous = tail;
        tail = n;
        return;
    }

    node* Current = Previous->next;
    n->next = Current;
    n->previous = Previous;
    Previous->next = n;
    Current->previous = n;
}

void deleteAtStart()
{
    node* temp = head;

    if (!temp) 
    {
        cout << "List is Empty" << endl;
    }

    else 
    {
        if (head == tail) 
        {
            delete head;
            head = tail = nullptr;
        }
        
        else 
        {
            head = head->next;
            head->previous = nullptr;
            delete temp;
        }
    }
}

void deleteAtEnd()
{
    node* temp = tail;

    if (!temp)
    {
        cout << "List is Empty" << endl;
        return;
    }

    if (head == tail) 
    {
        delete head;
        head = tail = nullptr;
    }

    else 
    {
        tail = tail->previous;
        tail->next = nullptr;
        delete temp;
    }
}

void deleteAtSpecificPosition(int pos)
{
    node* current = head;

    if (pos == 1) 
    {
        deleteAtStart();
    }

    else 
    {
        for (int i = 1; i < pos && current != nullptr; i++) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << "Invalid position" << endl;
            return;
        }

        if (current == tail) {
            tail = tail->previous;
            if (tail) tail->next = nullptr;
            else head = nullptr;
            delete current;
            return;
        }

        current->previous->next = current->next;
        current->next->previous = current->previous;

        delete current;
    }
}

int main()
{
    insertAtEnd(20);
    insertAtEnd(30);
    insertAtEnd(40);
    insertAtEnd(50);
    insertAtEnd(60);
    insertAtStart(10);

    deleteAtStart();
    deleteAtEnd();
    deleteAtSpecificPosition(2);

    displayForward();
    displayBackward();

    return 0;
}
