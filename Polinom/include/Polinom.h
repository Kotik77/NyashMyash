#ifndef POLYNOM_H
#define POLYNOM_H
#include "complex.h"

class Polynom{
	double *p;
	int n;

public:
	Polynom(int = 0);
	Polynom(int, double*);
	Polynom(const Polynom&);
	~Polynom();
	int degree() const;
	void print() const;
	
	Polynom& operator +=(const Polynom &);
	Polynom& operator -=(const Polynom &);
	Polynom& operator *=(const Polynom &);
	Polynom& operator =(const Polynom&);
	Polynom& operator /=(const Polynom&);
	//����������
	double &operator[](int); //P[i]
    double operator[](int) const;

	//���������� �������� ������ �������
	Complex operator() (Complex) const;
};

Polynom operator+(const Polynom& P1, const Polynom& P2);
Polynom operator*(const Polynom& P1, const Polynom& P2);
bool operator==(const Polynom&, const Polynom&);
bool operator!=(const Polynom&, const Polynom&);

#endif POLYNOM_H