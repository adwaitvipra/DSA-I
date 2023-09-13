#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Queue
{
	int size;

	struct Node *front;
	struct Node *rear;
};

struct Node
{
	int data;
	struct Node *next;
};

bool IsEmpty (struct Queue queue)
{
	bool flag = true;

	if (queue.front && (queue.size > 0))
		flag = false;

	return flag;
}

bool IsFull ()
{
	bool flag = true;
	struct Node *tmp = NULL;

	if ((tmp = (struct Node *) malloc (sizeof (struct Node))))
	{
		flag = false;
		free (tmp);
	}

	return flag;
}

struct Queue *Create (struct Queue **queue)
{
	struct Queue *new = NULL;

	if ((new = (struct Queue *) malloc (sizeof (struct Queue))))
	{
		new->size = 0;

		new->front = new->rear = NULL;

		if (queue)
		{
			*queue = new;
		}
	}

	return new;
}

void Enqueue (struct Queue *queue, int val)
{
	struct Node *new = NULL;

	if (queue && !IsFull ()
			&& (new = (struct Node *) malloc (sizeof (struct Node))))
	{
		new->data = val;
		new->next = NULL;

		if (!queue->front)
		{
			queue->size = 1;

			queue->front = queue->rear = new;
		}
		else
		{
			queue->size += 1;

			queue->rear->next  = new;
			queue->rear = new;
		}
	}

	return ;
}

int Dequeue (struct Queue *queue)
{
	int ret = INT_MIN;
	struct Node *tmp = NULL;

	if (queue && !IsEmpty (*queue))
	{
		queue->size -= 1;

		tmp = queue->front;
		ret = tmp->data;

		queue->front = queue->front->next;

		free (tmp);
	}

	return ret;
}

void Display (struct Queue queue)
{
	struct Node *ptr = NULL;

	if (!IsEmpty (queue))
	{
		ptr = queue.front;

		while (ptr)
		{
			printf ("%d ", ptr->data);
			ptr = ptr->next;
		}
		printf ("\n");
	}

	return ;
}

void Delete (struct Queue **queue)
{
	if (queue && *queue)
	{
		while ((*queue)->front && ((*queue)->size > 0))
			Dequeue (*queue);

		free (*queue);

		*queue = NULL;
	}

	return ;
}

int main (const int argc, const char *argv[])
{
	struct Queue *queue = NULL;

	Create (&queue);

	Enqueue (queue, 10);
	Enqueue (queue, 20);
	Enqueue (queue, 30);
	Display (*queue);

	Enqueue (queue, 40);
	Enqueue (queue, 50);
	Display (*queue);

	printf ("%d is deleted\n", Dequeue (queue));
	printf ("%d is deleted\n", Dequeue (queue));
	Display (*queue);

	printf ("%d is deleted\n", Dequeue (queue));
	printf ("%d is deleted\n", Dequeue (queue));
	Display (*queue);

	Delete (&queue);

	return 0;
}
