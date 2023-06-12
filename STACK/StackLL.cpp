#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
};
class Stack
{
private:
    Node *top;

public:
    Stack() { top = NULL; }
    void Display();
    void push(int);
    int pop();
    int peek(int);
    int StackTop();
    int IsEmpty();
    int IsFull();
    int Length();
};
int Stack::IsEmpty()
{
    if (!top)
        return 1;
    return 0;
}
int Stack::IsFull()
{
    int r = 0;
    Node *t;
    t = new Node;
    r = t ? 0 : 1;
    delete t;
    return r;
}
int Stack::Length()
{
    Node *t = top;
    int len = 0;
    while (t)
    {
        len++;
        t = t->next;
    }
    return len;
}
void Stack::Display()
{
    Node *p = top;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}
void Stack::push(int x)
{
    Node *t = NULL;
    t = new Node;
    if (IsFull())
        cout << "Stack Overflow!\n";
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}
int Stack::pop()
{
    int x = -1;
    if (IsEmpty())
        return x;
    else
    {
        Node *t = top;
        x = t->data;
        top = top->next;
        delete t;
        return x;
    }
}
int Stack::peek(int index) // valid index must be passed
{
    int i, x = -1;
    if (index < 1 || index > Length())
        return x;
    Node *p = top;
    if (IsEmpty())
        return x;
    for (i = 0; i < index - 1; i++)
        p = p->next;
    return p->data;
}
int Stack::StackTop()
{
    if (!IsEmpty())
        return top->data;
    return -1;
}
int main()
{
    Stack t;
    cout << "Empty";
    cout << t.IsEmpty() << endl;
    cout << "Full";
    cout << t.IsFull() << endl;
    t.push(10);
    t.push(20);
    t.push(30);
    t.push(40);
    t.push(50);
    t.push(60);
    t.push(70);
    t.Display();
    cout << "StackTop";
    cout << t.StackTop() << endl;
    cout << "peek" << t.peek(5) << endl;
    cout << "peek" << t.peek(4) << endl;
    cout << "peek" << t.peek(3) << endl;
    cout << "peek" << t.peek(2) << endl;
    cout << "peek" << t.peek(1) << endl;
    cout << "peek" << t.peek(0) << endl;
    cout << "peek" << t.peek(-1) << endl;
    cout << "peek" << t.peek(50) << endl;
    cout << "pop" << t.pop() << endl;
    cout << "pop" << t.pop() << endl;
    t.Display();
    cout << "pop" << t.pop() << endl;
    cout << "pop" << t.pop() << endl;
    cout << "pop" << t.pop() << endl;
    t.Display();
    cout << "pop" << t.pop() << endl;
    cout << "pop" << t.pop() << endl;
    t.Display();
    cout << "pop" << t.pop() << endl;
    cout << "pop" << t.pop() << endl;
    t.Display();
    cout << "pop" << t.pop() << endl;
    cout << "pop" << t.pop() << endl;
    cout << "pop" << t.pop() << endl;
    t.Display();
    return 0;
}
