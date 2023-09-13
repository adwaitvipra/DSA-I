#include <iostream>
#include <climits>

#define SIZE 128

using namespace std;

class Queue
{
	private:
		int *Q = nullptr;
		int size;
		int front;
		int rear;

	public:
		Queue ()
		{
			size = SIZE;
			front = rear = -1;

			Q = new int [size];
		};

		Queue (int);
		~Queue ();

		bool IsEmpty ();
		bool IsFull ();

		void Display ();

		void Enqueue (int);
		int Dequeue ();
};

Queue :: Queue (int size)
{
	if (size > 0)
	{
		this->size = size;
		front = rear = -1;

		Q = new int [this->size];
	}

	return ;
}

Queue :: ~Queue ()
{
	if (Q)
		delete [] Q;

	return ;
}

bool Queue :: IsEmpty ()
{
	bool flag = false;

	if (Q && (size >= 0))
		if (front == rear)
			flag = true;

	return flag;
}

bool Queue :: IsFull ()
{
	bool flag = false;

	if (Q && (size >= 0))
		if (rear == (size - 1))
			flag = true;

	return flag;
}

void Queue :: Display ()
{
	if (Q && (size >= 0) && !IsEmpty ())
	{
		for (int idx = (front + 1); idx <= rear; idx++)
			printf ("%d ", Q[idx]);
		printf ("\n");
	}

	return ;
}

void Queue :: Enqueue (int val)
{
	if (Q && (size >= 0) && !IsFull ())
	{
		rear += 1;
		Q[rear] = val;
	}

	return ;
}

int Queue :: Dequeue ()
{
	int ret = INT_MIN;

	if (Q && (size >= 0) && !IsEmpty ())
	{
		front += 1;
		ret = Q[front];
	}

	return ret;
}

int main (const int argc, const char *argv[])
{
	Queue queue (SIZE);

	for (int i = 0; i < 10; i++)
		queue.Enqueue (i);

	queue.Display ();

	return 0;
}
