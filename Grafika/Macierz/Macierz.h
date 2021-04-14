#pragma once
#define _USE_MATH_DEFINES 
#include <iostream>
#include <math.h>
#include <stdio.h>
#ifndef CMATRIX_H
#define CMATRIX_H



//#define M_PI = 3.14;

template<class T>
class Matrix {
public:
	Matrix(int rows, int cols) {
		setRow(rows);
		setCol(cols);

		data = new T *[rows];

		for (int i = 0; i < row; i++) {
			data[i] = new T[cols];
		}

		for (int i = 0; i < row; i++) {
			for (int j = 0; j < cols; j++) {
				data[i][j] = (T)i * j;
			}
		}
	}

	void print();

	void setRow(int r) {
		row = r;
	}

	void setCol(int c) {
		col = c;
	}

	T &operator()(int row, int col);

private:
	T **data;
	int row, col;
};

template<class T>
void Matrix<T>::print() {
	int i, j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			printf("%.1f    ", (float)data[i][j]);
		}
		printf("\n");
	}
}

template<class T>
T &Matrix<T>::operator()(int row, int col) {
	return data[row][col];
}

#endif // CMATRIX_H

using namespace std;


double naStopnie(double rad) {
	return rad * 180 / M_PI;
}

double naRadiany(double deg) {

	return deg * M_PI / 180;
}


int main() {


	Matrix <float> m(3, 3);

	m.print();


	cout << m(1, 1) << endl;



	cout << naStopnie(10) << endl;
	cout << naRadiany(572.958) << endl;


	return 0;
}