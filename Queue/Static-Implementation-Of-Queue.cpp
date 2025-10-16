#include <iostream>
#define max 5
using namespace std;

struct Queue
{
	int queue[max];
	int front;
	int rear;

	// Constructor: initializes queue with zeros and sets front & rear to -1
	Queue()
	{
		for (int i = 0; i < max; i++)
		{
			queue[i] = 0;
		}
		front = rear = -1;
	}

	// Checks if queue is empty
	bool isEmpty()
	{
		return front == -1 && rear == -1;
	}

	// Checks if queue is full
	bool isFull()
	{
		return rear == max - 1;
	}

	// Adds an element to the queue
	void enqueue(int val)
	{
		if (isEmpty())
		{
			front++;
			rear++;
			queue[rear] = val;
			cout << val << " added in Queue" << endl;
			return;
		}

		if (isFull())
		{
			cout << "Queue is Full" << endl;
			return;
		}

		rear++;
		queue[rear] = val;
		cout << val << " added in Queue" << endl;
	}

	// Removes the front element from the queue
	void dequeue()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return;
		}

		cout << queue[front] << " is dequeued" << endl;

		// Reset when last element is dequeued
		if (front == rear)
		{
			front = rear = -1;
		}
		else
		{
			front++;
		}
	}

	// Displays all elements in the queue
	void display()
	{
		if (isEmpty())
		{
			cout << "Queue is Empty" << endl;
			return;
		}

		for (int i = front; i <= rear; i++)
		{
			cout << queue[i] << " ";
		}
		cout << endl;
	}
};

int main()
{
	Queue q1;

	q1.enqueue(10);
	q1.enqueue(20);
	q1.enqueue(30);
	q1.enqueue(40);
	q1.enqueue(50);
	q1.enqueue(60); // Won’t be added (Queue full)

	q1.display();

	q1.dequeue();
	q1.dequeue();

	q1.display();

	return 0;
}
