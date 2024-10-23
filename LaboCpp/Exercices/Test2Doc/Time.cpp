#include <cstring>
#include <iostream>
#include "Time.h"

using namespace std;
namespace planning{
    Time::Time()
    {
        setHour(11);
        setMinute(47);
    }

    Time::Time(int j) {
        setHour(j / 60);
        setMinute(j % 60);
    }

    Time::Time(int h, int m)
    {
        setHour(h);
        setMinute(m);
    }

    Time::~Time(){
    }

    Time::Time(const Time& e)
    {
        setHour(e.getHour());
        setMinute(e.getMinute());
    }

    void Time::display() const{
        if(hours > 9 && minutes > 9)
        {
            cout << hours << "h" << minutes << endl;
        }
        else if(hours < 10 && minutes > 9)
        {
            cout << "0" << hours << "h" << minutes << endl;
        }
        else if(hours > 9 && minutes < 9)
        {
            cout << hours << "h" << "0" << minutes << endl;
        }
        else if(hours < 9 && minutes < 9)
        {
            cout << "0" << hours << "h" << "0" << minutes << endl;
        } 
    }
    
    int Time::getHour() const {
        return hours;
    }

    int Time::getMinute() const {
        return minutes;
    }

    void Time::setHour(int h) {
        hours = h;
    }

    void Time::setMinute(int m) {
        minutes = m;
    }
}