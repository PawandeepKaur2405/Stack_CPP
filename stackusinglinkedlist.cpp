#include<bits/stdc++.h>
using namespace std; 

class node
{
    public:
    int data;
    node* next;

    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void push(node* &head, int value)
{
    node* n = new node(value);
    if(head == NULL)
    {
        head = n;
        return;
    }
    node* temp = head;

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
}

int pop(node* &head)
{
    if(head == NULL)
    {
        cout<<"Empty stack";
        return -1;
    }

    node* temp = head;
    node* prev = head;

    while(temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }

    prev->next = NULL;
    int t = temp->data;
    delete temp;
    return t;
}

int Top(node* head)
{
    if(head == NULL)
    {
        cout<<"Empty stack\n";
        return -1;
    }
    node* temp = head;
    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    return temp->data;
}

bool empty(node* head)
{
    if(head == NULL)
    {
        return true;
    }
    return false;
}

int main()
{
    node* top = NULL;
    push(top,1);
    push(top,2);
    push(top,3);

    cout<<"Top item : "<<Top(top)<<"\n";
    cout<<"Is stack empty ? "<<empty(top)<<"\n";
    cout<<"Delete top item : "<<pop(top)<<" deleted";

    return 0;
}