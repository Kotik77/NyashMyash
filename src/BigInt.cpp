#include <iostream>
#include <algorithm>
#include <vector>
#include "BigInt.h"

using namespace std;

BigInt::BigInt(){
	length = 0;
	sign = 1;
	digits.resize(length);
}
BigInt::BigInt(int l, short s, vector<short> &arr){
	length = l;
	sign = s;
	digits.resize(length);
	for (int i = 0; i < length; i++){
		digits[i] = arr[i];
	}
}
BigInt::BigInt(const BigInt& a){
	length = a.length;
	sign = a.sign;
	digits.resize(length);
	for (int i = 0; i < length; i++)
		digits[i] = a.digits[i];
}
BigInt::~BigInt(){
	digits.clear();
}

int BigInt::len() const{
	return length;
}

void BigInt::print(){
    if (sign == -1)
        cout << "-";
	for (vector<short>::iterator it = digits.begin(); it != digits.end(); it++)
		cout << *it << " ";
}

BigInt& BigInt::operator+=(const BigInt& t){ //must be changed
	short remainder = 0;
	short p;
	int i, j;
    if (t.length > length){
        vector<short> c = t.digits;
		i = length - 1;
		j = t.length - 1;
		for (i, j; i >= 0; i--, j--){
			p = digits[i] + t.digits[j] + remainder;
            c[j] = p % 10;
			remainder = p / 10;
		}
        if (remainder != 0)
            c[t.length - length - 1] += remainder;
        digits = c;
	}
	else{
		i = t.length - 1;
		j = length - 1;
		for (i, j; i >= 0; i--, j--){
			p = digits[j] + t.digits[i] + remainder;
            digits[i] = p % 10;
			remainder = p / 10;
		}
        if (remainder != 0)
            digits.insert(digits.begin(), remainder);
	}
	return *this;
}

BigInt& BigInt::operator-=(const BigInt& t){ //must be changed
    short remainder = 0;
    short p;
    int i, j;
    if (t.length > length || (t.length == length && digits[0] > t.digits[0])){
        vector<short> c = t.digits;
		i = length - 1;
		j = t.length - 1;
		for (i, j; i >= 0; i--, j--){
            p = digits[i] - remainder;
            if (p < t.digits[j]){
                c[j] = p + 10 - t.digits[j];
                remainder = 1;
            }
            else
                c[j] = p - t.digits[j];
		}
        digits = c;
	}
	else{
        sign = -1;
        i = t.length - 1;
		j = length - 1;
		for (i, j; i >= 0; i--, j--){
            p = t.digits[j] - remainder;
            if (p < digits[i] && i != 0){
                digits[j] = p + 10 - digits[i];
                remainder = 1;
            }
            if (p >= digits[i]){
                digits[j] = p - digits[i];
                remainder = 0;
            }
            if (p < digits[i] && i == 0)
                digits[j] = digits[i] - p;
		}
	}

	return *this;
}

BigInt& BigInt::operator=(BigInt& t){
	if (this == &t)
		return *this;
    digits.clear();
    for (vector<short>::iterator h = t.digits.begin(); h != t.digits.end(); h++)
        digits.push_back(*h);
    length = t.length;

    return *this;
}