
#include"Common.h"


/*
excluded from build...
if want to build change the same in properties of this source file
*/


int main()
{
	int row, col;
	cin >> row >> col;
	int** Darr = new int* [row];
	for (int i = 0; i < 3; i++)
		Darr[i] = new int[col];

	for (int i = 0; i < row; i++)
		for (int j = 0; j < col; j++)
			cin >> Darr[i][j];

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
			cout << Darr[i][j] << " ";
		cout << endl;
	}
}