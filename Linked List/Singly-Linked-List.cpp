#include <iostream>
using namespace std;

struct node {
    int data;
    node* next;
};

node* head = nullptr;
node* tail = nullptr;

void insertAtEnd(int val) {
    node* n = new node;
    n->data = val;
    n->next = nullptr;

    if (head == nullptr) {
        head = n;
        tail = n;
    }
    else {
        tail->next = n;
        tail = n;
    }
    cout << "Inserted " << val << " at end" << endl;
}

void insertAtStart(int val) {
    node* n = new node;
    n->data = val;
    n->next = nullptr;

    if (head == nullptr) {
        head = tail = n;
    }
    else {
        n->next = head;
        head = n;
    }
    cout << "Inserted " << val << " at start" << endl;
}

void insertAtSpecificPosition(int position, int val) {
    node* n = new node;
    n->data = val;
    n->next = nullptr;

    if (position == 1) {
        n->next = head;
        head = n;
        if (tail == nullptr) tail = n;
        cout << "Inserted " << val << " at position 1" << endl;
        return;
    }

    node* previous = head;
    for (int i = 1; i < position - 1; i++) {
        if (previous == nullptr) {
            cout << "Position " << position << " is out of range" << endl;
            delete n;
            return;
        }
        previous = previous->next;
    }

    n->next = previous->next;
    previous->next = n;
    if (n->next == nullptr) tail = n;

    cout << "Inserted " << val << " at position " << position << endl;
}

void countNodes() {
    node* temp = head;
    int count = 0;

    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    cout << "Total nodes: " << count << endl;
}

void display() {
    node* temp = head;

    if (head == nullptr) {
        cout << "List is empty" << endl;
        return;
    }

    cout << "List: ";
    while (temp != nullptr) {
        cout << temp->data;
        if (temp->next != nullptr) cout << " -> ";
        temp = temp->next;
    }
    cout << endl;
}

void searchValue(int val) {
    node* temp = head;
    while (temp != nullptr) {
        if (val == temp->data) {
            cout << "Value " << val << " found" << endl;
            return;
        }
        temp = temp->next;
    }
    cout << "Value " << val << " not found" << endl;
}

void deleteAtStart() {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }

    node* temp = head;
    cout << "Deleted " << temp->data << " from start" << endl;

    if (head->next == nullptr) {
        delete head;
        head = tail = nullptr;
    }
    else {
        head = head->next;
        delete temp;
    }
}

void deleteAtEnd() {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }

    if (head->next == nullptr) {
        cout << "Deleted " << head->data << " from end" << endl;
        delete head;
        head = tail = nullptr;
        return;
    }

    node* temp = head;
    while (temp->next != tail) {
        temp = temp->next;
    }
    cout << "Deleted " << tail->data << " from end" << endl;
    delete tail;
    tail = temp;
    tail->next = nullptr;
}

void deleteAtEndnHeadOnly() {
    if (head == nullptr) {
        cout << "List is empty, nothing to delete" << endl;
        return;
    }

    if (head->next == nullptr) {
        cout << "Deleted " << head->data << " (list is empty now)" << endl;
        delete head;
        head = tail = nullptr;
        return;
    }

    node* temp = head;
    while (temp->next->next != nullptr) {
        temp = temp->next;
    }
    cout << "Deleted " << temp->next->data << " from end" << endl;
    delete temp->next;
    temp->next = nullptr;
    tail = temp;
}

void bubbleSort() {
    if (!head) {
        cout << "List does not exist" << endl;
        return;
    }

    bool swapped;
    do {
        node* current = head;
        swapped = false;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                int d = current->data;
                current->data = current->next->data;
                current->next->data = d;
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);

    cout << "List sorted using Bubble Sort" << endl;
}

int main() {
    insertAtEnd(20);
    insertAtEnd(10);
    insertAtEnd(30);
    insertAtEnd(40);
    display();

    bubbleSort();
    display();

    insertAtSpecificPosition(1, 5);
    insertAtSpecificPosition(2, 14);
    display();

    insertAtStart(50);
    insertAtStart(55);
    insertAtStart(70);
    display();

    deleteAtStart();
    display();

    deleteAtEnd();
    display();

    deleteAtEndnHeadOnly();
    display();

    countNodes();

    searchValue(500);
    searchValue(50);

    return 0;
}
