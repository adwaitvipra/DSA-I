#include <stdio.h>
#include <stdlib.h>

struct Queue
{
    int size;
    int front;
    int rear;
    int *Q;
};
void Create(struct Queue *q, int s)
{
    q->size = s;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(sizeof(int) * q->size);
    return;
}
int IsEmpty(struct Queue q)
{
    if (q.front == q.rear)
        return 1;
    return 0;
}
int IsFull(struct Queue q)
{
    if (q.rear == q.size - 1)
        return 1;
    return 0;
}
void Display(struct Queue q)
{
    int i;
    if (IsEmpty(q))
    {
        printf("Queue Underflow!");
    }
    for (i = q.front + 1; i <= q.rear; i++)
        printf("%d ", q.Q[i]);
    printf("\n");
    return;
}
void enqueue(struct Queue *q, int x)
{
    if (IsFull(*q))
    {
        printf("Queue Overflow!\n");
        return;
    }
    q->rear++;
    q->Q[q->rear] = x;
    return;
}
int dequeue(struct Queue *q)
{
    int x = -1;
    if (IsEmpty(*q))
    {
        printf("Queue Underflow!");
        return x;
    }
    q->front++;
    x = q->Q[q->front];
    return x;
}
int main(int argc, char const *argv[])
{
    struct Queue q;
    Create(&q, 10);
    enqueue(&q, 10);
    enqueue(&q, 100);
    enqueue(&q, 1000);
    enqueue(&q, 10000);
    enqueue(&q, 100000);
    Display(q);
    while (!IsEmpty(q))
    {
        printf("%d ", dequeue(&q));
    }
    printf("\n");
    Display(q);
    return 0;
}
