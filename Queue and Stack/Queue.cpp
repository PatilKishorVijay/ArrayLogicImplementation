#include<iostream>
using namespace std;

class Queue_array
{
	int front;
	int rear;
	int* Q;
	int size;

public:
	Queue_array(int L)
	{
		Q = new int[L];
		front = rear = -1;
	}

	void enqueue(int x)
	{
		rear++;
		Q[rear] = x;
	}

	int dequeue()
	{
		int x = -1;
		
		if (front == rear)
			cout << "queue is empty" << endl;
		else
		{
			front++;
			x = Q[front];
		}
		return x;
	}

	int isEmpty()
	{
		return(front == rear);
	}

	bool isFull()
	{
		return (rear == (size - 1));
	}

	int first()
	{

		return Q[front + 1];
	}
	int last()
	{
		return Q[rear];
	}
	void display()
	{
		for (int i = front+1; i <= rear; i++)
			cout << Q[i] << " ";
		cout << endl;
	}

};
int main()
{
	Queue_array Q(7);
	int x;
	
	for (int i = 0; i < 7; i++)
	{
		cin >> x;
		Q.enqueue(x);
	}

	Q.display();
	Q.dequeue();
	Q.display();
	cout << endl;
	cout << Q.first() << endl;
	cout << Q.last() << endl;

}