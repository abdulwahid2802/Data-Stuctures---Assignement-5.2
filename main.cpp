#include<iostream>
#include <cstdlib>
#include<time.h>

using namespace std;

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
	void _printLevel(Queue<Nptr>&);

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

	static int level = 0;

	while (!q.isEmpty())
	{
		_printLevel(q);
	}
}

template<class T>
void Tree<T>::_printLevel(Queue<Nptr> &q)
{
	if (!q.isEmpty())
	{
		Nptr n = q.deque();
		cout << n->data<<" ";
		if (n->left)
			q.enque(n->left);
		if (n->right)
			q.enque(n->right);

		_printLevel(q);

	}
}


int main()
{

	srand(time(0));
	Queue<int> q;
	Tree<int> t;

	for (int i = 0; i < 10; i++)
	{
		int n = rand() % 100;
		t.insert(n);
		cout << n << " ";

	}

	cout << endl;
		//q.enque(i);

	//q.print();

	t.printPre();
	cout << endl;

	t.printLevel();

	cin.get();
	return 0;
}