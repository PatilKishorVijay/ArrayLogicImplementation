#include<iostream>
using namespace std;

void displayArray(int *arr,int L)
{
	for (int i = 0; i < L; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void swap(int &a,int &b)
{
	int c;
	c = a; a = b; b = c;
}
void doBubbleSort(int *arr,int L)
{
	for (int i = 0; i < L-1; i++)
	{
		int flag = 0;
		for (int j =0; j < L-1-i ; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)
		{
			cout << "array is sorted after " << arr[i] << endl;
			cout << "it minimised " << L - i << " iterations" << endl;
			break;
		}
	}
}

void AddElementsInArray(int *arr,int x)
{
	for (int i = 0; i < x; i++)
		cin >> arr[i];
}

void insertKeyInSortedArray(int* arr, int L)
{
	for (int i = 1; i <L;i++)
	{
		int x = arr[i];
		int j = i - 1;
		while (j >= 0 && arr[j]>x)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = x;
	}
}


void doSelectionSort(int *arr, int L)
{
	for (int i = 0; i < L-1; i++)
	{
		int j, k;
		for (j=k = i; j < L; j++)
		{
			if (arr[j] < arr[k])
			{
				k = j;
			}
		}
		swap(arr[k],arr[i]);
	}
}

void mergeSort(int *arr,int L)
{
	for (int i = 0; i < L; i++)
	{

	}
}
void mergeArrays(int*arr1,int L1,int *arr2,int L2)
{
	int* marr = new int[L1 + L2];
	int i = 0, j = 0, k = 0;;
	while (i < L1 && j < L2)
	{
		if (arr1[i] < arr2[j])
			marr[k++] = arr1[i++];
		else
			marr[k++] = arr2[j++];
	}
	while (i < L1)
		marr[k++] = arr1[i++];
	while (j < L2)
		marr[k++] = arr2[j++];

	displayArray(marr,L1+L2);
}


void merge(int *arr,int l,int mid,int h)
{
	int i, j, k=0;
	int B[100];
	while(i <= mid && j <= h)
	{
		if (arr[i] < arr[j])
			B[k++] = arr[i++];
		else
			B[k++] = arr[j++];
	}
	while (i <= mid)
		B[k++] = arr[i++];
	while (j <= h)
		B[k++] = arr[j++];

	for (int i=l;i<=h;i++)
	{
		arr[i] = B[i];
	}
	displayArray(arr, h + 1);
}
void mergeSort()
{

}
int main()
{
	/*int x;
	cin >> x;*/
	/*int *arr1=new int[x];
	AddElementsInArray(arr1,x);
	displayArray(arr1, 5);
	doBubbleSort(arr1, 5);
	displayArray(arr1,5);*/

	
	//int* arr2 = new int[x];
	//AddElementsInArray(arr2,x);
	//
	//displayArray(arr2, x);
	//insertKeyInSortedArray(arr2,x);
	//displayArray(arr2, x);

	//int* arr3 = new int[x];
	//AddElementsInArray(arr3,x);
	//displayArray(arr3,x);
	//doSelectionSort(arr3,x);
	//displayArray(arr3, x);

	
	int arr4[3]= {2,4,11};
	
	int arr5[5] = {1,3,5,9,15};
	
	displayArray(arr4,3);
	cout << endl;
	displayArray(arr5, 5);
	mergeArrays(arr4,3,arr5,5);
	
	int arr6[10] = { 12,2,45,6,87,98,17,11,21,51 };
	mergeSort(arr6,10);
}