#include "matrix.h"
using namespace matrix;

Matrix2D::Matrix2D(int row, int col)
{
	m_row = row;
	m_col = col;
}

Matrix2D::~Matrix2D()
{

}

void Matrix2D::SetValueAt(int row, int col, int num)
{
	m_matrix[row][col] = num;
}

int Matrix2D::GetValueAt(int row, int col)
{
	if (row > 0 && row < m_row && col > 0 && col < m_col) return m_matrix[row][col];
	cout << "Invalid index of matrix" << endl;
}

void Matrix2D::Zeros()
{
	for (int ii = 0; ii < m_row; ii = ii + 1)
	{
		for (int jj = 0; jj < m_col; jj = jj + 1)
		{
			m_matrix[ii][jj] = 0;
		}
	}
}

void Matrix2D::Diag(int num)
{
	if (m_row != m_col) cout << "Incorrect dimentsions to create diagonal matrix." << endl;
	else
	{
		for (int ii = 0; ii < m_row; ii = ii + 1)
		{
			for (int jj = 0; jj < m_col; jj = jj + 1)
			{
				if (ii == jj) m_matrix[ii][jj] = num;
				else m_matrix[ii][jj] = 0;
			}
		}
	}
}

void Matrix2D::Show()
{
	for (int ii = 0; ii < m_row; ii = ii + 1)
	{
		for (int jj = 0; jj < m_col; jj = jj + 1)
		{
			cout << m_matrix[ii][jj] << " ";
		}
		cout << endl;
	}
	cout << endl;
}

void Matrix2D::Show(int index, char mode)
{
	if (index >= 0 && index < m_row && mode == 'r')
	{
		for (int jj = 0; jj < m_col; jj = jj + 1)
		{
			cout << m_matrix[index][jj] << " ";
		}
		cout << endl;
	}
	else if (index >= 0 && index < m_col && mode == 'c')
	{
		for (int ii = 0; ii < m_row; ii = ii + 1)
		{
			cout << m_matrix[ii][index] << endl;
		}
		cout << endl;
	}
	else cout << "Invalid index of row, column, or read mode, read mode must be 'r' or 'c'." << endl;
	
}

Matrix2D Matrix2D::operator + (Matrix2D obj)
{
	if (m_row != obj.m_row || m_col != obj.m_col)
	{
		cout << "Incorrect dimensions for matrix addition." << endl;
	}

	else
	{
		Matrix2D res(m_row, m_col);
		for (int ii = 0; ii < m_row; ii = ii + 1)
		{
			for (int jj = 0; jj < m_col; jj = jj + 1)
			{
				res.m_matrix[ii][jj] = m_matrix[ii][jj] + obj.m_matrix[ii][jj];
			}
		}

		return res;
	}
}

Matrix2D Matrix2D::operator - (Matrix2D obj)
{
	//int row = m_row;
	//int col = m_col;
	//cout << row << " " << col << endl;
	if (m_row != obj.m_row || m_col != obj.m_col)
	{
		cout << "Incorrect dimensions for matrix subtraction." << endl;
	}

	else
	{
		Matrix2D res(m_row, m_col);
		for (int ii = 0; ii < m_row; ii = ii + 1)
		{
			for (int jj = 0; jj < m_col; jj = jj + 1)
			{
				res.m_matrix[ii][jj] = m_matrix[ii][jj] - obj.m_matrix[ii][jj];
			}
		}

		return res;
	}
}

Matrix2D Matrix2D::operator * (Matrix2D obj)
{
	//int row = m_row;
	//int col = m_col;
	//cout << row << " " << col << endl;
	if (m_col != obj.m_row)
	{
		cout << "Incorrect dimensions for matrix multiplication." << endl;
	}
	else
	{
		Matrix2D res(m_row, obj.m_col);
		res.Zeros();
		for (int ii = 0; ii < m_row; ii = ii + 1)
		{
			for (int jj = 0; jj < obj.m_col; jj = jj + 1)
			{
				for (int kk = 0; kk < m_col; kk = kk + 1)
				{
					res.m_matrix[ii][jj] = res.m_matrix[ii][jj] + m_matrix[ii][kk] * obj.m_matrix[kk][jj];
				}
			}
		}

		return res;
	}
}

