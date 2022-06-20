#include<iostream>
#include<windows.h>
using namespace std;

/*
1) findind missing element 
	* for sorted array and single element
	* for unsorted array
	* for multiple missing element
*/

void display(int *arr,int L)
{
	for (int i = 0; i < L; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int isSortedArray(int* arr, int L)
{
	for (int i = 0; i < L-1; i++)
		if (arr[i] > arr[i + 1])
			return 0;
	return 1;
}

int findMin(int *arr , int L)
{
	int i = 0;
	int min = arr[i];
	for (i=1; i < L; i++)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

int findMax(int *arr, int L)
{
	int i = 0;
	int max = arr[i];
	for (int i = 1; i < L; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

void findMissingElement(int *arr , int L)
{
	if (isSortedArray(arr, L))
	{
		int l = arr[0];
		int h = arr[L - 1];
		int diff = arr[0] - 0;
		for (int i = 0; i < L; i++)
		{
			if (arr[i] - i != diff)
			{
				while (diff < arr[i] - i)
				{
					cout << "missing element is " << i + diff << endl;
					diff++;
				}
				
			}
		}
	}
	else
	{
		int l = findMin(arr, L);
		int h = findMax(arr,L);

		int* hash = new int[h]{0};
		for (int i = 0; i < L; i++)
			hash[arr[i]] = 1;
		cout << "multiple missing elements are from unsorted array as below" << endl;
		for (int i = 0; i < h; i++)
			if (hash[i] == 0)
				cout << i << " ";
		cout << endl;
		cout << endl;
	}
}



void findDuplicatesAndCount(int *arr , int L)
{

	int i = 0, j = 0;
	display(arr, L);
	if (isSortedArray(arr, L))
	{
		for (i; i < L - 1; i++)
		{
			cout << endl<<"displaying sorted array " << endl;
			display(arr, L);
			if (arr[i] == arr[i + 1])
			{
				j = i + 1;
				while (arr[i] == arr[j])
					j++;
				cout << arr[i] << " repeated " << j - i << " times in given SORTED array" << endl;
				i = j - 1;
			}
		}
	}
	else
	{
		cout <<endl<< "displaying Un-sorted array " << endl;
		display(arr, L);
		int h = findMax(arr,L);
		int* hash = new int[h] {0};
		for (int i = 0; i < L; i++)
		{
			hash[arr[i]]++;
		}

		for (int i = 0; i <= h; i++)
		{
			if (hash[i] >1)
				cout<<i<<" is repeated " << hash[i] << " times in unsorted array" << endl;
		}
	}
}

void check_For_Pair_With_Sum_As_K(int *arr, int L, int k)
{
	for (int i = 0; i < L-1; i++)
	{
		for (int j = i + 1; j < L; j++)
		{
			if (arr[i] + arr[j] == k)
				cout << " pair is " << arr[i] << " & " << arr[j] << endl;
		}
	}
}

void findMaxAndMin(int *arr, int &max,int &min,int L)
{
	max = min = arr[0];
	for (int i = 0; i < L; i++)
	{
		if (arr[i] <= min)
		{
			min = arr[i];
		}
		else
		{
			max = arr[i];
		}
	}
}
int main()
{
	//missing element fining from sorted array

	//a) finding missing element from an array of first n natural numbers
	cout << "find missing element from first n natural numbers" << endl;
	int Narr[11] = { 1,2,3,4,5,6,8,9,10,11,12 };
	display(Narr, 11);
	//calculate sum of first n natural numbers n=12;
	int n = 12;
	int sum = n * (n + 1) / 2;
	int LocalSum = 0;
	for (int i = 0; i < 11; i++)
		LocalSum += Narr[i];
	cout << "missing number from array of first " << n << " natural number is " << sum - LocalSum << endl;
	cout << "***************************" << endl << endl;


	//Missing element from sorted array
	cout << "to find single missing element" << endl; 
	int arr[10] = { 6,7,8,9,10,12,13,14,15,16 };
	findMissingElement(arr, 10);
	cout << "***************************" << endl << endl;

	//Finding multiple missing elements
	cout << "to find multiple missing element" << endl; 
	int marr[10] = { 6,7,8,9,11,12,15,17,18,19 };
	display(marr,10);
	findMissingElement(marr, 10);
	cout << "***************************" << endl << endl;


	//finding missing from array not sorted
	cout << "finding missing from unsorted" << endl;
	int uarr[10] = { 0,2,1,8,7,11,4,9,12,14 };
	display(uarr,10);
	findMissingElement(uarr,10);
	cout << "***************************" << endl << endl;



	//find duplicates in an array
	cout << "code for finding duplicates in an array with their count also" << endl;
	int Sarr[10] = { 10,12,15,15,23,27,31,31,31,52};    //sorted array
	findDuplicatesAndCount(Sarr,10);
	int UnsortedArr[10] = { 12,21,32,21,11,45,11,17,11,17 };
	findDuplicatesAndCount(UnsortedArr,10);
	cout << "***************************" << endl << endl;

	//finding pair of elements with sum =k;
	cout << "code for finding pair with K as sum" << endl;
	display(Narr, 10);
	int k;
	cout << "enter sum " << endl;
	cin >> k;
	check_For_Pair_With_Sum_As_K(Narr,10,k);
	cout << "***************************" << endl << endl;

	//finding max and min in single scan
	cout << "code for max and min in single scan" << endl;
	int max, min;
	display(Narr, 10);
	findMaxAndMin(Narr,max,min,10);
	cout <<"max  "<<  max << endl;
	cout << "min " << min << endl;
}