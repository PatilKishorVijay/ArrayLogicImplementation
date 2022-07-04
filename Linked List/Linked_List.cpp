#include<iostream>
#include<string>
using namespace std;


class Node
{
public:
	int data;
	Node* next;
	Node()
	{
		next = NULL;
	}
	Node(int x):data(x)
	{
		next = NULL;
	}
	~Node()
	{
		cout << "Destructor Node class" << endl;
	}
};

class List
{
private:
	Node *head, *tail,*newNode;
public:
	List()
	{
		head = tail = NULL;
	}

	void AddNode(int no)
	{
		newNode = new Node(no);
		if (head == NULL)
			head=tail=newNode;
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
	}

	void displayList()
	{
		for (Node* current = head ; current != NULL; current = current->next)
		{
			
			cout << current->data << " ";
		}
		cout << endl;
	}

	int getCountOfNodes()
	{
		int cnt = 0;
		Node* current = head;
		while (current)
		{
			cnt++;
			current = current->next;
		}
		return cnt;
	}
	
	int maxFromList()
	{
		int max = 0;
		Node* current = head;
		while (current)
		{
			if (max < current->data)
				max = current->data;
			current = current->next;
		}
		return max;
	}
	int isSortedList()
	{
		int x = -2147483648;
		for (Node* current = head; current != NULL; current = current->next)
		{
			if (current->data < x)
				return 0;
			x = current->data;
		}

		return 1;
	}

	void removeDuplicatesFromSortedList()
	{
		if (isSortedList())
		{
			for (Node* current = head; current->next != NULL; current = current->next)
			{
				if (current->data == current->next->data)
				{
					while (current->data == current->next->data)
					{
						Node* remove = current->next;
						current->next = current->next->next;
						delete remove;
					}
				}

			}

		}
	}

	void reverseList()
	{
		Node* p, * q, * r;
		p = head;
		q = r = NULL;

		while (p!=NULL)
		{
			r = q;
			q = p;
			p = p->next;
			q->next = r;
		}

		head = q;
	}

	int getMiddleNode()
	{
		Node* p, * q;
		p = head;
		q = head;

		while (q)
		{
			q = q->next;
			if (!q)
				return p->data;
			p = p->next;
			q = q->next;
		} 
		return p->data;
	}

	void Concatenate(List &M)
	{
		Node* current = this->head;
		while (current->next!=NULL)
		{
			current = current->next;
		}

		current->next = M.head;
	}

	void mergeSortedList(List &M, List &Merged)
	{
		Node* p = head;
		Node* q = M.head;
		while (p && q)
		{
			if (p->data <= q->data)
			{
				if (Merged.head == NULL)
				{
					Merged.head = Merged.tail = p;
				}
				else
				{
					Merged.tail->next = p;
					Merged.tail = p;
				}
				p = p->next;
			}
			else
			{
				if (Merged.head == NULL)
				{
					Merged.head = Merged.tail = q;
				}
				else
				{
					Merged.tail->next = q;
					Merged.tail = q;
				}
				q = q->next;
			}

		}
		while (p)
		{
			Merged.tail->next = p;
			tail = p;
			p = p->next;
		}
		while (q)
		{
			Merged.tail->next = q;
			tail = q;
			q = q->next;
		}

	}

};
int main()
{
	List L,M;
	int data;
	cout << "enter the elements u want to add in list 1 except 0" << endl;

	while (cin>>data, data != 0)
	{
		L.AddNode(data);
	}
	cout << "enter the elements u want to add in list 2  except 0" << endl;
	while (cin >> data, data != 0)
	{
		M.AddNode(data);
	}

	//L.displayList();
	//cout << endl << endl;
	//cout << L.getCountOfNodes() << endl;
	//cout << endl;
	//cout << L.maxFromList() << endl;
	//cout << L.isSortedList() << endl;
	//L.displayList();
	//L.removeDuplicatesFromSortedList();
	//L.displayList();
	//L.reverseList();
	//L.displayList();
	//cout << endl;

	//cout << L.getMiddleNode() << endl;
	//L.Concatenate(M);
	//L.displayList();
	//cout << endl;

	List Merged;
	L.mergeSortedList(M, Merged);
	Merged.displayList();
	

}