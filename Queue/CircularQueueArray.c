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
    q->front = q->rear = 0;
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
    if ((q.rear + 1) % q.size == q.front)
        return 1;
    return 0;
}
void Display(struct Queue q)
{
    int i = q.front + 1;
    if (IsEmpty(q))
    {
        printf("Queue Underflow!");
    }
    do
    {
        printf("%d ", q.Q[i]);
        i = (i + 1) % q.size; //move i circularly 
    } while (i!=(q.rear + 1) % q.size);//move i circularly unless is not equal to r + 1, that is print data
    // on r but don't go in loop if  i is equal to rear + 1
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
    q->rear = (q->rear + 1) % q->size;
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
    q->front = (q->front + 1) % q->size;
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
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    enqueue(&q, 10);
    enqueue(&q, 100);
    enqueue(&q, 1000);
    enqueue(&q, 10000);
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("%d ", dequeue(&q));
    printf("\n");
    Display(q);
    return 0;
}
