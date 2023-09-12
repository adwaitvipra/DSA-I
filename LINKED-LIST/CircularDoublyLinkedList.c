#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	struct Node *prev;
	int data;
	struct Node *next;
};

struct Node *Create (int arr[], int n)
{
}

{
	struct Node *t, *last;
	int i;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = A[0];
	t->next = t->prev = NULL;
	Head = t;
	last = t;
	for (i = 1; i < n; i++)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = A[i];

		Head->prev = t;
		last->next = t;

		t->prev = last;
		t->next = Head;

		last = t;
	}
}

void Display (struct Node *lst)
{
}

{
	do
	{
		printf("%d ", p->data);
		p = p->next;
	} while (p != Head);
	printf("\n");
}

int Length (struct Node *lst)
{
}

{
	int len = 0;
	do
	{
		len++;
		p = p->next;
	} while (p != Head);
	return len;
}

void Insert (struct Node *lst, int idx, int val)
{

}

{
	int i;
	struct Node *t;
	if (Head == NULL && index == 0)
	{
		t = (struct Node *)malloc(sizeof(struct Node));
		t->data = x;
		t->prev = t->next = t;
		Head = t;
		return;
	}
	if (index < 0 || index > Length(p)) // check if index is valid or not
		return;
	t = (struct Node *)malloc(sizeof(struct Node));
	t->data = x;
	t->prev = t->next = NULL;
	if (index == 0) // insert before head and change the head
	{
		t->next = Head;
		t->prev = Head->prev;
		if (Head->prev) // check if there is Head's prev is not null
			Head->prev->next = t;
		Head = t;
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		t->prev = p;
		t->next = p->next;
		p->next->prev = t;
		p->next = t;
	}
}

struct Node *Delete (struct Node *lst, int idx)
{

}

{
	int x = -1, i;
	if (index < 1 || index > Length(p)) // check for valid index
		return x;
	if (index == 1) // Delete Head
	{
		x = p->data;
		if (p->next) // if next node is not null move head
		{
			Head = Head->next;
			Head->prev = p->prev;
			p->prev->next = Head;
		}
		else // next of head is null that is head must be made null after deleting the node
			Head = NULL;
		free(p);
	}
	else
	{
		for (i = 0; i < index - 1; i++)
			p = p->next;
		p->prev->next=p->next;
		p->next->prev=p->prev;
		x=p->data;
		free(p);
	}
	return x;
}

int main (const int argc, const char *argv[])
{
	struct Node *list = NULL;
	int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

	Create (arr, 10);
	Display(list);

	Delete (list, 1);
	Display (list);

	Delete (list, 9);
	Display (list);

	Delete (list, 4);
	Display (list);

	return 0;
}
