#include <iostream>
#include "TimeStamp.h"

using namespace std;

int main(){
    timeStamp T_1(2,56,34);
    timeStamp T_2(13,42,1);

    cout << T_1 - T_2 << endl;
    return 0;
}