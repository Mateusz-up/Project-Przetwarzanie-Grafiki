#pragma once
#include "Wektor.h"

using namespace std;

template<int rozmiar>
class macierz {

private:

	float rodzaj;
	float tablica[rozmiar][rozmiar];


public:

	macierz(void);
	macierz(float x);
	macierz(float tablica[rozmiar][rozmiar]);
	typedef float(*Type)[rozmiar][rozmiar];
	Type getTab() { return &tablica; }
	float* getRow(int x);
	macierz<rozmiar> &operator=(const macierz &M);
	macierz<rozmiar> &operator+(const macierz &M);
	macierz<rozmiar> &operator+=(const macierz &M);
	macierz<rozmiar> &operator-(const macierz &M);
	macierz<rozmiar> &operator-=(const macierz &M);
	macierz<rozmiar> operator*(const macierz &M);
	macierz<rozmiar> &operator*=(const macierz &M);
	macierz<rozmiar> &operator*(int liczba);
	macierz<rozmiar> &operator*=(int liczba);
	wektor<rozmiar >& operator*(wektor<rozmiar>& W);
	float& operator[](int x) const;
	float* operator[](int x);
	void setEl(int x, int y, float wartosc);
	float getEl(int x, int y);


	void usunWierszKolumne(float** tab, float** res_tab, const int wiersz, const int kolumna, const int wymiar_x, const int wymiar_y);
	float obliczWyznacznik(float **tab, int wymiar);
	void macierzDopelnien(float **tab, float **resTab);
	void transpozycja();
	void transpozycja(float** tablica);
	void odwracanie();


	friend ostream& operator<<(ostream& wy, const macierz& M)
	{
		for (int i = 0; i < rozmiar; i++)
		{
			for (int j = 0; j < rozmiar; j++)
			{
				wy << M.tablica[i][j] << "\t";
			}
			wy << "\n";
		}
		return wy;
	};
};


template <int rozmiar>


void macierz<rozmiar>::usunWierszKolumne(float** tab, float** res_tab, const int wiersz, const int kolumna, const int wymiar_x, const int wymiar_y)
{
	for (int i = 0, j = 0; i < wymiar_x - 1; ++i, ++j)
	{
		if (i == wiersz)
			++j;
		for (int k = 0, l = 0; k < wymiar_y - 1; ++k, ++l)
		{
			if (k == kolumna && k == l)
				++l;
			res_tab[i][k] = tab[j][l];
		}
	}
}



////    konstruktor bezargumentowy inicjuje tablice zerami

template<int rozmiar>
macierz<rozmiar>::macierz(void) {
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			tablica[i][j] = 0.0;
		}
	}
};


////    konstruktor z parametrem float mo¿e tworzyæ macierz jednostkow¹: macierz<rozmiar>(1)
////    kontruktor ten stworzy macierz, która zostanie wypelniona zerami oprocz przekatnej na której bêd¹ jedynki

template<int rozmiar>
macierz<rozmiar>::macierz(float x) {
	rodzaj = x;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			if (i == j)
				tablica[i][j] = rodzaj;
			else
				tablica[i][j] = 0;
		}
	}
};


template<int rozmiar>
macierz<rozmiar>::macierz(float tablica[rozmiar][rozmiar]) {

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			setEl(i, j, tablica[i][j]);
		}
	}
};

template <int rozmiar>
float* macierz<rozmiar>::getRow(int x)
{
	return this->tablica[x];
}



template<int rozmiar>
macierz<rozmiar> &macierz<rozmiar>::operator=(const macierz &M) {
	rodzaj = M.rodzaj;

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			tablica[i][j] = M.tablica[i][j];
		}
	}
	return *this;
};

template<int rozmiar>
macierz<rozmiar> &macierz<rozmiar>::operator+(const macierz &M) {
	macierz<rozmiar> temp;

	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {

			temp.tablica[i][j] = tablica[i][j] + M.tablica[i][j];
		}
	}
	return temp;
};

template<int rozmiar>
macierz<rozmiar> &macierz<rozmiar>::operator+=(const macierz &M) {


	return this + M;
};

template<int rozmiar>
macierz<rozmiar> &macierz<rozmiar>::operator-(const macierz &M) {
	macierz<rozmiar> temp;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			temp.tablica[i][j] = tablica[i][j] - M.tablica[i][j];
		}
	}
	return temp;
};

template<int rozmiar>
macierz<rozmiar> &macierz<rozmiar>::operator-=(const macierz &M) {

	return this - M;
};

template<int rozmiar>
macierz<rozmiar> macierz<rozmiar>::operator*(const macierz &M) {

	macierz<rozmiar> temp;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			for (int k = 0; k < rozmiar; k++)
				temp.tablica[i][j] += tablica[i][k] * M.tablica[k][j];
		}
	}
	return temp;
};

template<int rozmiar>
macierz<rozmiar> &macierz<rozmiar>::operator*=(const macierz &M) {


	return this * M;
};


template<int rozmiar>
macierz<rozmiar> &macierz<rozmiar>::operator*(int liczba) {

	macierz<rozmiar> temp;
	for (int i = 0; i < rozmiar; i++) {
		for (int j = 0; j < rozmiar; j++) {
			setEl(i, j, this->getEl() * liczba);
		}
	}
	return temp;


};


template<int rozmiar>
macierz<rozmiar> &macierz<rozmiar>::operator*=(int liczba) {

	return this * liczba;
};

template <int rozmiar>
wektor<rozmiar>& macierz<rozmiar>::operator*(wektor<rozmiar>& W)
{
	static wektor<rozmiar>* tempWec = new wektor<rozmiar>;
	int temp = 0;
	for (int i = 0; i < rozmiar; ++i)
	{
		temp = 0;
		for (int j = 0; j < rozmiar; ++j)
			temp += W[j] * (*this->getTab())[i][j];
		(*tempWec)[i] = temp;
	}

	return *tempWec;
}

template <int rozmiar>
float& macierz<rozmiar>::operator[](int x) const
{
	return this->getRow(x);
}

template <int rozmiar>
float* macierz<rozmiar>::operator[](int x)
{
	return this->getRow(x);
}



template<int rozmiar>
void macierz<rozmiar>::setEl(int x, int y, float wartosc)
{
	if ((x >= 0) && (x <= rozmiar) && (y >= 0) && (y <= rozmiar))
		tablica[x][y] = wartosc;
};


template<int rozmiar>
float macierz<rozmiar>::getEl(int x, int y) {

	return tablica[x][y];
};


template<int rozmiar>

void macierz<rozmiar>::transpozycja()
{
	float tempTab[rozmiar][rozmiar];

	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
		{
			tempTab[j][i] = this->getEl(i, j);
		}
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			this->setEl(i, j, tempTab[i][j]);
}

template<int rozmiar>

void macierz<rozmiar>::transpozycja(float** tablica)
{
	float resTab[rozmiar][rozmiar];

	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
		{
			resTab[j][i] = tablica[i][j];
		}
	for (int i = 0; i < rozmiar; i++)
		for (int j = 0; j < rozmiar; j++)
			tablica[i][j] = resTab[i][j];
}



template <int rozmiar>
float macierz<rozmiar>::obliczWyznacznik(float **tab, int wymiar)
{
	float wynik = 0;
	if (wymiar == 1)
		return tab[0][0];

	float** tempTab = new float*[wymiar];

	for (int i = 0; i < wymiar; ++i)
	{
		tempTab[i] = new float[wymiar];
	}

	for (int i = 0; i < wymiar; ++i)
	{
		usunWierszKolumne(tab, tempTab, 0, i, wymiar, wymiar);
		wynik += tab[0][i] * pow(-1, i + 2) * obliczWyznacznik(tempTab, wymiar - 1);
	}

	return wynik;
}

template <int rozmiar>
void macierz<rozmiar>::macierzDopelnien(float **tab, float **resTab)
{
	float** tempTab = new float*[rozmiar];
	for (int i = 0; i < rozmiar; ++i)
	{
		tempTab[i] = new float[rozmiar];
	}

	for (int i = 0; i < rozmiar; ++i)
	{
		for (int j = 0; j < rozmiar; ++j)
		{
			usunWierszKolumne(tab, tempTab, i, j, rozmiar, rozmiar);
			resTab[i][j] = pow(-1, i + j + 2) * obliczWyznacznik(tempTab, rozmiar - 1);
		}
	}
}

template<int rozmiar>
void macierz<rozmiar>::odwracanie()
{

	float** odwrTab = new float*[rozmiar];
	for (int i = 0; i < rozmiar; ++i)
	{
		odwrTab[i] = new float[rozmiar];
		for (int j = 0; j < rozmiar; ++j)
		{
			odwrTab[i][j] = (*this->getTab())[i][j];
		}
	}

	float det = obliczWyznacznik(odwrTab, rozmiar);


	if (det == 0)
	{

		cout << "Wyznaczkik jest rowny 0,nie istnieje macierz odwrotna!";

	}

	else
	{
		float** resTab = new float*[rozmiar];
		for (int i = 0; i < rozmiar; ++i)
			resTab[i] = new float[rozmiar];

		this->macierzDopelnien(odwrTab, resTab);
		this->transpozycja(resTab);

		for (int i = 0; i < rozmiar; ++i)
			for (int j = 0; j < rozmiar; ++j)
				this->setEl(i, j, resTab[i][j] * (1 / det));
	}
}








