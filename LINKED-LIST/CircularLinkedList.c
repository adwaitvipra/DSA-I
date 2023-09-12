#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *Create (int arr[], int n)
{
	struct Node *new = NULL, *head = NULL, *tail = NULL;

	if (arr && (n > 0) && (new = (struct Node *) malloc (sizeof (struct Node))))
	{
		new->data = arr[0];
		new->next = NULL;

		head = new;
		tail = new;

		for (int idx = 1; idx < n; idx++)
		{
			if ((new = (struct Node *) malloc (sizeof (struct Node))))
			{
				new->data = arr[idx];
				new->next = NULL;

				tail->next = new;
				tail = new;
			}
		}

		tail->next = head;
	}

	return head;
}

void IDisplay (struct Node *lst)
{
	struct Node *ptr = NULL;

	if (lst)
	{
		ptr = lst;

		do
		{
			printf ("%d ", ptr->data);
			ptr = ptr->next;

		} while (ptr != lst);

		printf ("\n");
	}

	return ;
}

void RDisplay (struct Node *lst)
{
	static bool flag = false;
	static struct Node *head = NULL;

	if (lst && (lst != head))
	{
		if (!flag)
		{
			flag = true;
			head = lst;
		}

		printf ("%d ", lst->data);
		RDisplay (lst->next);
	}
	else
	{
		flag = false;
		head = NULL;

		printf ("\n");
	}

	return ;
}

int Length (struct Node *lst)
{
	int len = INT_MIN;
	struct Node *ptr = NULL;

	if (lst)
	{
		len = 0;
		ptr = lst;

		do
		{
			len += 1;
			ptr = ptr->next;

		} while (ptr != lst);
	}

	return len;
}

struct Node *Insert (struct Node *lst, int idx, int val)
{
	struct Node *new = NULL, *ptr = NULL, *head = NULL;

	if ((idx >= 0) && (idx <= Length (lst))
			&& (new = (struct Node *) malloc (sizeof (struct Node))))
	{
		new->data = val;
		new->next = NULL;

		if (!lst)
		{
			head = new;
			new->next = new;
		}
		else
		{
			ptr = lst;

			if (!idx)
			{
				do
				{
					ptr = ptr->next;

				} while (ptr->next != lst);

				new->next = lst;
				ptr->next = new;

				head = new;
			}
			else
			{
				for (int jmp = 0; jmp < (idx - 1); jmp++)
					ptr = ptr->next;

				new->next = ptr->next;
				ptr->next = new;

				head = lst;
			}
		}

	}

	return head;
}

struct Node *Delete (struct Node *lst, int idx)
{
	struct Node *tmp = NULL, *ptr = NULL, *head = NULL;

	if (lst && (idx >= 0) && (idx < Length (lst)))
	{
		ptr = lst;

		if (!idx)
		{
			do
			{
				ptr = ptr->next;

			} while (ptr->next != lst);

			tmp = lst;

			ptr->next = lst->next;
			head = lst->next;

			free (tmp);
		}
		else
		{
			head = lst;

			for (int jmp = 0; jmp < (idx - 1); jmp++)
				ptr = ptr->next;

			tmp = ptr->next;
			ptr->next = tmp->next;

			free (tmp);
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

	list = Delete (list, 0);
	list = Delete (list, 2);
	RDisplay (list);

	return 0;
}
