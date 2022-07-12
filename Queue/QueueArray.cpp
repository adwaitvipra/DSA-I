#include <iostream>

using namespace std;

class Queue
{
private:
    int size;
    int front;
    int rear;
    int *Q;

public:
    Queue()
    {
        front = rear = -1;
        size = 10;
        Q = new int[size];
    };
    Queue(int);
    ~Queue();
    int IsEmpty();
    int IsFull();
    void enqueue(int);
    int dequeue();
    void Display();
};

Queue::Queue(int size)
{
    this->size = size;
    front = rear = -1;
    Q = new int[this->size];
}

Queue::~Queue()
{
    delete[] Q;
}
int Queue::IsEmpty()
{
    if (front == rear)
        return 1;
    return 0;
}
int Queue::IsFull()
{
    if (rear == size - 1)
        return 1;
    return 0;
}
void Queue::Display()
{
    int i;
    if (IsEmpty())
        printf("Queue Underflow!\n");
    else
    {
        for (i = front + 1; i <= rear; i++)
            printf("%d ", Q[i]);
    }
    printf("\n");
    return;
}
void Queue::enqueue(int x)
{
    if (IsFull())
    {
        printf("Queue Overflow!\n");
        return;
    }
    rear++;
    Q[rear] = x;
    return;
}
int Queue::dequeue()
{
    int x = -1;
    if (IsEmpty())
        printf("Queue Underflow!\n");
    else
    {
        front++;
        x = Q[front];
    }
    return x;
}
int main(int argc, char const *argv[])
{
    Queue q(10);

    return 0;
}
