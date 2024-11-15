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

    void Time::display() const
    {
        cout << (hours < 10 ? "0" : "") << hours << "h"
         << (minutes < 10 ? "0" : "") << minutes << endl;
    }

    
    int Time::getHour() const {
        return hours;
    }

    int Time::getMinute() const {
        return minutes;
    }

    void Time::setHour(int h) {
        if (h < 0 || h >= 24)
            throw TimeException(TimeException::INVALID_HOUR, "Heures pas comprisent entre 0 et 23");
        hours = h;
    }

    void Time::setMinute(int m) {
        if (m < 0 || m >= 60)
            throw TimeException(TimeException::INVALID_MINUTE, "Minutes pas comprisent entre 0 et 59");
        minutes = m;
    }

    Time& Time::operator=(const Time& t)
    {
        hours = t.hours;
        minutes = t.minutes;
        return (*this);
    }

    Time Time::operator+(int minutesAdd)
    {
        Time res;
        res = Time(hours*60+minutes+minutesAdd);
        return res;
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

    Time Time::operator-(int MinutesSou) const {
        Time res;
        res = Time(hours*60+minutes-MinutesSou);
        return res;
    }

    Time operator-(int MinutesSou, const Time& t)
    {
        return t - MinutesSou;
    }

    Time operator-(const Time &t1, const Time &t2)
    {

        int resultat;

        int minA = (t1.hours * 60) + t1.minutes;
        int minB = (t2.hours * 60) + t2.minutes;

        resultat = minA - minB; 
        return resultat;
    }

    int Time::operator>(const Time &t)
    {
        return compH(t) == -1;
    }

    int Time::operator<(const Time &t)
    {
        return compH(t) == 1;
    }

    int Time::operator==(const Time &t)
    {
        return compH(t) == 0;
    }

    int Time::compH(const Time &t)
    {
        if (hours < t.hours)
            return 1;
        if (hours > t.hours)
            return -1;

        if (minutes < t.minutes)
            return 1;
        if (minutes > t.minutes)
            return -1;

        //égalité
        return 0;
    }

    ostream &operator<<(ostream &s, const Time &t)
    {
        s << t.hours << "h" << t.minutes;
        return s;
    }

    istream& operator>>(istream& s, Time& t)
    {
        string heure;
        char milieu;
        int i = 0;

        s >> t.hours >> t.minutes;
        return s;
        /*
        do
        {
            if(i > 0)
            {
                cout << "Saisissez une heure : ";
            }

            s >> heure;
            stringstream convertisseur(heure);
            convertisseur >> t.hours >> milieu >> t.minutes;

            if (milieu == 'h' && t.hours >= 0 && t.hours < 24 && t.minutes >= 0 && t.minutes < 60) 
            {
                return s;
            }
            i++;
        } while (true);
        */
    }

    Time Time::operator++()
    {
        (*this) = (*this) + 1;
        return (*this);
    }

    Time Time::operator++(int)
    {
        Time t(*this);
        (*this) = (*this) + 1;
        return t;
    }

    Time Time::operator--()
    {
        (*this) = (*this) - 1;
        return (*this);
    }

    Time Time::operator--(int)
    {
        Time t(*this);
        (*this) = (*this) - 1;
        return t;
    }
} 