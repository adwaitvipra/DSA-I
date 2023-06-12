#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;
int IsEmpty()
{
    if (front == NULL)
        return 1;
    return 0;
}
int IsFull()
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (!t)
        return 1;
    else
        return 0;
}

void enqueue(int x)
{
    struct Node *t;
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Queue Overflow!\n");
        return;
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if (front == NULL)
            front = rear = t;
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}
int dequeue()
{
    int x = -1;
    struct Node *p;
    if (front == NULL)
    {
        printf("Queue Underflow!\n");
        return x;
    }
    else
    {
        p = front;
        front = front->next;
        x = p->data;
        free(p);
    }
    return x;
}
void Display()
{
    struct Node *p;
    p = front;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int main(int argc, char const *argv[])
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    Display();
    enqueue(40);
    enqueue(50);
    Display();
    printf("%d is deleted\n", dequeue());
    printf("%d is deleted\n", dequeue());
    Display();
    printf("%d is deleted\n", dequeue());
    printf("%d is deleted\n", dequeue());
    Display();
    return 0;
}
