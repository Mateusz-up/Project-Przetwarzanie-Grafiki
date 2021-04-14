#pragma once
#include <iostream>
#include <math.h>

template<class...>class Wektor;

template<>
class Wektor<float, float, float>
{
	float x; float y; float z;

public:
	Wektor()
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
	}

	Wektor(float x)
	{
		this->x = x;
		this->y = x;
		this->z = x;
	}

	Wektor(float x, float y, float z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	Wektor(float *tablica)
	{
		this->x = tablica[0];
		this->y = tablica[1];
		this->z = tablica[2];


	}

	Wektor& operator=(Wektor& vector)
	{
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;

		return *this;

	}

	friend Wektor& operator+(Wektor& vector1, Wektor& vector2)
	{
		Wektor wektor(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z);
		return wektor;
	}

	Wektor& operator+=(Wektor& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		return *this;

	}

	friend Wektor& operator-(Wektor& vector1, Wektor& vector2)
	{
		Wektor wektor(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z);
		return wektor;
	}


	Wektor& operator-=(Wektor& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		return *this;

	}

	friend Wektor& operator*(Wektor& vector1, Wektor& vector2)
	{
		Wektor wektor(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z);
		return wektor;
	}

	Wektor& operator*=(Wektor& vector)
	{
		this->x *= vector.x;
		this->y *= vector.y;
		this->z *= vector.z;
		return *this;

	}

	friend std::ostream& operator<<(std::ostream& wyjscie, Wektor& vector)
	{
		wyjscie << "x: " << vector.x << "y: " << vector.y << "z: " << vector.z;
		return wyjscie;
	}


	float getX()
	{


		return x;
	}
	float getY()
	{


		return y;
	}
	float getZ()
	{


		return z;
	}

	void setX(float x)
	{

		this->x = x;

	}
	void setY(float y)
	{

		this->y = y;

	}
	void setZ(float z)
	{

		this->z = z;

	}


	float dlugosc_wektora()
	{
		return sqrt(this->x*this->x + this->y*this->y + this->z*this->z);

	}

	void normalizacja_wektora()
	{
		float dlugosc = dlugosc_wektora();
		this->x /= dlugosc;
		this->y /= dlugosc;
		this->z /= dlugosc;

	}

	float iloczyn_skalarny(Wektor& vector)
	{
		return this->x*vector.x + this->y*vector.y + this->z*vector.z;

	}

	Wektor& iloczyn_wektorowy(Wektor vec1, Wektor vec2) {
		Wektor wektor((vec1.y*vec2.z) - (vec2.y*vec1.z), (vec1.x*vec2.z) - (vec2.x*vec1.z), (vec1.y*vec2.y) - (vec2.x*vec1.y));
		return wektor;
	}
};



template<>
class Wektor<float, float, float, float>
{
	float x; float y; float z; float w;

public:
	Wektor() {
		this->x = 0;
		this->y = 0;
		this->z = 0;
		this->w = 0;
	}
	Wektor(float x) {
		this->x = x;
		this->y = x;
		this->z = x;
		this->w = x;
	}
	Wektor(float x, float y, float z, float w) {
		this->x = x;
		this->y = y;
		this->z = z;
		this->w = w;

	}

	Wektor(float *tablica)
	{
		this->x = tablica[0];
		this->y = tablica[1];
		this->z = tablica[2];
		this->w = tablica[3];


	}
	Wektor& operator=(Wektor& vector)
	{
		this->x = vector.x;
		this->y = vector.y;
		this->z = vector.z;
		this->w = vector.w;

		return *this;

	}

	friend Wektor& operator+(Wektor& vector1, Wektor& vector2)
	{
		Wektor wektor(vector1.x + vector2.x, vector1.y + vector2.y, vector1.z + vector2.z, vector1.w + vector2.w);

		return wektor;
	}


	Wektor& operator+=(Wektor& vector)
	{
		this->x += vector.x;
		this->y += vector.y;
		this->z += vector.z;
		this->w += vector.w;
		return *this;

	}

	friend Wektor& operator-(Wektor& vector1, Wektor& vector2)
	{
		Wektor wektor(vector1.x - vector2.x, vector1.y - vector2.y, vector1.z - vector2.z, vector1.w - vector2.w);

		return wektor;
	}

	Wektor& operator-=(Wektor& vector)
	{
		this->x -= vector.x;
		this->y -= vector.y;
		this->z -= vector.z;
		this->w -= vector.w;
		return *this;

	}


	friend Wektor& operator*(Wektor& vector1, Wektor& vector2)
	{
		Wektor wektor(vector1.x * vector2.x, vector1.y * vector2.y, vector1.z * vector2.z, vector1.w * vector2.w);
		return wektor;
	}



	Wektor& operator*=(Wektor& vector)
	{
		this->x *= vector.x;
		this->y *= vector.y;
		this->z *= vector.z;
		this->w *= vector.w;
		return *this;

	}

	friend std::ostream& operator<<(std::ostream& wyjscie, Wektor& vector)
	{
		wyjscie << "x:" << vector.x << " y:" << vector.y << " z:" << vector.z << " w:" << vector.w;
		return wyjscie;
	}


	float getX()
	{


		return x;
	}
	float getY()
	{


		return y;
	}
	float getZ()
	{


		return z;
	}
	float getW()
	{


		return w;
	}
	void setX(float x)
	{

		this->x = x;

	}
	void setW(float w)
	{

		this->w = w;

	}
	void setY(float y)
	{

		this->y = y;

	}
	void setZ(float z)
	{

		this->z = z;

	}


	float dlugosc_wektora()
	{
		return sqrt(this->x*this->x + this->y*this->y + this->z*this->z + this->w*this->w);

	}

	void normalizacja_wektora()
	{
		float dlugosc = dlugosc_wektora();
		this->x /= dlugosc;
		this->y /= dlugosc;
		this->z /= dlugosc;
		this->w /= dlugosc;

	}

	float iloczyn_skalarny(Wektor& vector)
	{
		return this->x*vector.x + this->y*vector.y + this->z*vector.z + this->w*vector.w;

	}

	Wektor iloczyn_wektorowy(Wektor& vec1, Wektor& vec2) {
		Wektor wektor(vec1.y*vec2.z - vec2.y*vec1.z, vec1.x*vec2.z - vec2.x*vec1.z, vec1.y*vec2.y - vec2.x*vec1.y, 0);
		return wektor;
	}
};













