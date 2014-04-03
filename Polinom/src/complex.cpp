#include "complex.h"
#include <iostream>

using namespace std;

Complex::Complex(double a,double b):x(a),y(b){};

double Complex:: real() const{
	return x;
}

double Complex::imag() const{
	return y;
}

void Complex::print() const{
	//Complex t;
	cout << real();
	if(imag() > 0)
		cout<<'+';
	cout << imag() << 'i' << endl;
}

ostream& operator <<(ostream&out,const Complex&z){
	out << z.real();
	if (z.imag() > 0)
		cout << '+';
	if (z.imag() != 0)
	    cout << z.imag() << 'i';
	return out;
}

Complex& Complex::operator +=(Complex z){
	x += z.x;
	y += z.y;
	return *this;
}

Complex& Complex::operator *=(Complex z){
	double tmp_x = x*z.x-y*z.y;
	y = x*z.y+z.x*y;
	x = tmp_x;
	return *this;
}

Complex& Complex::operator -=(Complex z){
	x -= z.x;
	y -= z.y;
	return *this;
}

Complex& Complex::operator/=(Complex z){
	double tmp_x = (x*z.x + y*z.y)/(z.x*z.x + z.y*z.y);
	y = (y*z.x - x*z.y)/(z.x*z.x + z.y*z.y);
	x = tmp_x;
	return *this;
}

Complex operator+(Complex z1, Complex z2){
	Complex z(z1);
	z += z2;
	return z;
}
Complex operator-(Complex z1, Complex z2){
	Complex z(z1);
	z -= z2;
	return z;
}

Complex operator*(Complex z1, Complex z2){
	Complex z(z1);
	z *= z2;
	return z;
}

bool operator==(Complex z1, Complex z2){
	if ((z1.imag() == z2.imag()) && (z1.real() == z2.imag()))
		return true;
	else 
		return false;
}

bool operator!=(Complex z1, Complex z2){
	return !(z1 == z2);
}

Complex Complex::operator ^(int deg) const{
	if (deg==0)
		return Complex(1);

	Complex zn(1);
	for (int i = 1; i <= deg; i++)
		zn *= *this;
	return zn;
}