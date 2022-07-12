#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} * Head;
void Create(int A[], int n)
{
    int i;
    struct Node *t, *last;
    Head = (struct Node *)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}
void IDisplay(struct Node *h)
{
    do
    {
        printf("%d ", h->data);
        h = h->next;
    } while (h != Head);
    printf("\n");
}
void RDisplay(struct Node *h) // maintain a static flag to check if ptr comes second time on head node
{
    static int flag = 0;
    if (h != Head || flag == 0)
    {
        flag = 1;
        printf("%d ", h->data);
        RDisplay(h->next);
    }
    flag = 0;
}
int Length(struct Node *h)
{
    int l = 0;
    do
    {
        l++;
        h = h->next;
    } while (h != Head);
    return l;
}
void Insert(struct Node *h, int index, int x)
{
    int i;
    struct Node *t, *p;
    if (index < 0 || index > Length(h))
        return;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    if (index == 0)
    {
        if (h == NULL)
        {
            t->next = t;
            Head = t;
        }
        else
        {

            while (h->next != Head)
            {
                h = h->next;
            }
            t->next = Head;
            h->next = t;
            Head = t; // moving head on t
        }
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            h = h->next;
        t->next = h->next;
        h->next = t;
    }
}
int Delete(struct Node *h, int index)
{
    int i, x;
    struct Node *q;
    // check for valid index
    if (index < 1 || index > Length(h))
        return -1;
    if (index == 1)
    {
        while (h->next != Head)
            h = h->next;
        x = Head->data;
        if (Head == h)
        {
            free(h);
            Head = NULL;
        }
        else
        {
            h->next = Head->next;
            free(Head);
            Head = h->next;
        }
    }
    else
    {
        for (i = 0; i < index - 2; i++) //move h to second last node of index node and assign q to node at index
        {
            h=h->next;
        }
        q=h->next;
        h->next=q->next;
        x=q->data;
        free(q);
    }
    return x;
}

int main(int argc, char const *argv[])
{
    int A[] = {1};
    Create(A, 1);
    return 0;
}
