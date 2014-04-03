#ifndef TIMESTAMP_H
#define TIMESTAMP_H

class timeStamp{
    int hours, minutes, seconds;

public:
    timeStamp(){
        hours = 0;
        minutes = 0;
        seconds = 0;
    }
    timeStamp(int h, int m, int s){
        hours = h;
        minutes = m;
        seconds = s;
    }
    int operator-(timeStamp&) const;
};

#endif TIMESTAMP_H