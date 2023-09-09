#include <iostream>
#include <climits>

using namespace std;

template <typename T>
class Node
{
	public:
		T data;
		Node *next;
};

template <typename T>
class LinkedList
{
	private:
		Node <T> *head;

	public:
		LinkedList()
		{ 
			head = nullptr;
		}

		LinkedList (T [], int);
		~LinkedList ();

		int Length ();
		void Display ();

		void Insert (int, T);
		T Delete (int);
};

	template <typename T>
LinkedList <T> :: LinkedList (T arr[], int n)
{
	Node <T> *tmp = nullptr, *tail = nullptr;

	if (arr && (n > 0))
	{
		head = new Node <T>;
		head->data = arr[0];
		head->next = nullptr;

		tail = head;

		for (int i = 1; i < n; i++)
		{
			tmp = new Node <T>;

			tmp->data = arr[i];
			tmp->next = nullptr;

			tail->next = tmp;
			tail = tmp;
		}
	}

	return ;
}

	template <typename T>
LinkedList <T> :: ~LinkedList ()
{
	Node <T> *prev = nullptr, *curr = nullptr;

	if (head)
	{
		curr = head;

		while (curr)
		{
			prev = curr;
			curr = curr->next;

			delete prev;
		}
	}

	return ;
}

	template <typename T>
int LinkedList <T> :: Length ()
{
	int len = INT_MIN;
	Node <T> *itr = nullptr;

	if (head)
	{
		len = 0;
		itr = head;

		while (itr)
		{
			len += 1;
			itr = itr->next;
		}
	}

	return len;
}

	template <typename T>
void LinkedList <T> :: Display ()
{
	Node <T> *itr = nullptr;

	if (head)
	{
		itr = head;

		while (itr)
		{
			cout << itr->data << ' ';
			itr = itr->next;
		}
		cout << endl;
	}

	return ;
}

	template <typename T>
void LinkedList <T> :: Insert (int idx, T x)
{
	Node <T> *tmp = nullptr, *ptr = nullptr;

	if ((idx >= 0) && (idx <= Length ()))
	{
		ptr = head;

		tmp = new Node <T>;

		tmp->data = x;
		tmp->next = nullptr;

		if (!idx)
		{
			tmp->next = head;
			head = tmp;
		}
		else
		{
			for (int jmp = 0; jmp < (idx - 1); jmp++)
				ptr = ptr->next;

			tmp->next = ptr->next;
			ptr->next = tmp;
		}
	}

	return ;
}

	template <typename T>
T LinkedList <T> :: Delete (int idx)
{
	T ret = INT_MIN;
	Node <T> *prev = nullptr, *curr = nullptr;

	if ((idx >= 0) && (idx < Length ()))
	{
		curr = head;

		if (!idx)
		{
			ret = curr->data;

			head = head->next;

			free (curr);
		}
		else
		{
			for (int jmp = 0; jmp < idx; jmp++)
			{
				prev = curr;
				curr = curr->next;
			}

			ret = curr->data;

			prev->next = curr->next;

			free (curr);
		}
	}

	return ret;
}

int main (const int argc, const char *argv[])
{
	float arr[] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7, 8.8, 9.9};
	LinkedList <float> list (arr, 9);

	list.Display ();

	list.Insert (0, 0.0);
	list.Insert (10, 10.10);
	list.Display ();

	list.Delete (0);
	list.Delete (9);
	list.Display ();

	return 0;
}
