#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node
{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third = NULL, *last = NULL; // global ptr

struct Node *Create(struct Node *head, int A[], int n)
{
    struct Node *t, *last;
    int i;
    head = (struct Node *)malloc(sizeof(struct Node));
    head->data = A[0];
    head->next = NULL;
    last = head;
    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
    return head;
}
void IDisplay(struct Node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void RDisplay(struct Node *p)
{
    if (p != NULL)
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
}
int ICount(struct Node *p)
{
    int cnt = 0;
    while (p)
    {
        cnt++;
        p = p->next;
    }
    return cnt;
}

int RCount(struct Node *p)
{
    if (p != NULL)
        return RCount(p->next) + 1;
    else
        return 0;
}
int ISum(struct Node *p)
{
    int i, s = 0;
    while (p)
    {
        s += p->data;
        p = p->next;
    }
    return s;
}
int RSum(struct Node *p)
{
    if (!p)
        return 0;
    return RSum(p->next) + p->data;
}
int IMax(struct Node *p)
{
    int max = INT_MIN;
    while (p)
    {
        if (p->data > max)
            max = p->data;
        p = p->next;
    }
    return max;
}
int RMax(struct Node *p)
{
    int x = 0;
    if (!p)
        return INT_MIN;
    else
    {
        x = RMax(p->next);
        if (x > p->data)
        {
            return x;
        }
        else
            return p->data;
    }
}
int RMaxIm(struct Node *p)
{
    int x = 0;
    if (!p)
        return INT_MIN;
    x = RMaxIm(p->next);
    return x > p->data ? x : p->data;
}
struct Node *ILinearSearch(struct Node *p, int key)
{
    while (p)
    {
        if (p->data == key)
            return p; // return address of node
        p = p->next;
    }
    return NULL;
}
struct Node *RLinearSearch(struct Node *p, int key)
{
    if (!p)
        return NULL;
    if (key == p->data)
        return p;
    return RLinearSearch(p->next, key);
}
struct Node *ILinearSearchMove2Front(struct Node *p, int key)
{
    struct Node *q = NULL; // tail ptr
    while (p)
    {
        if (key == p->data)
        {
            q->next = p->next;
            p->next = first;
            first = p;
            return p;
        }
        q = p;
        p = p->next;
    }
    return NULL;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    if (index < 0 || index > ICount(p)) // check if index is valid or not
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        t->next = first;
        first = t;
    }
    else
    {
        for (int i = 0; (i < index - 1 /*&& p*/); i++) // move p until it points to node at index
            p = p->next;
        t->next = p->next; // if(p) and above condtion can be used when there is no index check at start
        p->next = t;
    }
}
void Append(int x) // node will be surely inserted
{
    struct Node *t = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;
    if (first == NULL)
    {
        first = last = t;
    }
    else
    {
        last->next = t;
        last = t;
    }
}
void InsertSorted(struct Node *p, int x)
{
    struct Node *t, *q = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = NULL;

    if (!first) // check if list is empty then make first point to t
    {
        first = t;
    }
    else
    {
        while (p && p->data < x) // move p until data is less than x and null is not reached
        {
            q = p;
            p = p->next;
        }
        if (p == first) // if data is smaller than first node
        {
            t->next = first;
            first = t;
        }
        else
        {
            t->next = p;
            q->next = t;
        }
    }
}
int Delete(struct Node *p, int index)
{
    struct Node *q = NULL;
    int x = -1, i;
    if (index < 1 || index > ICount(p)) // is index valid
    {
        return x;
    }
    // If node to be deleted is first
    if (index == 1)
    {
        q = first;
        first = first->next;
        x = q->data;
        free(q);
        return x;
    }
    else // Any other node
    {
        for (i = 0; i < index - 1; i++) // move p on node with given index
        {
            q = p; // q is a tail ptr
            p = p->next;
        }
        q->next = p->next; // link q with node after p
        x = p->data;
        free(p);
        return x;
    }
}
int IsSorted(struct Node *p)
{
    int x = INT_MIN;
    while (p)
    {
        if (p->data < x)
            return 0;
        x = p->data;
        p = p->next;
    }
    return 1;
}
void RemoveDuplicates(struct Node *p) // p is tail ptr
{
    struct Node *q = p->next;
    while (q)
    {
        if (p->data != q->data) // different data, go further
        {
            p = q;
            q = q->next;
        }
        else // two nodes have same data
        {
            p->next = q->next;
            free(q);
            q = p->next;
        }
    }
}
void ReverseElements(struct Node *p)
{
    int i = 0, *A;
    struct Node *q = NULL;
    A = (int *)malloc(sizeof(int) * ICount(p));
    q = p;
    while (q) // copy data of node to arr
    {
        A[i] = q->data;
        q = q->next;
        i++;
    }
    q = p;    // make q point to start again
    i--;      // decrement i to keep it on last ele
    while (q) // copy ele of arr to data of node
    {
        q->data = A[i];
        q = q->next;
        i--;
    }
}
void ReverseLinksSlidingPtrs(struct Node *p)
{
    struct Node *q, *r;
    r = q = NULL;
    while (p)
    {
        r = q;
        q = p;
        p = p->next;
        q->next = r; // reverse link of node with q as ptr, q will reverse link of last node
    }
    first = q; // make first to point at q
}
void ReverseRecursion(struct Node *q, struct Node *p) // pass q as NULL and p as first
{
    if (p)
    {
        ReverseRecursion(p, p->next); // move q to p and p to next node
        p->next = q;                  // reverse link of p wtih q
    }
    else
        first = q; // make q as first since q will be on the last node, which will become first node
}
void Concatanate(struct Node *p, struct Node *q)
{
    third = p;              // make third ptr point on p
    while (p->next != NULL) // move p until its next is not null
    {
        p = p->next;
    }
    p->next = q;
    q = NULL;
}
void Merge(struct Node *p, struct Node *q) // pass head ptr of lists to be merged
{                                          // both list must be sorted
    struct Node *last;
    if (p->data < q->data)
    {
        third = last = p;
        p = p->next;
        last->next = NULL;
    }
    else
    {
        third = last = q;
        q = q->next;
        last->next = NULL;
    }
    while (p && q) // move p and q until one of them reaches null
    {
        if (p->data < q->data)
        {
            last->next = p;
            last = p;
            p = p->next;
            last->next = NULL;
        }
        else
        {
            last->next = q;
            last = q;
            q = q->next;
            last->next = NULL;
        }
    }
    if (p)
        last->next = p;
    else
        last->next = q;
}
int IsLoop(struct Node *f)
{
    struct Node *p, *q;
    p = q = f;
    do
    {
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    } while (p && q && p != q);
    if (p == q)
        return 1;
    return 0;
}
void MiddleNode(struct Node *p)
{
    struct Node *q;
    q = p;
    while (q)
    {
        q = q->next;
        if (q)
            q = q->next;
        if (q)
            p = p->next;
    }
    printf("%d ", p->data);
}
void IntersectionNode(struct Node *p, struct Node *q) 
// store address of all nodes of both lists in two stacks then pop values if they are same, 
//retain copy of last popped node, return that node or print data of intersection node
{
    struct Node *r;
    r = p;
    while (r)
    {
        push(&stk1, r);
    }
    r = q;
    while (r)
    {
        push(&stk2, r);
    }
    while (peek(stk1) == peek(stk2))
    {
        r = pop(&stk1);
        pop(stk2);
    }
}
int main(int argc, char const *argv[])
{
    int A[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
    int B[] = {1, 3, 5};
    first = Create(first, A, 10);
    second = Create(first, B, 3);
    struct Node *p = first, *q = second;
    while (q->next)
        q = q->next;
    while (p->data != 10)
        p = p->next;
    q->next = p;
    IDisplay(first);
    IDisplay(second);
    return 0;
}
