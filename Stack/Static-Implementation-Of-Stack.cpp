#include <iostream>
#define max 5
using namespace std;

struct Stack
{
	int stack[max];
	int top;

	Stack()
	{
		top = -1;

		for (int i = 0; i < max; i++)
		{
			stack[i] = 0;
		}
	}

	bool isEmpty()
	{
		return top == -1;
	}

	bool isFull()
	{
		return top == max - 1;
	}

	void push(int val)
	{

		if (isFull())
		{
			cout << "Stack is Full" << endl;
			return;
		}

		top++;
		stack[top] = val;

		cout << val << " Pushed" << endl;
	}

	void pop()
	{
		if (isEmpty())
		{
			cout << "Stack is Empty" << endl;
			return;
		}

		cout << stack[top] << " is Popped" << endl;
		top--;
	}

	void display()
	{
		cout << "Displaying Stack" << endl;

		for (int i = 0; i <= top; i++)
		{
			cout << stack[i] << " ";
		}
	}
};

int main()
{
	Stack s1;

	s1.push(10);
	s1.push(20);
	s1.push(30);
	s1.push(40);
	s1.push(50);

	s1.pop();

	s1.display();

	return 0;
}
