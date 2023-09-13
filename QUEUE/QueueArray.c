#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queue
{
	int *Q;
	int size;
	int front;
	int rear;
};

bool IsValid (struct Queue queue)
{
	bool flag = false;

	if (queue.Q && (queue.size >= 0))
		flag = true;

	return flag;
}

bool IsEmpty (struct Queue queue)
{
	bool flag = false;

	if (IsValid (queue))
		if (queue.front == queue.rear)
			flag = true;

	return flag;
}

bool IsFull (struct Queue queue)
{
	bool flag = false;

	if (IsValid (queue))
		if (queue.rear == (queue.size - 1))
			flag = true;

	return flag;
}

void Display (struct Queue queue)
{
	if (IsValid (queue) && !IsEmpty (queue))
	{
		for (int idx = (queue.front + 1); idx <= queue.rear; idx++)
			printf ("%d ", queue.Q[idx]);
		printf ("\n");
	}

	return ;
}

struct Queue *Create (struct Queue **queue, int size)
{
	struct Queue *new = NULL;

	if ((size > 0) && (new = (struct Queue *) malloc (sizeof (struct Queue))))
	{
		if ((new->Q = (int *) malloc (size * sizeof (int))))
		{
			new->size = size;
			new->front = new->rear = -1;
		}
		else
		{
			free (new);
			new = NULL;
		}

		if (queue)
		{
			*queue = new;
		}
	}

	return new;
}

bool Enqueue (struct Queue *queue, int val)
{
	bool flag = false;

	if (queue && IsValid (*queue) && !IsFull (*queue))
	{
		flag = true;

		queue->rear += 1;
		queue->Q[queue->rear] = val;
	}

	return flag;
}

int Dequeue (struct Queue *queue)
{
	int ret = INT_MIN;

	if (queue && IsValid (*queue) && !IsEmpty (*queue))
	{
		queue->front += 1;
		ret = queue->Q[queue->front];
	}

	return ret;
}

void Delete (struct Queue **queue)
{
	if (queue && *queue)
	{
		if ((*queue)->Q)
			free ((*queue)->Q);

		free (*queue);

		*queue = NULL;
	}

	return ;
}

int main (const int argc, const char *argv[])
{
	struct Queue *queue = NULL;

	Create (&queue, 10);

	for (int i = 0, val = 1; i < 10; i++, val *= 10)
		Enqueue (queue, val);

	Display (*queue);

	while (queue && IsValid (*queue) && !IsEmpty(*queue))
		printf ("%d ", Dequeue (queue));
	printf ("\n");

	Display (*queue);

	Delete (&queue);

	return 0;
}
