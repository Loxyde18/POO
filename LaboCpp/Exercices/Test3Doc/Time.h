#include <cstring>
#include <iostream>
#ifndef TIME_H
#define TIME_H


using namespace std;
namespace planning{
    class Time {
        friend Time operator+(int, const Time&);
        friend Time operator+(const Time&, const Time&);
        friend Time operator-(int, const Time&);
        friend Time operator-(const Time&, const Time&);
        friend istream& operator>>(istream&, Time&);
        friend ostream& operator<<(ostream&, const Time&);
    private :
        int hours;
        int minutes;
        int compH(const Time&);
    public :
        Time();
        Time(int j);
        Time(int h, int m);
        Time(const Time& e);
        int getHour() const;
        int getMinute() const;
        void display() const;
        void setHour(int h);
        void setMinute(int m);
        ~Time();

        //Opérateur
        Time& operator=(const Time&);
        Time operator+(int) const;
        Time operator-(int) const;
        int operator<(const Time&);
        int operator>(const Time&);
        int operator==(const Time&);
    };

}

#endif