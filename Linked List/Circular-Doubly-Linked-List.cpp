#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;
	node* prev;

	node()
	{
		data = 0;
		next = nullptr;
		prev = nullptr;
	}

	node(int d)
	{
		data = d;
		next = nullptr;
		prev = nullptr;
	}
};

struct circularLinkedList
{
	node* head;
	node* tail;

	circularLinkedList()
	{
		head = nullptr;
		tail = nullptr;
	}

	void addNode(int val)
	{
		node* n = new node;
		n->data = val;

		if (!head)
		{
			head = tail = n;
			tail->next = head;
			head->prev = tail;
			return;
		}

		tail->next = n;
		n->prev = tail;
		tail = n;
		tail->next = head;
		head->prev = tail;
	}

	void display()
	{
		if (!head)
		{
			cout << "Linked List is Empty" << endl;
			return;
		}

		node* temp = head;

		while (true)
		{
			cout << temp->data << " ";

			if (temp == tail)
			{
				return;
			}

			temp = temp->next;
		}
	}

	void addAtHead(int val)
	{
		node* n = new node;
		n->data = val;

		if (!head)
		{
			head = tail = n;
			tail->next = head;
			head->prev = tail;
			return;
		}

		tail->next = n;
		n->prev = tail;
		
		n->next = head;
		head->prev = n;

		head = n;
	}

	void addAtTail(int val)
	{
		node* n = new node;
		n->data = val;

		if (!head)
		{
			head = tail = n;
			return;
		}

		tail->next = n;
		n->prev = tail;
		tail = n;
		tail->next = head;
		head->prev = tail;
	}

	int totalNodes()
	{
		int n = 0;

		if (!head)
		{
			return n;
		}

		node* temp = head;

		while (true)
		{
			if (temp == tail)
			{
				n++;
				return n;
			}

			n++;
			temp = temp->next;
		}

		return n;
	}

	void deleteNode(int index)
	{
		if (!head)
		{
			cout << "List is empty!" << endl;
			return;
		}

		if (index < 0)
		{
			cout << "Invalid Index" << endl;
			return;
		}

		int total = totalNodes();

		if (index >= total)
		{
			cout << "Index Exceed" << endl;
			return;
		}

		// Case 1: Delete head node (index 0)
		if (index == 0)
		{
			node* current = head;

			// If only one node in the list
			if (head == tail)
			{
				delete head;
				head = tail = nullptr;
				return;
			}

			tail->next = head->next;
			head->next->prev = tail;
			head = head->next;
			delete current;
			return;
		}

		// Case 2: Delete tail node (last index)
		if (index == total - 1)
		{
			node* current = tail;
			tail = tail->prev;
			tail->next = head;
			head->prev = tail;
			delete current;
			return;
		}

		// Case 3: Delete middle node
		node* temp = head;

		// Traverse to the node at given index
		for (int i = 0; i < index; i++)
		{
			temp = temp->next;
		}

		// Update the links to bypass the node to be deleted
		temp->prev->next = temp->next;
		temp->next->prev = temp->prev;
		delete temp;
	}
};

int main()
{
	circularLinkedList c1;

	c1.addNode(10);
	c1.addNode(20);
	c1.addNode(30);

	c1.addAtHead(0);
	c1.addAtTail(40);

	c1.display();

	cout << c1.totalNodes();


	return 0;
}
