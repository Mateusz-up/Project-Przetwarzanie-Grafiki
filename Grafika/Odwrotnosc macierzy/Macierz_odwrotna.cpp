#include<iostream>
#include<cmath>

using namespace std;

void zapisywanie_macierzy(double **macierz, int wiersze, int kolumny)
{
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)

		{
			cin >> macierz[i][j];
		}

		cout << endl;
	}
}

void wyswietlanie_macierzy(double **macierz, int wiersze, int kolumny)
{
	cout << "\n" << endl;
	for (int i = 0; i < wiersze; i++)
	{
		for (int j = 0; j < kolumny; j++)
		{

			cout << macierz[i][j] << '\t';
		}
		cout << endl;
	}
	cout << "\n" << endl;
}

double** odwracanie_macierzy(double **m)
{
	int wiersze = 3;
	int kolumny = 3;

	double** pom_m = new double*[wiersze];

	for (int i = 0; i < kolumny; i++)
	{
		pom_m[i] = new double[kolumny];
	}

	double det = (m[0][0] * m[1][1] * m[2][2] + m[0][1] * m[1][2] * m[2][0] + m[0][2] * m[1][0] * m[2][1]);
	det -= (m[0][2] * m[1][1] * m[2][0] + m[0][0] * m[1][2] * m[2][1] + m[0][1] * m[1][0] * m[2][2]);

	cout << "Wyznacznik jest rowny= " << det << endl;


	if (det == 0)
	{
		cout << "\nWyznaczkik jest rowny 0,nie istnieje macierz odwrotna! \n" << endl;
		system("pause");
		exit(0);
	}

	else
	{
		cout << "\nMacierz odwrotna";

		double tab[9];

		tab[0] = pow(-1, 2)*(m[1][1] * m[2][2] - m[1][2] * m[2][1]);
		tab[1] = pow(-1, 3)*(m[1][0] * m[2][2] - m[1][2] * m[2][0]);
		tab[2] = pow(-1, 4)*(m[1][0] * m[2][1] - m[1][1] * m[2][0]);

		tab[3] = pow(-1, 3)*(m[0][1] * m[2][2] - m[0][2] * m[2][1]);
		tab[4] = pow(-1, 4)*(m[0][0] * m[2][2] - m[0][2] * m[2][0]);
		tab[5] = pow(-1, 5)*(m[0][0] * m[2][1] - m[0][1] * m[2][0]);

		tab[6] = pow(-1, 4)*(m[0][1] * m[1][2] - m[0][2] * m[1][1]);
		tab[7] = pow(-1, 5)*(m[0][0] * m[1][2] - m[0][2] * m[1][0]);
		tab[8] = pow(-1, 6)*(m[0][0] * m[1][1] - m[0][1] * m[1][0]);


		pom_m[0][0] = tab[0] / det;
		pom_m[0][1] = tab[3] / det;
		pom_m[0][2] = tab[6] / det;

		pom_m[1][0] = tab[1] / det;
		pom_m[1][1] = tab[4] / det;
		pom_m[1][2] = tab[7] / det;

		pom_m[2][0] = tab[2] / det;
		pom_m[2][1] = tab[5] / det;
		pom_m[2][2] = tab[8] / det;

		return pom_m;
	}
}
int main(void) {
	
	int wiersze = 3;
	int kolumny = 3;

	double** macierz = new double*[wiersze];

	for (int i = 0; i < kolumny; i++)
	{
		macierz[i] = new double[kolumny];
	}

	cout << "Wprowadz macierz (3x3)" << endl;

	zapisywanie_macierzy(macierz, wiersze, kolumny);

	cout << "  Macierz  ";

	wyswietlanie_macierzy(macierz, wiersze, kolumny);


	wyswietlanie_macierzy(odwracanie_macierzy(macierz), wiersze, kolumny);


	system("pause");

}