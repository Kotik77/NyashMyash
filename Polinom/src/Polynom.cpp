#include "complex.h"
#include "Polinom.h"
#include <cstring>
#include <iostream>

using namespace std;

Polynom::Polynom(int deg){
		n = deg;
		p = new double[n + 1];
}

Polynom::Polynom(int deg, double *arr){
	n = deg;
	p = new double[n + 1];

	for(int i = 0; i <= n; i++)
		p[i] = arr[i];
}

Polynom::Polynom(const Polynom& t){
	n = t.degree();
	p = new double[n + 1];

	for(int i = 0; i <= n; i++)
		p[i] = t.p[i];
}

int Polynom::degree()const{
	return n;
}

Polynom::~Polynom(){
	delete[] p;
}

void Polynom::print() const{
	for (int i = 0; i <= n; i++)
		std::cout << p[i] << "\t";
	std::cout << std::endl;
}

Polynom& Polynom::operator+=(const Polynom&P){
//степень полинома слева меньше 
	if(n < P.n){
		//выделение памяти для хранения суммы
		double *tmp_p = new double[P.n+1];
		//переписывание коэф исходного и заполняем нулями при старших коэф
		for (int i = 0; i<P.n+1; i++){
			if (i < P.n-n)
				tmp_p[i] = 0;
			else tmp_p[i] = p[i-P.n+n];
		}
		//измение значений степени и указателя на массив коэф
		n = P.n;
		delete []p;
		p = tmp_p;
	}
	//сложение при одинаковых степенях
	for (int k = n-P.n; k<=n; k++)
		p[k] +=P.p[k-n+P.n];
	return *this;
}

Polynom& Polynom::operator -=(const Polynom &P){
	if(n < P.n){
		//выделение памяти для хранения суммы
		double *tmp_p = new double[P.n+1];
		//переписывание коэф исходного и заполняем нулями при старших коэф
		for (int i = 0; i<P.n+1; i++){
			if (i < P.n-n)
				tmp_p[i] = 0;
			else tmp_p[i] = p[i-P.n+n];
		}
		//измение значений степени и указателя на массив коэф
		n = P.n;
		delete []p;
		p = tmp_p;
	}
	// при одинаковых степенях
	for (int k = n-P.n; k<=n; k++)
		p[k] -=P.p[k-n+P.n];
	return *this;
}

Polynom& Polynom::operator /=(const Polynom &P){
	double tmp_c = p[n];
	double tmp_ost  = 0;
	int tmp = n - P.n ;
	double *tmp_p = new double [tmp + 1];
	for (int i = 0; i < tmp + 1; i++){
		tmp_p [i] = 0;
		for (int j = 1; j < tmp + 1; j++){
			tmp_p[0] = p[0];
			tmp_p[j] = p[j]+P[tmp+1]*tmp_p[j-1];	
			
		}
		tmp_ost = p[n] + tmp_p[tmp+1]*P[tmp];
	}
	p = tmp_p;
	std::cout << "The remainder is: "<< tmp_ost << std::endl;
	return *this;
}

Polynom& Polynom::operator *=(const  Polynom &P){
	int tmp = n+ P.n;
	double *tmp_p = new double[tmp+1];
	for (int i = 0; i <= tmp;i++){
		tmp_p[i] = 0;
		for (int k= max(0,i-P.n);k <= min(i,n);k++)
			tmp_p[i]+=p[k]*P.p[i-k];
	}
	n = tmp;
	delete []p;
	p = tmp_p;
	return *this;	
}

Polynom& Polynom::operator=(const Polynom &P){
	//проверка самоприсваивания
	if (this == &P)
		return *this;
	double *tmp_p = new double [P.n+1];
	//copy coef
	for (int i = 0;i<=P.n;i++)
		tmp_p[i] = P.p[i];
	//change obj
	n = P.n;
	delete []p;
	p = tmp_p;
	return *this;
}

Polynom operator+(const Polynom& P1, const Polynom& P2){
	Polynom P(P1);
	P += P2;
	return P;
}

Polynom operator*(const Polynom& P1, const Polynom& P2){
	Polynom P(P1);
	P *= P2;
	return P;
}

double Polynom::operator [](int i) const{
	if (i < 0) 
        i = 0;
	if (i > n) 
        i = n;
	return p[i];
}

double& Polynom::operator[](int i){
	if (i < 0) 
        i = 0;
	if (i > n) 
        i = n;
	return p[i];
}

bool operator==(const Polynom& P1, const Polynom& P2){
	if (P1.degree() != P2.degree())
		return false;
	for (int i=0; i<=P1.degree();i++)
		if (P1[i] != P2[i])
			return false;
	return true;
}

bool operator!=(const Polynom& P1, const Polynom& P2){
	return !(P1 == P2);
}

Complex Polynom::operator() (Complex z) const {
	Complex Pz;
	for (int i=0; i <=n; i++)
		Pz += p[i]*(z^(n-i));
	return Pz;
}