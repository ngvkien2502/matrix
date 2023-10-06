#pragma once
#include <iostream>
using namespace std;

#define MAX 100

namespace matrix
{
	class Matrix2D
	{
	private:
		int m_row, m_col;
		int m_matrix[MAX][MAX];

	public:
		Matrix2D(int row, int col);
		~Matrix2D();

		void SetValueAt(int row, int col, int num);
		int GetValueAt(int row, int col);

		/*Create zeros matrix*/
		void Zeros();
		/*Create diagonal matrix*/
		void Diag(int num);
		/*Show matrix totally*/
		void Show();
		/* Show each row or column of matrix
		* @param index: index of row or column;
		* mode: 'r': row or 'c': column.
		*/
		void Show(int index, char mode);

		/*Matrix addition*/
		Matrix2D operator + (Matrix2D obj);
		/*Matrix subtraction*/
		Matrix2D operator - (Matrix2D obj);
		/*Matrix multiplication*/
		Matrix2D operator * (Matrix2D obj);
	};
}