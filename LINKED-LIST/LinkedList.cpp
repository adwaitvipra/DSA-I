#include <iostream>
using namespace std;
template <class T>
class Node
{
public:
    T data;
    Node *next;
};
template <class T>
class LinkedList
{
private:
    Node<T> *first;

public:
    LinkedList() { first = NULL; }
    LinkedList(T A[], int n);
    ~LinkedList();
    void Display();
    void Insert(int index, T x);
    T Delete(int index);
    int Length();
};
template <class T>
LinkedList<T>::LinkedList(T A[], int n)
{
    Node<T> *t, *last;
    first = new Node<T>;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (int i = 1; i < n; i++)
    {
        t = new Node<T>;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
template <class T>
LinkedList<T>::~LinkedList()
{
    Node<T> *p = NULL, *q = first;
    while (q)
    {
        p = q;
        q = q->next;
        delete p;
    }
}
template <class T>
int LinkedList<T>::Length()
{
    int i = 0;
    Node<T> *p = first;
    while (p)
    {
        i++;
        p = p->next;
    }
    return i;
}
template <class T>
void LinkedList<T>::Display()
{
    Node<T> *p = first;
    while (p)
    {
        cout << p->data << " ";
        p = p->next;
    }
    printf("\n");
}
template <class T>
void LinkedList<T>::Insert(int index, T x)
{
    Node<T> *p = first;
    Node<T> *t = NULL;
    if (index < 0 || index > Length())
        return;
    t = new Node<T>;
    t->data = x;
    t->next = NULL;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; i < index - 1; i++) // move p ahead index-1 times
            p = p->next;
        t->next = p->next;
        p->next = t;
    }
}
template <class T>
T LinkedList<T>::Delete(int index) // assuming index starts form 1;
{
    Node<T> *p = first;
    Node<T> *q = NULL;
    T x;
    if (index < 1 || index > Length())
        return -1;
    if (index == 1)
    {
        x = p->data;
        first = first->next;
        free(p);
        return x;
    }
    else
    {
        for (int i = 0; i < index - 1; i++)
        {
            q = p;
            p = p->next;
        }
        x = p->data;
        q->next = p->next;
        free(p);
        return x;
    }
}
int main(int argc, char const *argv[])
{
    float A[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
    LinkedList<float> l(A, 10);
    l.Display();
    l.Insert(0, 0.5);
    l.Display();
    cout << l.Length() << endl;
    l.Delete(5);
    l.Delete(1);
    l.Display();
    return 0;
}