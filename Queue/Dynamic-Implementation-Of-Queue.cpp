#include <iostream>
using namespace std;

struct node
{
	int data;
	node* next;

	node()
	{
		data = 0;
		next = nullptr;
	}
};

struct Queue
{
	node* front;
	node* rear;

	Queue()
	{
		front = nullptr;
		rear = nullptr;
	}

	bool isEmpty()
	{
		return front == nullptr;
	}

	void enqueue(int val)
	{
		node* n = new node;
		n->data = val;

		if (isEmpty())
		{
			front = n;
			rear = n;
			return;
		}

		rear->next = n;
		rear = n;
	}

	int dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return -1;
		}

		node* temp = front;
		int data = temp->data;

		front = front->next;

		delete temp;

		return data;

	}

	void display()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return;
		}

		cout << "Displaying Queue : " << endl;

		node* temp = front;

		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
	}
};

int main()
{
	Queue q1;

	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);

	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;
	cout << q1.dequeue() << endl;

	q1.display();

	return 0;
}
