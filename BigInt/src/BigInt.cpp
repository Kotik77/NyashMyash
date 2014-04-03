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
		digits[length - i - 1] = arr[i];  //переворачиваем число
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
	for (vector<short>::reverse_iterator it = digits.rbegin(); it != digits.rend(); it++) //чтобы пройти по вектору с конца к началу
		cout << *it << " ";
    cout << endl;
}

BigInt& BigInt::operator+=(const BigInt& t){	
	short remainder = 0;
	int maxLen = max(length, t.length);

	for (int i = 0; i < maxLen || remainder; i++){
		if (i == length){
			digits.push_back(0);
			length++;
		}
		digits[i] += remainder + (i < t.length ? t.digits[i] : 0);
		remainder = digits[i] / 10;
		if (remainder)  
            digits[i] -= 10;
	}
	return *this;
}

BigInt& BigInt::operator*=(const BigInt& t){
	if (length == 1 && digits[0] == 0 || t.length == 1 && t.digits[0] == 0){
		length = 1;
		digits.clear();
		return *this;
	}
	else{		
		short remainder = 0;
		vector<short> res;		
		res.resize(length + t.length);

		for (int i = 0; i < length; i++)
		for (int j = 0; j < t.length || remainder; j++){
			short cur = res[i + j] + digits[i] * (j < t.length ? t.digits[j] : 0) + remainder;
			res[i + j] = cur % 10;
			remainder = cur / 10;
		};
				
		length += t.length;
		if (res.back() == 0){
			res.pop_back();
			length--;
		}					
		
		digits = res;
		return *this;
	}
}

BigInt& BigInt::operator=(const BigInt& t){
	length = t.length;
	sign = t.sign;
	digits.clear();
	for (int i = 0; i < length; i++)
		digits.push_back(t.digits[i]);
	return *this;
}