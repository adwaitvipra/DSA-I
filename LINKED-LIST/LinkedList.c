#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

struct Node
{
	int data;
	struct Node *next;
};

struct Node *Create (struct Node **list, int A[], int n)
{
	struct Node *head = NULL, *tmp = NULL, *prev = NULL;

	if (A && (n > 0) && (head = (struct Node *) malloc (sizeof (struct Node))))
	{
		head->data = A[0];
		head->next = NULL;

		prev = head;

		for (int cnt = 1; cnt < n; cnt++)
		{
			if ((tmp = (struct Node *) malloc (sizeof (struct Node))))
			{
				tmp->data = A[cnt];
				tmp->next = NULL;

				prev->next = tmp;
				prev = tmp;
			}
			else
				printf ("dynamic allocation failed!\n");
		}
	}

	if (list)
		*list = head;

	return head;
}

void IDisplay (struct Node *lst)
{
	while (lst)
	{
		printf ("%d ", lst->data);
		lst = lst->next;
	}
	printf("\n");

	return ;
}

void RDisplay (struct Node *lst)
{
	if (lst)
	{
		printf ("%d ", lst->data);
		RDisplay (lst->next);
	}

	return ;
}

int ICount (struct Node *p)
{
	int cnt = 0;

	while (p)
	{
		cnt++;
		p = p->next;
	}

	return cnt;
}

int RCount (struct Node *p)
{
	if (p)
		return RCount (p->next) + 1;

	return 0;
}

int ISum (struct Node *p)
{
	int s = INT_MIN;

	if (p)
	{
		s = 0;
		while (p)
		{
			s += p->data;
			p = p->next;
		}
	}

	return s;
}

int RSum (struct Node *p)
{
	if (!p)
		return 0;

	return (RSum (p->next) + p->data);
}

int IMax (struct Node *p)
{
	int max = INT_MIN;

	while (p)
	{
		if (p->data > max)
			max = p->data;

		p = p->next;
	}

	return max;
}

int RMax (struct Node *p)
{
	int max = INT_MIN;

	if (p)
	{
		max = RMax (p->next);

		if (max < p->data)
		{
			max = p->data;
		}
	}

	return max;
}

struct Node *ILinearSearch (struct Node *p, int key)
{
	struct Node *ret = NULL;

	while (p)
	{
		if (p->data == key)
		{
			ret = p;
			break;
		}

		p = p->next;
	}

	return ret;
}

struct Node *RLinearSearch (struct Node *p, int key)
{
	struct Node *ret = NULL;

	if (p)
	{
		if (p->data == key)
		{
			ret = p;
		}
		else
		{
			ret = RLinearSearch (p->next, key);
		}
	}

	return ret;
}

struct Node *ILinearSearchMove2Front (struct Node *lst, int key)
{
	struct Node *curr = NULL, *prev = NULL;

	if (lst)
	{
		curr = lst;

		while (curr && (curr->data != key))
		{
			prev = curr;
			curr = curr->next;
		}

		if (curr)
		{
			prev->next = curr->next;
			curr->next = lst;

			lst = curr;
		}
	}

	return lst;
}

struct Node *Insert (struct Node *lst, int index, int x)
{
	struct Node *new = NULL, *ptr = NULL;

	if (((index >= 0) && (index <= ICount (lst)))
			&& (new = (struct Node *) malloc (sizeof (struct Node))))
	{
		ptr = lst;

		new->data = x;
		new->next = NULL;

		if (!index)
		{
			new->next = lst;
			lst = new;
		}
		else
		{
			for (int i = 0; i < (index - 1); i++)
				ptr = ptr->next;

			new->next = ptr->next;
			ptr->next = new;
		}
	}

	return lst;
}

// node will be surely inserted
struct Node *Append (struct Node *lst, int x)
{
	struct Node *new = NULL, *ptr = NULL;

	if ((new = (struct Node *) malloc (sizeof (struct Node))))
	{
		new->data = x;
		new->next = NULL;

		if (lst)
		{
			ptr = lst;
			while (ptr->next)
				ptr = ptr->next;

			ptr->next = new;
		}
		else
		{
			lst = new;
		}
	}

	return lst;
}

struct Node *InsertSorted (struct Node *lst, int x)
{
	struct Node *new = NULL, *prev = NULL, *curr = NULL;

	if ((new = (struct Node *) malloc (sizeof (struct Node))))
	{
		new->data = x;
		new->next = NULL;

		if (!lst)
			lst = new;
		else
		{
			while (curr && (curr->data < x))
			{
				prev = curr;
				curr = curr->next;
			}

			new->next = curr;

			// if data is smaller than first node
			if (curr == lst)
				lst = new;
			else
			{
				prev->next = new;
			}
		}
	}

	return lst;
}

struct Node *Delete (struct Node *lst, int idx)
{
	struct Node *prev = NULL, *curr = NULL;

	if (lst && ((idx >= 0) && (idx < ICount (lst))))
	{
		if (!idx)
		{
			prev = lst;
			lst = lst->next;

			free (prev);
		}
		else
		{
			curr = lst;

			for (int i = 0; i < idx; i++)
			{
				prev = curr;
				curr = curr->next;
			}

			prev->next = curr->next;

			free (curr);
		}
	}

	return lst;
}

bool IsSorted (struct Node *p)
{
	int next = INT_MIN;
	bool flag = true;

	while (p && p->next && flag)
	{
		next = p->next->data;

		if (p->data > next)
			flag = false;

		p = p->next;
	}

	return flag;
}

struct Node *RemoveDuplicates (struct Node *lst)
{
	struct Node *prev = NULL, *curr = NULL, *tmp = NULL;

	if (lst)
	{
		curr = lst;

		while (curr)
		{
			prev = curr;
			curr = curr->next;

			if (prev->data == curr->data)
			{
				prev->next = curr->next;

				free (curr);

				curr = prev->next;
			}
		}
	}

	return lst;
}

struct Node *ReverseElements (struct Node *lst)
{
	int cnt, idx;
	int *aux = NULL;
	struct Node *ptr = NULL;

	if (lst) 
	{
		idx = 0;
		cnt = ICount (lst);

		if ((cnt > 0) && (aux = (int *) malloc (cnt * sizeof (int))))
		{
			ptr = lst;

			while (ptr)
			{
				aux [idx] = ptr->data;

				ptr = ptr->next;
				idx += 1;
			}

			ptr = lst;
			idx -= 1;

			while (ptr)
			{
				ptr->data = aux[idx];

				ptr = ptr->next;
				idx += 1;
			}

		}
	}

	return lst;
}

// reverse link of node with curr as ptr (point to prev),
// curr will reverse link of last node in list
struct Node *ReverseLinksSlidingPtrs (struct Node *lst)
{
	struct Node *prev = NULL, *curr = NULL;
	while (lst)
	{
		prev = curr;
		curr = lst;

		lst = lst->next;
		curr->next = prev;
	}

	if (curr)
	{
		lst = curr;
	}

	return lst;
}

// pass prev as NULL and curr as head
struct Node *ReverseRecursion (struct Node *prev, struct Node *curr)
{
	// move prev to curr and curr to next node
	// reverse link of curr wtih prev

	struct Node *head = NULL;

	// make q as first since q will be on the last node, which will become first node

	if (!curr)
		head = prev;
	else
	{
		head = ReverseRecursion (curr, curr->next);
		curr->next = prev;
	}

	return head;
}

struct Node *Concatanate (struct Node *one, struct Node *two)
{
	struct Node *head = NULL;

	if (one && two)
	{
		while (one->next)
			one = one->next;

		one->next = two;
		head = one;
	}
	else if (one || two)
	{
		if (one)
			head = one;
		else
		{
			head = two;
		}
	}

	return head;
}

// pass head ptr of lists to be merged
// both list must be sorted
struct Node *Merge (struct Node *one, struct Node *two)
{
	struct Node *head = NULL, *tail = NULL;

	if (one && two)
	{
		if (one->data < two->data)
		{
			head = one;
			one = one->next;
		}
		else
		{
			head = two;
			two = two->next;
		}
		tail = head;

		while (one && two)
		{
			if (one->data < two->data)
			{
				tail->next = one;
				tail = one;

				one = one->next;
			}
			else
			{
				tail->next = two;
				tail = two;

				two = two->next;
			}

		}

		if (one)
			tail->next = one;
		else if (two)
		{
			tail->next = two;
		}
	}
	else if (one || two)
	{
		if (one)
			head = one;
		else
		{
			head = two;
		}
	}

	return head;
}

bool IsLoop (struct Node *lst)
{
	bool flag = false;
	struct Node *slow = NULL, *fast = NULL;

	if (lst)
	{
		slow = fast = lst;

		do
		{
			slow = slow->next;
			fast = fast->next;

			if (fast)
			{
				fast = fast->next;
			}

		} while (slow && fast && (slow != fast));

		if (slow == fast)
		{
			flag = true;
		}
	}

	return flag;
}

struct Node *MiddleNode (struct Node *lst)
{
	struct Node *slow = NULL, *fast = NULL;

	if (lst)
	{
		slow = fast = lst;

		while (fast)
		{
			fast = fast->next;

			if (fast)
			{
				fast = fast->next;
				slow = slow->next;
			}
		}
	}

	return slow;
}

// store address of all nodes of both lists in two stacks then pop values if they are same, 
// retain copy of last popped node, return that node or print data of intersection node
/*
void IntersectionNode (struct Node *one, struct Node *two) 
{
	struct Node *ptr = NULL;

	if (one && two)
	{
		ptr = one;

		while (ptr)
		{
			push (&stkx, ptr);
			ptr = ptr->next;
		}

		ptr = two;

		while (ptr)
		{
			push (&stky, ptr);
			ptr = ptr->next;
		}

		while (peek (stkx) == peek (stky))
		{
			pop (stkx);
			ptr = pop (stky);
		}
	}

	return ptr;
}
*/

int main (int argc, char const *argv[])
{
	struct Node *lstx = NULL, *lsty = NULL;
	int A[] = {0, 2, 4, 6, 8, 10, 12, 14, 16, 18};
	int B[] = {1, 3, 5};

	lstx = Create (&lstx, A, 10);
	lsty = Create (&lsty, B, 3);

	struct Node *p = lstx, *q = lsty;

	while (q->next)
		q = q->next;

	while (p->data != 10)
		p = p->next;

	q->next = p;

	IDisplay (lstx);
	IDisplay (lsty);

	return 0;
}
