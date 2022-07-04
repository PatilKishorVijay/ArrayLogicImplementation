#include<iostream>
#include<queue>
using namespace std;


class Node
{
public:
	Node* Lchild;
	int data;
	Node* Rchild;
	//Node* Parent;

	Node(int x)
	{
		Lchild = Rchild = NULL;
		data = x;
	}
};

class BinaryTree
{
	
	Node* root;
	//static int count;

	void insertIntoTree(Node* node, int x)
	{
		if (!root)
		{
			root = new Node(x);
		}
		else
		{
			while (node)
			{
				if (x <= node->data)
				{
					if (node->Lchild == NULL)
					{
						node->Lchild = new Node(x);
						return;
					}
					else
						node = node->Lchild;

				}
				else
				{
					if (node->Rchild == NULL)
					{
						node->Rchild = new Node(x);
						return;
					}
					else
						node = node->Rchild;
				}
			}
		}
	}
	void getPreorder(Node* p)
	{
		if (p)
		{
			cout << p->data << " ";
			getPreorder(p->Lchild);
			getPreorder(p->Rchild);
		}
	}
	void getPostOrder(Node* p)
	{
		if (p) {
			getPostOrder(p->Lchild);
			getPostOrder(p->Rchild);
			cout << p->data << " ";
		}

	}
	void getInOrder(Node* p)
	{
		if (p) {
			//count++;
			getInOrder(p->Lchild);
			cout << p->data << " ";
			getInOrder(p->Rchild);
		}
	}
	int getDepthAndNodeCount(Node* node, int choice)
	{
		if (!node)
			return 0;
		else
		{
			int x = getDepthAndNodeCount(node->Lchild, choice);
			int y = getDepthAndNodeCount(node->Rchild, choice);
			if (choice == 1)
			{
				if (x > y)
					return x + 1;
				else
					return y + 1;
			}
			else
				return x + y + 1;
		}
	}
	void printElementByLevel(Node* node, int level)
	{
		if (node == NULL)
			return;
		if (level == 1)
			cout << node->data << " ";
		else if (level > 1)
		{
			printElementByLevel(node->Lchild, level - 1);
			printElementByLevel(node->Rchild, level - 1);
		}
	}
	void getLevelTraversal(Node* node)
	{
		int h = calculateDepth();
		for (int i = 1; i <= h; i++)
		{
			printElementByLevel(root, i);
		}
	}
	bool searchKeyInTree(Node* p, int key)
	{
		if (!p)
			return 0;
		while (p)
		{
			if (p->data == key)
				return 1;
			else
			{
				if (p->data > key)
					p = p->Lchild;
				else
					p = p->Rchild;
			}
		}
		return 0;
	}
public:
	BinaryTree()
	{
		root = NULL;
	}
	
	void insert(int x)
	{
		insertIntoTree(root, x);
	}

	
	void preOrder()
	{
		getPreorder(root);
	}
	
	void postOrder()
	{
		getPostOrder(root);
	}

	
	void inOrder()
	{
		getInOrder(root);
	}
	int getNodeCount()
	{
		return getDepthAndNodeCount(root, 2);
	}
	
	int calculateDepth()
	{
		return getDepthAndNodeCount(root,1);
	}
	
	
	void traverseLevel()
	{
		getLevelTraversal(root);
	}

	
	bool searchKey(int key)
	{
		return searchKeyInTree(root,key);
	}

};
int BinaryTree::count = 0;
int main()
{
	BinaryTree BT1;
	int x;
	cout << "enter elements in B tree except -1" << endl;
	while(cin>>x,x!=-1)
	BT1.insert(x);

	//cout << "pre order --" << endl;
	//BT1.preOrder();
	//cout << endl;
	//cout << "post order --" << endl;
	//BT1.postOrder();
	//cout << endl;
	//cout << "In order --" << endl;
	//BT1.inOrder();
	//cout << endl;
	//cout << BT1.getNodeCount() << endl;
	//cout << "height / depth " << BT1.calculateDepth() << endl;
	//cout << "node count "<<BT1.getNodeCount() << endl;

	//cout << endl;
	//BT1.traverseLevel();

	int key;
	cout << "enter key to search in tree" << endl;
	cin >> key;
	if (BT1.searchKey(key))
		cout << "found" << endl;
	else
		cout << "not found" << endl;

}