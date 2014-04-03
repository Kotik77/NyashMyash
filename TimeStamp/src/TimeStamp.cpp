#include <iostream>
#include "TimeStamp.h"

using namespace std;

int timeStamp::operator-(timeStamp& t) const{
    int t_1, t_2;
    t_1 = hours*3600 + minutes*60 + seconds;
    t_2 = t.hours*3600 + t.minutes*60 + t.seconds;
    int result = t_1 - t_2;

    return result;
}