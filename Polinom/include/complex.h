#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

class Complex{
	double x,y;
public:
	Complex(double=0,double=0);
	double real() const;
	double imag() const;
	void print() const;
	
Complex& operator+=(Complex);
Complex& operator*=(Complex);
Complex& operator-=(Complex);
Complex& operator/=(Complex);
Complex operator^(int) const;

};

std::ostream& operator<<(std::ostream&, const Complex&);

Complex operator+(Complex, Complex);
Complex operator*(Complex, Complex);
Complex operator-(Complex, Complex);
Complex operator/(Complex, Complex);
bool operator==(Complex, Complex);
bool operator !=(Complex, Complex);


#endif COMPLEX_H