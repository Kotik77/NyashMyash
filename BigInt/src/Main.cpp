#include <iostream>
#include <vector>
#include "BigInt.h"

using namespace std;

void main(){
    int mass[] = {2,5,8,4,3};
    int mass_1[] = {7,2};
    vector<short> arr(mass, mass + 5);
    vector<short> arr1(mass_1, mass_1+2);
	BigInt N(5, 1, arr);
	BigInt N2(2, 1, arr1);
    N *= N2;

    N.print();
}