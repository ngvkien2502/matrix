#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include "matrix.h"
using namespace matrix;
//using namespace std;

int main()
{
	freopen("input.txt", "r", stdin);

	int T;
	int row, col;
	int temp;
	
	cin >> T;
	for (int tc = 0; tc < T; tc = tc + 1)
	{
		cout << "#" << tc + 1 << ":" << endl;

		cin >> row >> col;
		Matrix2D mat1(row, col);
		for (int ii = 0; ii < row; ii = ii + 1)
		{
			for (int jj = 0; jj < col; jj = jj + 1)
			{
				cin >> temp;
				mat1.SetValueAt(ii, jj, temp);
			}
		}

		cin >> row >> col;
		Matrix2D mat2(row, col);
		for (int ii = 0; ii < row; ii = ii + 1)
		{
			for (int jj = 0; jj < col; jj = jj + 1)
			{
				cin >> temp;
				mat2.SetValueAt(ii, jj, temp);
			}
		}
		cout << "Matrix 1:" << endl;
		mat1.Show();
		cout << "Matrix 2:" << endl;
		mat2.Show();
		
		Matrix2D sumMat = mat1 + mat2;
		cout << "Sum of matrices:" << endl;
		sumMat.Show();

		cin >> row >> col;
		Matrix2D mat3(row, col);
		for (int ii = 0; ii < row; ii = ii + 1)
		{
			for (int jj = 0; jj < col; jj = jj + 1)
			{
				cin >> temp;
				mat3.SetValueAt(ii, jj, temp);
			}
		}

		cin >> row >> col;
		Matrix2D mat4(row, col);
		for (int ii = 0; ii < row; ii = ii + 1)
		{
			for (int jj = 0; jj < col; jj = jj + 1)
			{
				cin >> temp;
				mat4.SetValueAt(ii, jj, temp);
			}
		}
		cout << "Matrix 1:" << endl;
		mat3.Show();
		cout << "Matrix 2:" << endl;
		mat4.Show();

		Matrix2D multiMat = mat3 * mat4;
		cout << "Multiplication of matrices:" << endl;
		multiMat.Show();
	}

	_getch();
	return 0;
}