#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

#include "Time.h"
#include "TimeException.h"
namespace planning
{

    Time::Time()
    {

        setHour(0);
        setMinute(0);
    };

    Time::Time(int h, int m)
    {
        setHour(h);
        setMinute(m);
    };

    Time::Time(int duree)
    {
        if (duree < 0)
            throw TimeException(TimeException::INVALID_MINUTE, "Negative duration is invalid!");

        setHour(duree / 60);
        setMinute(duree % 60);
    };

    Time::Time(const Time &x)
    {
        setHour(x.getHour());
        setMinute(x.getMinute());
    };

    Time::~Time(){
        //cout << "Destructeur" << endl;
    };

    void Time::setHour(int h)
    {
        if (h < 0 || h >= 24)
            throw TimeException(TimeException::INVALID_HOUR, "Invalid hour !");
        hour = h;
    };

    void Time::setMinute(int min)
    {
        if (min < 0 || min >= 60)
            throw TimeException(TimeException::INVALID_MINUTE, "Invalid Minute !");
        minute = min;
    }

    int Time::getHour() const
    {
        return hour;
    }

    int Time::getMinute() const
    {
        return minute;
    }

    void Time::display() const
    {
        if (minute == 0)
        {
            cout << "Il est actuellement " << hour << ":"
                 << "00" << endl;
        }
        else
        {
            cout << "Il est actuellement " << hour << ":" << minute << endl;
        }
    }

    const Time &Time::operator=(const Time &x)
    {
        hour = x.hour;
        minute = x.minute;
        return (*this);
    }

    Time Time::operator+(int minAdd)
    {
        return Time(hour * 60 + minute + minAdd);
    }

    Time operator+(int minAdd, Time x)
    {
        return (x + minAdd);
    }

    Time operator+(const Time &a, const Time &b)
    {
        Time d;

        int hourAdd = a.hour + b.hour;
        int minAdd = a.minute + b.minute;

        d.setMinute(minAdd);
        d.setHour(hourAdd);

        return d;
    }

    Time Time::operator-(int minAdd)
    {

        Time d;
        int totalMinutes = (hour * 60 + minute) - minAdd;

        d.setMinute(totalMinutes % 60);
        d.setHour(totalMinutes / 60);
        return Time(totalMinutes);
    }

    Time operator-(int minAdd, const Time &x)
    {
        Time d;

        int totalMinutes = ((x.hour * 60 + x.minute) - minAdd);

        d.setMinute(totalMinutes % 60);
        d.setHour(totalMinutes / 60);

        return d;
    }

    Time operator-(const Time &a, const Time &b)
    {
        Time d;

        int hourAdd = a.hour - b.hour;
        int minAdd = a.minute - b.minute;

        d.setMinute(minAdd);
        d.setHour(hourAdd);

        return d;
    }

    int Time::operator>(const Time &x)
    {
        return compTime(x) == -1;
    }

    int Time::operator<(const Time &x)
    {
        return compTime(x) == 1;
    }

    int Time::operator==(const Time &x)
    {
        return compTime(x) == 0;
    }

    int Time::compTime(const Time &x)
    {
        //comparaison des heure
        if (hour < x.hour)
            return 1;
        if (hour > x.hour)
            return -1;

        //comparaison des minute
        if (minute < x.minute)
            return 1;
        if (minute > x.minute)
            return -1;

        //égalité
        return 0;
    }

    Time Time::operator++()
    { //préincré la valeur change avant l'exé
        int min = (*this).minute;
        int heure = (*this).hour;

        int minTT = heure * 60 + min;

        if (minTT > (60 * 24))
            throw TimeException(TimeException::OVERFLOW, "Overflow !");

        (*this) = (*this) + 30;
        return (*this);
    }

    Time Time::operator++(int)
    { //postincré la valeur change apres l'execution
        int min = (*this).minute;
        int heure = (*this).hour;

        int minTT = heure * 60 + min;

        if (minTT > (60 * 24))
            throw TimeException(TimeException::OVERFLOW, "Overflow !");

        Time temp(*this);
        (*this) = (*this) + 30;

        return temp;
    }

    Time Time::operator--()
    { //préincré la valeur change avant l'exé
        int min = (*this).minute;
        int heure = (*this).hour;

        int minTT = heure * 60 + min;

        if (minTT < 0)
            throw TimeException(TimeException::OVERFLOW, "Overflow !");

        (*this) = (*this) - 30;

        return (*this);
    }

    Time Time::operator--(int)
    { //postincré la valeur change apres l'execution

        int min = (*this).minute;
        int heure = (*this).hour;

        int minTT = heure * 60 + min;

        if (minTT < 0)
            throw TimeException(TimeException::OVERFLOW, "Overflow !");

        Time temp(*this);
        (*this) = (*this) - 30;

        return temp;
    }

    ostream &operator<<(ostream &s, const Time &x)
    {
        s << "<Time>" << endl;
        s << "<hour>" << endl;
        s << x.hour << endl;
        s << "</hour>" << endl;
        s << "<minute>" << endl;
        s << x.minute << endl;
        s << "</minute>" << endl;
        s << "</Time>";
        return s;
    }

    istream &operator>>(istream &s, Time &x)
    {
        string line;

        getline(s, line); // <time>
        getline(s, line); //   <hour>
        getline(s, line); //     <variable>
        x.setHour(stoi(line));
        getline(s, line); //   </hour>
        getline(s, line); //   <minute>
        getline(s, line); //    <variable>
        x.setMinute(stoi(line));
        getline(s, line); //   <minute/>
        getline(s, line); //  </time>

        return s;
    }

    string Time::toString()
    {
        return " | " + to_string(hour) + "h" + to_string(minute);
    }
}
