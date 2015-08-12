#include <iostream>
using namespace std;

void printMatrix(int matrix[][6],int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		cout << endl;
		for (int j = 0; j < col; j++)
		{
			cout << matrix[i][j] << " ";
		}
		
	}
}
void printSpiral(int matrix[][6], int row, int col)
{
	cout << endl << " Spiral Form : " << endl;
	int startingRow = 0, endingRow = row-1, startingCol = 0, endingCol = col-1;
	while ((startingRow <= endingRow) && (startingCol <= endingCol))
	{
		for (int i = startingRow; i <= endingCol; i++)
		{
			cout << matrix[startingRow][i] << " ";

		}
		startingRow++;
		for (int j = startingRow; j <= endingRow; j++)
		{
			cout << matrix[j][endingCol] << " ";

		}
		endingCol--;
		if (startingRow <= endingRow)
		{
			for (int k = endingCol; k > startingCol - 1; k--)
			{
				cout << matrix[endingRow][k] << " ";

			}
			endingRow--;

		}
		if (startingCol <= endingCol)
		{
			for (int l = endingRow; l >= startingRow; l--)
			{
				cout << matrix[l][startingCol] << " ";
			}
			startingCol++;
		}
		
	}



}
void main()
{
	/*{ { 1, 2, 3, 4 },
	{ 5, 6, 7, 8 },
	{ 9, 10, 11, 12 },
	{ 13, 14, 15, 16 } };*/
	
	int matrix[3][6] = { {1, 2, 3, 4, 5, 6 },
							{ 7,8,9,10,11,12 }, 
							{13,14,15,16,17,18 }};
	
	printMatrix(matrix, 3, 6 );
	printSpiral(matrix, 3, 6);
	int test;
	cin >> test;
	
}