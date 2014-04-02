#ifndef BIGINT_H
#define BIGINT_H

#include <vector>

using namespace std;

class BigInt{
	int length;
	short sign;
	vector<short> digits;
	
public:
	BigInt();
	BigInt(int, short, vector<short>&);
	BigInt(const BigInt&); 
	~BigInt();
	int len() const;
	void print();	
	BigInt& operator+=(const BigInt&);
	BigInt& operator-=(const BigInt&);
	BigInt& operator*=(const BigInt&);
	BigInt& operator/=(const BigInt&);
	BigInt& operator^=(const BigInt&);
    BigInt& operator=(BigInt&);
};
BigInt operator+(const BigInt&, const BigInt&);
BigInt operator-(const BigInt&, const BigInt&);
BigInt operator*(const BigInt&, const BigInt&);
BigInt operator/(const BigInt&, const BigInt&);
BigInt operator^(const BigInt&, const BigInt&);

#endif BIGINT_H