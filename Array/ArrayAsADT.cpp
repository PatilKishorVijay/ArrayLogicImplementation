#include<iostream>
using namespace std;


//ADT - Abstract Data Type Array as an abstract Data type

/*
* insertion
* deletion
* linear search
* binary search
* Reversing
* Merging
* Arranging negative elements
* Left shifting
* Swapping
* isSorted checking
*/



struct Array
{
	int A[20] = { 0 };
	int Size;
	int Length;
};

void insert(Array& arr, int pos, int& length, int no)
{
	if (pos >= length)
	{
		arr.A[pos] = no;
		length++;
	}
	else
	{
		for (int i = length; i > pos; i--)
		{
			arr.A[i] = arr.A[i - 1];

		}
		arr.A[pos] = no;
		length++;

	}
}

void deleteElement(Array& arr, int pos, int& length)
{
	if (pos <= length)
	{
		for (int i = pos - 1; i < length; i++)
			arr.A[i] = arr.A[i + 1];
		length--;
	}
}

int linearSearch(Array& arr, int length, int key)
{
	for (int i = 0; i < length; i++)
		if (key == arr.A[i])
			return (i + 1);
	return -1;
}

int BinarySearch(int* Barr, int length, int key)
{
	int l = 0, mid, h = length - 1;
	while (l <= h)
	{
		mid = (l + h) / 2;
		if (key == Barr[mid])
			return mid + 1;
		else if (key < Barr[mid])
			h = mid - 1;
		else
			l = mid + 1;
	}
	cout << "item not found" << endl;
	return -1;

}

int RBinarySearch(int* arr, int key, int l, int h)
{
	int mid = 0;
	if (l <= h)
	{
		mid = (l + h) / 2;
		if (key == arr[mid])
			return mid + 1;
		else if (key < arr[mid])
			RBinarySearch(arr, key, l, mid - 1);
		else
			RBinarySearch(arr, key, mid + 1, h);

	}
	else
		return -1;
}

void ReverseArray(int* arr, int length)
{

	for (int i = 0, j = length - 1; i < j; i++, j--)
	{
		int temp;
		temp = arr[i];
		arr[i] = arr[j];
		arr[j] = temp;
	}
}

void LeftShiftAndRotate(char* arr)
{
	cout << endl << endl;
	char ch = arr[0];
	for (int i = 0; i < 6; i++)
		arr[i] = arr[i + 1];
	arr[6] = ch;
	for (int i = 0; i < 7; i++)
		cout << arr[i] << " ";


}

void InsertIntoSortedArray(int* arr, int no, int length)
{
	int i = length - 1;
	while (arr[i] > no)
	{
		arr[i + 1] = arr[i];
		i--;
	}
	arr[i + 1] = no;
}

int isSorted(int* arr, int length)
{
	for (int i = 0; i < length - 1; i++)
	{
		if (arr[i] > arr[i + 1])
			return false;
	}
	return true;
}
void swap(int& a, int& b)
{
	int t = a;
	a = b;
	b = t;
}
void arrangeNegative(int* arr, int length)
{
	int i = 0, j = length - 1;
	while (i < j)
	{
		while (arr[i] < 0) { i++; }
		while (arr[j] > 0) { j--; }
		if (i < j)
			swap(arr[i], arr[j]);
	}
}

void mergeArrays(int* a, int* b,int *c)
{
	
	int i, j, k;
	i= j = k = 0;

	int aL = 6, bL = 3;
	while (i < aL && j < bL)
	{
		if (a[i] < b[j])
			c[k++] = a[i++];
		else
			c[k++] = b[j++];
	}

	for (; i < aL; i++)
		c[k++] = a[i];
	for (; j < bL; j++)
		c[k++] = b[j];

	
}
int main()
{
	cout << "code for adding elements in an array " << endl;
	Array arr;
	//cout << "enter size of an array to create" << endl;
	//cin >> arr.Size;
	int n;
	cout << "eneter elements u want to add initially" << endl;
	cin >> n;
	//arr.A = new int[arr.Size];

	for (int i = 0; i < n; i++)
	{
		cin >> arr.A[i];
	}

	for (int i = 0; i < n; i++)
		cout<< arr.A[i]<<" ";

	cout << endl << "**********************************" << endl;
	cout << endl << n << endl;

	
	//code for insertion of an element in array
	cout << "code for insertion of element in an array" << endl;
	int x,pos;

	cout << "eneter postion ad number u want to add" << endl;
	cin >> pos; cin >> x;

	insert(arr,pos-1,n,x);

	for (int i = 0; i < n; i++)

		cout << arr.A[i] << " ";
	cout << endl << "**********************************" << endl;
	cout <<endl<< n << endl;

	

	//code for array element deletion
	cout << "code for deleting an element in an array" << endl;
	int pos;

	cout << "enter the postion u want to delete" << endl;
	cin >> pos;
	deleteElement(arr,pos,n);
	for (int i = 0; i < n; i++)
		cout << arr.A[i] << " ";
	cout << endl << "**********************************" << endl;
	

		
	//code snippet for linear search
	cout << "code for Linear Search of element in an array " << endl;
	int no;
	cout << "enter element u want to earch in array" << endl;
	cin >> no;
	cout << "element found at " << linearSearch(arr, n, no) << endl;
	cout << endl << "**********************************" << endl;
	cout << endl << endl;
		


		/*
		binary search

		**** array must be sorted for binary search

	*/
	cout << "binary search mechanism for an array" << endl;
	int Barr[15] = { 12,23,34,45,56,67,78,89,90,100 };
	int key;
	for (int i = 0; i < 10; i++)
		cout << Barr[i] << " ";
	cout << endl;
	cout << "enter element to search by using binary search" << endl;
	cin >> key;
	cout << "key is present at " << BinarySearch(Barr, 10, key) << endl;
	int rkey;
	cout << "enter key for recurrsive binary search" << endl;
	cin >> rkey;
	cout << "key present using Recusive call to function " << RBinarySearch(Barr, rkey, 0, 10) << endl;
	cout << endl << "**********************************" << endl;
	cout << endl <<  endl;

	//reversing an array
	cout << "reversing of an array" << endl;
	int revarr[10] = { 12,23,34,45,56,87,21,17,11 ,1711 };
	cout << endl << endl;
	for (int i = 0; i < 10; i++)
		cout << revarr[i] << " ";
	cout << endl << endl;
	ReverseArray(revarr, 10);
	for (int i = 0; i < 10; i++)
		cout << revarr[i] << " ";
	cout << endl << "**********************************" << endl;
	cout << endl <<  endl;

	//left shift and rotate
	cout << "left shifting of an array" << endl;
	char carr[] = "Welcome";
	LeftShiftAndRotate(carr);

	cout << endl << "**********************************" << endl;
	cout << endl <<  endl;




	//checking if an array is sorted or not
	cout << "checking array is sorted or not" << endl;
	cout << "result of checking array sorted or not is :- " << isSorted(Barr, 10) << endl;
	cout << endl << "**********************************" << endl;
	cout << endl <<  endl;

	//inserting into a sorted array
	cout << "inserting element into a SORTED array" << endl;
	cout << "sorted array before insertion" << endl << endl;
	for (int i = 0; i < 10; i++)
		cout << Barr[i] << " ";
	int no;
	cout << "enter number to insert" << endl;
	cin >> no;
	InsertIntoSortedArray(Barr, no, 10);
	cout << "sorted array after**** insertion" << endl << endl;
	for (int i = 0; i < 11; i++)
		cout << Barr[i] << " ";
	cout << endl << "**********************************" << endl;
	cout << endl <<  endl;

	//arranging -ve on left side
	cout << "code for arranging negative elements in LHS of array" << endl;
	int NegativeArray[10] = { -11,22,33,-44,55,66,54,-89,57,-32 };
	for (int i = 0; i < 10; i++)
		cout << NegativeArray[i] << " ";
	cout << endl;
	arrangeNegative(NegativeArray, 10);
	for (int i = 0; i < 10; i++)
		cout << NegativeArray[i] << " ";
	cout << endl << "**********************************" << endl;
	cout << endl <<  endl;

	//Merging of two arrays
	cout << "code for merging of sorted arrays" << endl;
	int a[6] = { 1,3,8,10,45,65 };
	for (int i = 0; i < 6; i++)
		cout << a[i] << " ";
	cout << endl;

	int b[3] = { 9,20,50 };
	for (int i = 0; i < 3; i++)
		cout << b[i] << " ";
	cout << endl;
	if (isSorted(a,6)&&isSorted(b,3)) 
	{
		cout << "after merging of a and b ----" << endl;
		int c[9];
		mergeArrays(a, b, c);
		for (int i = 0; i < 9; i++)
			cout << c[i] << " ";
	}
	cout << endl << "**********************************" << endl;
	cout << endl << endl;


}