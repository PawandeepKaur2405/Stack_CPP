#include<bits/stdc++.h>
using namespace std;
#define n 500

class Stack
{
    
    int top;
    int* arr;

    public:

    Stack()
    {
        top = -1;
        arr = new int[n];
    }

    void push(int value)
    {
        if(top == n-1)
        {
            cout<<"Stack Overflow\n";
            return;
        }

        top++;
        arr[top] = value;
    }

    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow\n";
            return;
        }

        top--;
    }

    void Top()
    {
        if(top == -1)
        {
            cout<<"Empty stack\n";
            return;
        }

       cout<<arr[top];
    }

    bool isEmpty()
    {
        if(top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{
    Stack s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.Top();
    s.pop();
    s.Top();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.isEmpty();
    return 0;
}