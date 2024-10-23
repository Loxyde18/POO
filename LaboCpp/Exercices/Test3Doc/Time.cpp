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
            cout << hours << "H" << minutes << endl;
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

    Time& Time::operator=(const Time& t)
    {
        hours = t.hours;
        minutes = t.minutes;
        cout << "feur" << endl;
        return (*this);
    }

    Time Time::operator+(int minutesAdd) const
    {
        Time resultat = *this;

		if(minutesAdd == 0)
		{
			return resultat;
		}

		resultat.minutes += minutesAdd;

        if (resultat.minutes >= 60)
        {
            resultat.hours += 1;
            resultat.minutes %= 60;
        }
    return resultat;
    }

    Time operator+(int minutesAdd, const Time& t)
    {
        Time resultat = t;
        resultat = resultat + minutesAdd;
        return resultat;
    }

    Time operator+(const Time& t1, const Time& t2)
    {
        Time resultat;
        
        resultat.hours = t1.hours + t2.hours;
        resultat.minutes = t1.minutes + t2.minutes;

        if (resultat.minutes >= 60)
        {
            resultat.hours += 1;
            resultat.minutes %= 60;
        }
        
        return resultat;
    }
    
} 