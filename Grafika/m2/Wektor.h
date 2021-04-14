#pragma once
#include <ostream>

template <int T>
class wektor final
{
	float tab[T];

public:
	wektor();
	wektor(const float x);
	wektor(const float x, const float y, const float z, const float w = 0);
	wektor(float* tab);

	wektor& operator=(const wektor& rwektor);
	wektor& operator+=(const wektor& rwektor);
	wektor& operator+(const wektor& rwektor);
	wektor& operator-(const wektor& rwektor);
	wektor& operator-=(const wektor& rwektor);
	wektor& operator*(const int value);
	wektor& operator*=(const int value);
	float operator[](const int value) const;
	float & operator[](const int value);

	template <int T>
	friend std::ostream& operator<<(std::ostream& os, const wektor& rwektor);

	float get_x() const;
	float get_y() const;
	float get_z() const;
	float get_w() const;

	void set_x(const float x);
	void set_y(const float y);
	void set_z(const float z);
	void set_w(const float w);

	float dlugosc() const;
	void normalizuj();
	static float iloczyn_skalarny(wektor& w1, wektor& w2);
	static wektor& iloczyn_wektorowy(wektor& w1, wektor& w2);
};

template <int T>
wektor<T>::wektor() : wektor<T>(0, 0, 0, 0)
{
}


template <int T>
wektor<T>::wektor(const float x) : wektor<T>(x, x, x, x)
{
}

template <int T>
wektor<T>::wektor(const float x, const float y, const float z, const float w)
{
	this->set_x(x);
	this->set_y(y);
	this->set_z(z);
	this->set_w(w);
}

template <int T>
wektor<T>::wektor(float* tab) :wektor(tab[0], tab[1], tab[2])
{
	if (T == 4)
	{
		set_w(tab[3]);
	}
}

template <int T>
wektor<T>& wektor<T>::operator=(const wektor& rwektor)
{
	if (this != &rwektor)
	{
		this->set_x(rwektor.get_x());
		this->set_y(rwektor.get_y());
		this->set_z(rwektor.get_z());
		if (T == 4)
			this->set_w(rwektor.get_w());
	}
	return *this;
}

template <int T>
wektor<T>& wektor<T>::operator+(const wektor<T>& rwektor)
{
	this->operator+=(rwektor);
	return *this;
}

template <int T>
wektor<T>& wektor<T>::operator+=(const wektor<T>& rwektor)
{
	this->set_x(this->get_x() + rwektor.get_x());
	this->set_y(this->get_y() + rwektor.get_y());
	this->set_z(this->get_z() + rwektor.get_z());
	if (T == 4)
		this->set_w(this->get_w() + rwektor.get_w());

	return *this;
}

template <int T>
wektor<T>& wektor<T>::operator-(const wektor& rwektor)
{
	this->operator-=(rwektor);
	return *this;
}

template <int T>
wektor<T>& wektor<T>::operator-=(const wektor& rwektor)
{
	this->set_x(this->get_x() - rwektor.get_x());
	this->set_y(this->get_y() - rwektor.get_y());
	this->set_z(this->get_z() - rwektor.get_z());
	if (T == 4)
		this->set_w(this->get_w() - rwektor.get_w());
	return *this;
}

template <int T>
wektor<T>& wektor<T>::operator*(const int value)
{
	this->operator*=(value);
	return *this;
}

template <int T>
wektor<T>& wektor<T>::operator*=(const int value)
{
	this->set_x(this->get_x() * value);
	this->set_y(this->get_y() * value);
	this->set_z(this->get_z() * value);
	if (T == 4)
		this->set_w(this->get_w() * value);

	return *this;
}

template <int T>
float wektor<T>::operator[](const int value) const
{
	switch (value)
	{
	case 0:
		return this->get_x();
	case 1:
		return this->get_y();
	case 2:
		return this->get_z();
	case 3:
		if (T == 4)
			return this->get_w();
	default:
		return 0;

	}
}

template <int T>
float & wektor<T>::operator[](const int value)
{
	return this->tab[value];
}

template <int T>
std::ostream& operator<<(std::ostream& os, const wektor<T>& wektor)
{
	os << "x:" << wektor.get_x() << " y:" << wektor.get_y() << " z:" << wektor.get_z();
	if (T == 4)
		os << " w:" << wektor.get_w();
	return os;
}

template <int T>
float wektor<T>::get_x() const
{
	return this->tab[0];
}

template <int T>
float wektor<T>::get_y() const
{
	return this->tab[1];
}

template <int T>
float wektor<T>::get_z() const
{
	return this->tab[2];
}

template <int T>
float wektor<T>::get_w() const
{
	return this->tab[3];
}

template <int T>
void wektor<T>::set_x(const float x)
{
	this->tab[0] = x;
}

template <int T>
void wektor<T>::set_y(const float y)
{
	this->tab[1] = y;
}

template <int T>
void wektor<T>::set_z(const float z)
{
	this->tab[2] = z;
}

template <int T>
void wektor<T>::set_w(const float w)
{
	this->tab[3] = w;
}

template <int T>
float wektor<T>::dlugosc() const
{
	const auto x2 = this->get_x() * this->get_x();
	const auto y2 = this->get_y() * this->get_y();
	const auto z2 = this->get_z() * this->get_z();

	if (T == 4)
	{
		const auto w2 = this->get_w() * this->get_w();
		return sqrt(x2 + y2 + z2 + w2);
	}
	return sqrt(x2 + y2 + z2);
}

template <int T>
void wektor<T>::normalizuj()
{
	const auto dl = this->dlugosc();
	this->set_x(this->get_x() / dl);
	this->set_y(this->get_y() / dl);
	this->set_z(this->get_z() / dl);
	if (T == 4)
		this->set_w(this->get_w() / dl);
}

template <int T>
float wektor<T>::iloczyn_skalarny(wektor& w1, wektor& w2)
{
	float x = w1.get_x() * w2.get_x() + w1.get_y() * w2.get_y() + w1.get_z() * w2.get_z();
	if (T == 4)
		x += w1.get_w() * w2.get_w();
	return x;
}

template <int T>
wektor<T>& wektor<T>::iloczyn_wektorowy(wektor& w1, wektor& w2)
{
	wektor<T> w3;
	w3.set_x(w1.get_y() * w2.get_z() - w1.get_z() * w2.get_y());
	w3.set_y(w1.get_z() * w2.get_x() - w1.get_x() * w2.get_z());
	w3.set_z(w1.get_x() * w2.get_y() - w1.get_y() * w2.get_x());
	return w3;
}
