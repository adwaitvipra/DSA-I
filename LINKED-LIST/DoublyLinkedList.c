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
	struct Node *new = NULL, *head = NULL, *tail = NULL;

	if (arr && (n > 0)
			&& (new = (struct Node *) malloc (sizeof (struct Node))))
	{
		new->data = arr[0];
		new->prev = new->next = NULL;

		head = new;
		tail = new;

		for (int cnt = 1; cnt < n; cnt++)
		{
			if ((new = (struct Node *) malloc (sizeof (struct Node))))
			{
				new->data = arr[cnt];
				new->next = NULL;

				new->prev = tail;
				tail->next = new;

				tail = new;
			}
		}
	}

	return head;
}

void IDisplay (struct Node *lst)
{
	while (lst)
	{
		printf ("%d ", lst->data);
		lst = lst->next;
	}
	printf ("\n");

	return ;
}

void RDisplay (struct Node *lst)
{
	if (!lst)
		printf ("\n");
	else
	{
		printf ("%d ", lst->data);
		RDisplay (lst->next);
	}

	return ;
}

void ReverseDisplay (struct Node *lst)
{
	if (lst)
	{
		while (lst->next)
			lst = lst->next;

		while (lst)
		{
			printf ("%d ", lst->data);
			lst = lst->prev;
		}
		printf ("\n");
	}

	return ;
}

int Length (struct Node *lst)
{
	int len = INT_MIN;

	if (lst)
	{
		len = 0;

		while (lst)
		{
			len += 1;
			lst = lst->next;
		}
	}

	return len;
}

struct Node *Insert (struct Node *lst, int idx, int val)
{
	struct Node *new = NULL, *head = NULL;

	if ((idx >= 0) && (idx <= Length (lst))
			&& (new = (struct Node *) malloc (sizeof (struct Node))))
	{
		new->data = val;
		new->prev = new->next = NULL;

		if (!lst)
			head = new;
		else
		{
			if (!idx)
			{
				head = new;
				
				new->next = lst;
				lst->prev = new;
			}
			else
			{
				head = lst;

				for (int jmp = 0; jmp < (idx - 1); jmp++)
					lst = lst->next;

				new->prev = lst;
				new->next = lst->next;

				lst->next->prev = new;
				lst->next = new;
			}
		}
	}

	return head;
}

struct Node *Delete (struct Node *lst, int idx)
{
	struct Node *head = NULL, *tmp = NULL;

	if (lst && (idx >= 0) && (idx < Length (lst)))
	{
		if (!idx)
		{
			tmp = lst;

			head = lst->next;
			head->prev = NULL;
		}
		else
		{
			head = lst;

			for (int jmp = 0; jmp < idx; jmp++)
				lst = lst->next;

			tmp = lst;

			lst->prev->next = lst->next;
			lst->next->prev = lst->prev;
		}

		free (tmp);
	}

	return head;
}

struct Node *Reverse (struct Node *lst)
{
	struct Node *tmp = NULL, *head = NULL;

	while (lst)
	{
		tmp = lst->next;

		lst->next = lst->prev;
		lst->prev = tmp;

		lst = lst->prev;

		if (lst && !(lst->next))
		{
			head = lst;
		}
	}

	return head;
}

int main (const int argc, const char *argv[])
{
	struct Node *list = NULL;
	int arr[] = {1, 2, 3, 4, 5, 6};

	list = Create (arr, sizeof(arr) / sizeof(int));
	RDisplay (list);

	list = Reverse (list);
	RDisplay (list);

	return 0;
}
