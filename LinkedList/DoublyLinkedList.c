#include <stdio.h>
#include <stdlib.h>
struct Node
{
    struct Node *prev;
    int data;
    struct Node *next;
} *first = NULL;
void Create(int A[], int n)
{
    int i;
    struct Node *t = NULL, *last = NULL;
    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = A[0];
    t->prev = NULL;
    first = t;
    last = t;

    for (i = 1; i < n; i++)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = A[i];
        t->prev = last;
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void IDisplay(struct Node *p)
{
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
void RDisplay(struct Node *p)
{
    if (!p)
        return;
    else
    {
        printf("%d ", p->data);
        RDisplay(p->next);
    }
    printf("\n");
}
void ReverseDisplay(struct Node *p)
{
    while (p->next)
    {
        p = p->next;
    }
    while (p)
    {
        printf("%d ", p->data);
        p = p->prev;
    }
    printf("\n");
}

int Length(struct Node *p)
{
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
void Insert(struct Node *p, int index, int x)
{
    struct Node *t;
    int i;
    if (first == NULL && index == 0)
    {
        t = (struct Node *)malloc(sizeof(struct Node));
        t->data = x;
        t->prev = t->next = NULL;
        first = t;
        return;
    }
    if (index < 0 || index > Length(p))
        return;

    t = (struct Node *)malloc(sizeof(struct Node));
    t->data = x;
    t->next = t->prev = NULL;

    if (index == 0)
    {
        t->next = p;
        p->prev = t;
        first = t;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        t->prev = p;
        t->next = p->next;
        if (p->next)
            p->next->prev = t;
        p->next = t;
    }
}
int Delete(struct Node *p, int index)
{
    int i, x = -1;
    if (index < 1 || index > Length(p))
        return x;
    if (index == 1)
    {
        first = first->next;
        if (first)
            first->prev = NULL;
        x = p->data;
        free(p);
        p = NULL;
    }
    else
    {
        for (i = 0; i < index - 1; i++)
            p = p->next;
        p->prev->next = p->next;
        if (p->next)
            p->next->prev = p->prev;
        x = p->data;
        free(p);
        p = NULL;
    }
    return x;
}
void Reverse(struct Node *p)
{
    struct Node *temp;
    while (p)
    {
        temp = p->next;
        p->next = p->prev;
        p->prev = temp;
        p = p->prev;       // as next is now in prev
        if (p && !p->next) // check if p is not null and p->next is null
            first = p;
    }
}
int main(int argc, char const *argv[])
{
    int A[] = {1, 2, 3, 4, 5, 6};
    Create(A, sizeof(A) / sizeof(int));
    RDisplay(first);
    printf("\n");
    Reverse(first);
    RDisplay(first);

    return 0;
}
