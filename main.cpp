#include<iostream>
#include <cstdlib>
#include<time.h>

using namespace std;
int count = 0;
template<class T>
class Queue
{
	typedef struct Node
	{
		T data;
		Node *next;
	}*Nptr;

	Nptr head;
	Nptr tail;

	void _makeNode(T);
	void _enque(Nptr &, Nptr);
	T _deque();


public:
	Queue() : head(NULL), tail(NULL){}
	void enque(T);
	void print();
	T deque();
	bool isEmpty();
};

template<class T>
bool Queue<T>::isEmpty()
{
	return head==NULL;
}

template<class T>
void Queue<T>::enque(T data)
{
	_makeNode(data);
}

template<class T>
void Queue<T>::_makeNode(T data)
{
	Nptr n = new Node();
	n->next = NULL;
	n->data = data;

	_enque(head, n);
}

template<class T>
void Queue<T>::_enque(Nptr &Ptr, Nptr n)
{
	if (!head)
	{
		head = n;
		tail = n;
	}
	else
	{
		tail->next = n;
		tail = n;
	}
}

template<class T>
void Queue<T>::print()
{
	Nptr temp = head;

	while (temp)
	{
		cout << temp->data<< " ";
		temp = temp->next;
	}
}

template<class T>
T Queue<T>::deque()
{
	return _deque();
}

template<class T>
T Queue<T>::_deque()
{
	if (head)
	{
		Nptr temp = head;
		T data = temp->data;

		head = head->next;
		delete temp;
		return data;
	}
	else
		return NULL;
}


template<class T>
class Tree
{
	typedef struct Node
	{
		T data;
		Node* right;
		Node* left;
	}*Nptr;
	Nptr root;

	void _makeNode(T);
	void _addNode(Nptr &, Nptr);
	void _printPre(Nptr);

public:
	Tree():root(NULL){}

	void insert(T);
	void printPre();
	void printLevel();
	bool isEmpty();
};

template<class T>
bool Tree<T>::isEmpty()
{
	return root == NULL;
}

template<class T>
void Tree<T>::insert(T data)
{
	_makeNode(data);
}

template<class T>
void Tree<T>::_makeNode(T data)
{
	Nptr n = new Node();
	n->right = n->left = NULL;
	n->data = data;

	_addNode(root, n);
}

template<class T>
void Tree<T>::_addNode(Nptr &Ptr, Nptr n)
{
	if (Ptr)
	{
		if (Ptr->data >= n->data)
			_addNode(Ptr->left, n);
		else
			_addNode(Ptr->right, n);
	}
	else
		Ptr = n;
}

template<class T>
void Tree<T>::printPre()
{
	_printPre(root);
}

template<class T>
void Tree<T>::_printPre(Nptr Ptr)
{
	if (Ptr)
	{
		_printPre(Ptr->left);
		cout << Ptr->data << " ";
		_printPre(Ptr->right);
	}
}

template<class T>
void Tree<T>::printLevel()
{
	Queue<Nptr> q;

	q.enque(root);
	int nodes = 1;

	static int level = 1;

	while (!q.isEmpty())
	{
		int temp=0;
		while (nodes--)
		{
			Nptr n = q.deque();
			cout << n->data << "----->>>> level: "<< level-1 << endl;
			if (n->left)
			{
				q.enque(n->left);
				temp++;
			}
			if (n->right)
			{
				q.enque(n->right);
				temp++;
			}
		}
		nodes = temp;
		level++;
	}
}


int main()
{

	char choice;
	Tree<int> t;

	while (1)
	{
		cin >> choice;
		switch (choice)
		{
			case 'e':
				exit(1); break;
			case 'i':
				int n;
				cin >> n;
				t.insert(n); break;
			case 'p':
				t.printPre(); 
				cout << endl; break;
			case 't':
				t.printLevel(); break;
			default:break;
		}

	}

	cin.get();
	return 0;
}