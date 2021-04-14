
#pragma once
#include "Macierz.h"
#include "Wektor.h"
#include <cmath>
#include <complex>
#include <cstdarg>


template <int T>
class przeksztalcenia
{
	macierz<T> M_macierz;
public:
	przeksztalcenia();
	macierz<T> macierz_skalowania(float arg);
	macierz<T> macierz_skalowania(float x, float y, float z = 0);
	macierz<T> macierz_skalowania(float tab[]);

	macierz<T> macierz_obrotu(float kat, char os = 'x');
	macierz<T> macierz_obrotu(float kat, wektor<T> os);

	macierz<T> macierz_przesuniecia(float arg);
	macierz<T> macierz_przesuniecia(float x, float y, float z = 0);
	macierz<T> macierz_przesuniecia(float tab[]);
	template <typename ...T2>
	macierz<T> laczenie_transofrmacji(T2 ... t);
	macierz<T> macierz_perspektywy(float kat, float wysokosc, float szerokosc, float bliskieZ, float dalekieZ);
	
	void jedynkowa();
};

template <int T>
przeksztalcenia<T>::przeksztalcenia()
{
	jedynkowa();
}

template <int T>
macierz<T> przeksztalcenia<T>::macierz_skalowania(float arg)
{
	jedynkowa();
	M_macierz[0][0] = arg;
	M_macierz[1][1] = arg;
	if (T == 4)
	{
		M_macierz[2][2] = arg;
	}
	return M_macierz;
}

template <int T>
macierz<T> przeksztalcenia<T>::macierz_skalowania(float x, float y, float z)
{
	jedynkowa();
	M_macierz[0][0] = x;
	M_macierz[1][1] = y;
	if (T == 4)
		M_macierz[2][2] = z;
	return M_macierz;
}

template <int T>
macierz<T> przeksztalcenia<T>::macierz_skalowania(float tab[])
{
	jedynkowa();
	M_macierz[0][0] = tab[0];

	if (T == 4)
	{
		M_macierz[2][2] = tab[2];
	}
	return M_macierz;
}

template <int T>
macierz<T> przeksztalcenia<T>::macierz_obrotu(float kat, char os)
{
	jedynkowa();
	if (T == 4)
	{
		if (os == 'x')
		{
			M_macierz[1][1] = std::cos(kat);
			M_macierz[1][2] = -std::sin(kat);
			M_macierz[2][1] = std::sin(kat);
			M_macierz[2][2] = std::cos(kat);
		}
		else if (os == 'y')
		{
			M_macierz[0][0] = std::cos(kat);
			M_macierz[0][2] = std::sin(kat);
			M_macierz[2][0] = -std::sin(kat);
			M_macierz[2][2] = std::sin(kat);
		}
		else if (os == 'z')
		{
			M_macierz[0][0] = std::cos(kat);
			M_macierz[0][1] = std::sin(kat);
			M_macierz[1][0] = -std::sin(kat);
			M_macierz[1][1] = std::cos(kat);
		}
	}
	else
	{
		M_macierz[0][0] = std::cos(kat);
		M_macierz[0][1] = std::sin(kat);
		M_macierz[1][0] = -std::sin(kat);
		M_macierz[1][1] = std::cos(kat);
	}
	return M_macierz;
}

inline macierz<4> przeksztalcenia<4>::macierz_obrotu(float kat, wektor<4> os)
{
	jedynkowa();
	M_macierz[0][0] = std::cos(kat) + (1 - std::cos(kat)) * os.get_x() * os.get_x();
	M_macierz[0][1] = (1 - std::cos(kat)) * os.get_x() * os.get_y() - std::sin(kat) * os.get_z();
	M_macierz[0][2] = (1 - std::cos(kat)) * os.get_z() * os.get_x() + std::sin(kat) * os.get_y();
	M_macierz[1][0] = (1 - std::cos(kat)) * os.get_x() * os.get_y() + std::sin(kat) * os.get_z();
	M_macierz[1][1] = std::cos(kat) + (1 - std::cos(kat)) * os.get_y() * os.get_y();
	M_macierz[1][2] = (1 - std::cos(kat)) * os.get_y() * os.get_z() - std::sin(kat) * os.get_x();
	M_macierz[2][0] = (1 - std::cos(kat)) * os.get_z() * os.get_x() - std::sin(kat) * os.get_y();
	M_macierz[2][1] = (1 - std::cos(kat)) * os.get_y() * os.get_z() + std::sin(kat) * os.get_x();
	M_macierz[2][2] = std::cos(kat) + (1 - std::cos(kat)) * os.get_z() * os.get_z();
	return M_macierz;
}

template <int T>
macierz<T> przeksztalcenia<T>::macierz_przesuniecia(float arg)
{
	jedynkowa();

	if (T == 4)
	{
		M_macierz[0][3] = arg;
		M_macierz[1][3] = arg;
		M_macierz[2][3] = arg;
	}
	else
	{
		M_macierz[0][2] = arg;
		M_macierz[1][2] = arg;
	}
	return M_macierz;
}

template <int T>
macierz<T> przeksztalcenia<T>::macierz_przesuniecia(float x, float y, float z)
{
	jedynkowa();

	if (T == 4)
	{
		M_macierz[0][3] = x;
		M_macierz[1][3] = y;
		M_macierz[2][3] = z;
	}
	else
	{
		M_macierz[0][2] = x;
		M_macierz[1][2] = y;
	}
	return M_macierz;
}

template <int T>
macierz<T> przeksztalcenia<T>::macierz_przesuniecia(float tab[])
{
	jedynkowa();

	if (T == 4)
	{
		M_macierz[0][3] = tab[0];
		M_macierz[1][3] = tab[1];
		M_macierz[2][3] = tab[2];
	}
	else
	{
		M_macierz[0][2] = tab[1];
		M_macierz[1][2] = tab[2];
	}
	return M_macierz;
}

template <int T>
template <typename ... T2>
macierz<T> przeksztalcenia<T>::laczenie_transofrmacji(T2 ... t)
{
	
	M_macierz= (t * ...);
	
	std::cout << "temp" << (t*...) ;
	
	return (t * ...);
}



template <int T>
macierz<T> przeksztalcenia<T>::macierz_perspektywy(float kat, float wysokosc, float szerokosc, float bliskieZ,
	float dalekieZ)
{
	
	float tablica[4][4]{
		0,0,0,0,
		0,0,0,0,
		0,0,0,0,
		0,0,0,0

	};
	//jedynkowa();
	float n = bliskieZ;
	float f = dalekieZ;
	
	float a = szerokosc / wysokosc;


	tablica[0][0] = 1.0f / (a * std::tanf(naRadiany(kat / 2)));
	tablica[1][1] = 1.0f / std::tanf(naRadiany(kat / 2));
	tablica[2][2] = (-n - f) / (n - f);
	tablica[2][3] = (2.0f * f * n) / (n - f);
	tablica[3][2] = 1.0f;
	tablica[3][3] = 0.0f;
	
	macierz<T> temp1(tablica);
	return temp1;
}

template <int T>
void przeksztalcenia<T>::jedynkowa()
{
	for (int x = 0; x < T; ++x)
		for (int y = 0; y < T; ++y)
			if (x != y)
				this->M_macierz[x][y] = 0;
			else
				this->M_macierz[x][y] = 1;
}
