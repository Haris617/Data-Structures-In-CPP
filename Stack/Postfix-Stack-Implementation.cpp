#include <iostream>
#include <string>
using namespace std;

struct StaticStack
{
    int arr[10];
    int top;

    StaticStack()
    {
        top = -1;
        for (int i = 0; i < 10; i++)
        {
            arr[i] = 0;
        }
    }

    bool isFull() { return top >= 9; }
    bool isEmpty() { return top == -1; }

    void push(int val)
    {
        if (isFull())
        {
            cout << "Stack is Full" << endl;
            return;
        }
        top++;
        arr[top] = val;
    }

    void display()
    {
        if (isEmpty())
        {
            cout << "Empty" << endl;
            return;
        }
        for (int i = 0; i <= top; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int pop()
    {
        if (isEmpty())
        {
            return -1;
        }
        int a = arr[top];
        top--;
        return a;
    }
};

int main()
{
    StaticStack s1;

    string x;
    cout << "Enter a Prefix Expression: ";
    cin >> x;

    for (int i = 0; i < x.length(); i++)
    {
        if (x[i] >= '0' && x[i] <= '9')
        {
            s1.push(x[i] - '0');
        }
        else if (x[i] == '+')
        {
            int a = s1.pop();
            int b = s1.pop();
            s1.push(a + b);
        }
        else if (x[i] == '-')
        {
            int a = s1.pop();
            int b = s1.pop();
            s1.push(a - b);
        }
        else if (x[i] == '*')
        {
            int a = s1.pop();
            int b = s1.pop();
            s1.push(a * b);
        }
        else if (x[i] == '/')
        {
            int a = s1.pop();
            int b = s1.pop();
            if (b != 0)
                s1.push(a / b);
            else
                cout << "Error: Division by zero!" << endl;
        }
    }

    cout << "Result: ";
    s1.display();

    return 0;
}
