#include "complex.h"
#include "poly.h"

#include <iostream>

void main()
{
	//Complex t(1,2);
	
	//t.print();
	//Complex z1(-3,5);
	//Complex z2(-3,2);
	//Complex z3(1,1);
	/*z1 +=z2;
	std::cout<<z1.real()<<"+"<<z1.imag()<<"*i"<<std::endl;*/

	int deg1 = 5; int deg2 = 1, deg3 = 1;
	double coef[] = {1,0,0,0,0}, coef2[] = {1,2}, coef3[] = {1,1};

	Polynom P(deg1, coef);
	Polynom Q(deg2, coef2);
	Polynom R(deg3, coef3);
	Polynom m;
	P/=Q;
	P.print();
	/*P += Q;
	P.print();
	Q *= R;
	Q.print();


	P=Q;
	P.print();
*/
	//Complex z;
	//z = z1*(z2+z3);
	////z.print();
	/*int deg1 = 2; int deg2 = 2, deg3 = 3;
	double coef1[] = {1,1,1}, coef2[] = {1,1,1}, coef3[] = {-4,0,0,3};

	Polynom P1(deg1, coef1);*/
	/*Polynom P2(deg2, coef2);
	Polynom P3(deg3, coef3);
	
	std::cout<<(P1==P2)<<std::endl;*/
	//Polynom T;
	//T = P1*P2+P3;
	//T.print();

	//std::cout<<"z1==z2 "<<(z1==z2)<<std::endl;
	
	/*double cf[] = {3,2,1};
	Polynom W(2,cf);
	Complex Wz;
	Wz = W(Complex());
	std::cout<<"Wz(0)= "<< Wz.real()<<"+"<<Wz.imag()<<"*i"<<std::endl;
	Wz = W(Complex(1));
	std::cout<<"Wz(1)= "<< Wz.real()<<"+"<<Wz.imag()<<"*i"<<std::endl;
	Wz = W(Complex(5,2));
	std::cout<<"Wz(5.2)= "<< Wz.real()<<"+"<<Wz.imag()<<"*i"<<std::endl;*/
	system("pause");

}