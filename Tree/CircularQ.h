struct Node
{
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root=NULL;
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void createQ(struct Queue *q, int s)
{
    q->size = s;
    q->front = q->rear = 0;
    q->Q = (struct Node **)malloc(sizeof(struct Node *) * q->size);
    return;
}
int IsEmptyQ(struct Queue q)
{
    if (q.front == q.rear)
        return 1;
    return 0;
}
int IsFullQ(struct Queue q)
{
    if ((q.rear + 1) % q.size == q.front)
        return 1;
    return 0;
}
void enqueue(struct Queue *q,struct Node* x)
{
    if (IsFullQ(*q))
    {
        printf("Queue Overflow!\n");
        return;
    }
    q->rear = (q->rear + 1) % q->size;
    q->Q[q->rear] = x;
    return;
}
struct Node * dequeue(struct Queue *q)
{
    struct Node* x = NULL;
    if (IsEmptyQ(*q))
    {
        printf("Queue Underflow!\n");
        return x;
    }
    q->front = (q->front + 1) % q->size;
    x = q->Q[q->front];
    return x;
}