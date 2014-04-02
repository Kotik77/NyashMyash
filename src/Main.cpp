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
    N -= N;

	/*std::vector<int> myvector;

	// set some values:
	for (int i = 1; i<10; ++i) myvector.push_back(i);   // 1 2 3 4 5 6 7 8 9

	std::reverse(myvector.begin(), myvector.end());    // 9 8 7
	std::cout << "myvector contains:";
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';*/

    N2.print();
}
