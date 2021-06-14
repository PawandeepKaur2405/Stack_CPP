#include<iostream>
#include<stack>
using namespace std;

void insertAtBottom(stack<int> &s, int ele)
{
    if(s.empty())
    {
        s.push(ele);
        return;
    }

    int topEle = s.top();
    s.pop();
    insertAtBottom(s,ele);

    s.push(topEle);
}

void reverse(stack<int> &s)
{
    if(s.empty())
    {
        return;
    }

    int ele = s.top();
    s.pop();
    reverse(s);

    insertAtBottom(s,ele);
}

int main()
{
    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);

    reverse(s);

    while(!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    
    return 0;
}