#include <iostream>
#define max 5
using namespace std;

/*
 * Node structure for linked list implementation of stack
 * Contains data and pointer to next node
 */
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

/*
 * Stack implementation using linked list
 * Supports push, pop, display, center finding, and copy operations
 */
struct stack
{
	node* top;
	int number = 0;

	stack()
	{
		top = nullptr;
	}

	bool isEmpty()
	{
		return top == nullptr;
	}

	// Push element onto stack (LIFO)
	void push(int val)
	{
		if (number >= max)
		{
			cout << "Stack is Full" << endl;
			return;
		}

		node* n = new node;
		n->data = val;

		if (!top)
		{
			top = n;
			number++;
		}
		else
		{
			n->next = top;
			top = n;
			number++;
		}
	}

	// Pop element from top of stack
	void pop()
	{
		if (!top)
		{
			cout << "Stack is Empty" << endl;
			return;
		}
		else
		{
			node* temp = top;
			top = top->next;

			cout << temp->data << " is Popped" << endl;
			number--;
			delete temp;
		}
	}

	// Display all elements in stack
	void display()
	{
		if (!top)
		{
			cout << "Stack is Empty" << endl;
			return;
		}

		node* temp = top;

		cout << "Displaying Stack" << endl;

		while (temp)
		{
			cout << temp->data << "->";
			temp = temp->next;
		}

		cout << "NULL" << endl;
	}

	// Find and display center element of stack
	void center()
	{
		if (!top)
		{
			cout << "Stack is Empty" << endl;
			return;
		}

		node* temp = top;
		int n = 0;

		// Count total elements
		while (temp)
		{
			n++;
			temp = temp->next;
		}

		temp = top;

		// Traverse to center node (first middle for even length)
		for (int i = 0; i < (n-1) / 2; i++)
		{
			temp = temp->next;
		}

		cout << "Center of Node is " << temp->data << endl;
	}
	
	// Get top element without popping
	int getTop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty" << endl;
			return 0;
		}
		else
		{
			return top->data;
		}
	}
};

/*
 * Creates a copy of stack a using temporary stack b
 * Uses double reversal to maintain original order
 */
stack copyStack(stack a, stack b)
{
	node* temp = a.top;
	stack c;

	if (!a.top)
	{
		return c;
	}

	// First reversal: a -> b
	while (a.top)
	{
		b.push(a.top->data);
		a.top = a.top->next;
	}

	// Second reversal: b -> c (restores original order)
	while (b.top)
	{
		c.push(b.top->data);
		b.top = b.top->next;
	}

	return c;
}

/*
 * Main function demonstrating stack operations:
 * - Push elements
 * - Display stack
 * - Pop elements  
 * - Find center
 * - Get top element
 */
int main()
{
	stack s1;

	// Push elements (6th push will show stack full)
	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);
	s1.push(60);

	s1.display();

	// Pop three elements
	s1.pop();
	s1.pop();
	s1.pop();

	s1.display();

	// Find center element
	s1.center();

	// Get top element
	s1.getTop();

	return 0;
}
