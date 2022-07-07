#include<iostream>
using namespace std;


template<class T>
class stack_array
{
	int size;
	T top;
	T* data;
public:
	stack_array() {}
	stack_array(T L)
	{
		data = new T[L];
		top = -1;
		size = L;
	}
	~stack_array()
	{
		delete[]data;
		cout << "destructor called" << endl;
		data = NULL;
	}
	void push(T x)
	{
		top++;
		this->data[top] = x;
	}

	T peek(int pos)
	{
		return this->data[(top - pos + 1)];
	}

	T pop()
	{
		int x = -1;
		if (size == -1)
		{
			cout << "stack underflow" << endl;
			return x;
		}
		else
		{
			x = data[top];
			top--;
			return x;
		}
		
		return x;
	}

	T stackTop()
	{
		return this->data[top];
	}

	int isFull()
	{
		if (top == size - 1)
			return 1;
		else
			return 0;
	}

	int isEmpty()
	{
		if (top == -1)
			return 1;
		else
			return 0;
	}
	void display()
	{
		if(!isEmpty())
		for(int i=0;i<size;i++)
		cout << this->data[i] << endl;
	}
};


class Node
{
public:
	Node* prev;
	Node* next;
	int data;

	Node(int no)
	{
		prev = next = NULL;
		data = no;
	}
	~Node()
	{
		cout << "Node destructor called" << endl;
	}
};
class stack_list
{
	Node* top;
	Node* tail;
public:
	stack_list()
	{
		top = tail = NULL;
	}
	void push(int x)
	{
		Node* newnode = new Node(x);
		if (!newnode)
			cout << "stack overflow heap is full" << endl;
		else
		{
			if (top == NULL)
			{
				top = tail = newnode;
			}
			else
			{
				newnode->next = top;
				top->prev = newnode;
				top = newnode;
			}
		}
	}

	int pop()
	{
		Node* temp;
		int x = -1;
		if (top == NULL)
			cout << "stack underflow" << endl;
		else
		{
			temp = top;
			top = top->next;
			x = temp->data;
			delete temp;
		}
		return x;
	}

	void display()
	{
		Node* temp = top;
		while (temp)
		{
			cout << temp->data << " ";
			temp = temp->next;
		}
		cout << endl;
	}


};


void pushandPopCharArrayToStack(char *arr,stack_array<char> &ref)
{
	for (int i = 0; arr[i] != '\0'; i++)
	{
		if (arr[i] == '(')
			ref.push(arr[i]);
		else if (arr[i] == ')')
			ref.pop();
	}
}

int main()
{
	/*int size;
	cout << "enter how many elements u want to add to stack ? " << endl;

	cin >> size;
	stack_array s(size);
	int x;
	for (int i = 0; i < size; i++)
	{
		cin >> x;
		s.push(x);
	}
	s.display();
	
	cout << s.peek(3) << endl;;
	cout << s.stackTop() << endl;
	cout << endl<<"popping...." << endl;
	for (int i = 0; i < size; i++)
	{
		cout << s.pop() << endl;;
	}

	s.display();*/

	/*stack_list s2;
	int x;
	cout << "enter elements to push into stack with list" << endl;

	while (cin >> x ,x != -1)
	{
		s2.push(x);
	}

	s2.display();

	while (s2.pop() != -1);

	s2.display();*/


	
	char arr[] = "((a+b)+(a-b)))";
	stack_array<char> s3(strlen(arr));
	pushandPopCharArrayToStack(arr,s3);
	if (s3.isEmpty())
		cout << "parenthesis is matching" << endl;
	else
		cout << "not matching" << endl;

}