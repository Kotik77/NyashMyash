#ifndef DATE_H
#define DATE_H

#include <string>
#include <iostream>

using namespace std;

class Date{
    bool leapyear;
    int day, month, year;
    bool leap(int) const;
    int maxday() const;

public:
    Date(int d, int m, int y):leapyear(leap(y)),day(d),month(m),year(y){};
    Date& operator++(int);
    Date& operator--(int);
    string operator-(Date&) const;
    //bool operator==(Date&) const;
    //friend ostream& operator<<(ostream&, const Date&);
};
#endif DATE_H
