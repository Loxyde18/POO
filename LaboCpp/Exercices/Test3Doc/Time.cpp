#include "Time.h"

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

    //Opérateurs

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

    Time Time::operator-(int MinutesSou) const {

        Time resultat = *this;
        int Convert = resultat.hours * 60 + resultat.minutes;
        Convert -= MinutesSou;

        if (Convert < 0) 
        {
            Convert = abs(Convert);
        }

        resultat.hours = Convert / 60;
        resultat.minutes = Convert % 60;

        return resultat;
    }

    Time operator-(int MinutesSou, const Time& t)
    {
        Time resultat = t;
        resultat = resultat - MinutesSou;
        return resultat;
    }

    Time operator-(const Time& t1, const Time& t2)
    {
        Time resultat;

        resultat.hours = abs(t1.hours - t2.hours);
        resultat.minutes = abs(t1.minutes - t2.minutes);

        return resultat;
    }

    int Time::operator<(const Time& t2)
    {
        return compH(t2)==-1;
    }

    int Time::operator>(const Time& t2)
    {
        return compH(t2)== 1;
    }

    int Time::operator==(const Time& t2)
    {
        return compH(t2)== 0;
    }

    int Time::compH(const Time& t2)
    {
        Time resultat = t2;
        if (hours < resultat.hours) return -1;
        if (hours > resultat.hours) return 1;
        // même heures
        if (minutes < resultat.minutes) return -1;
        if (minutes > resultat.minutes) return 1;
        // minutes égales
        return 0;
    }

    istream& operator>>(istream& s, Time& t)
    {
        int h, m;
        do
        {
            cout << "Hours : ";
            s >> t.hours;
    
        } while(t.hours < 0 || t.hours >= 24);

        do
        {
            cout << "Minutes : ";
            s >> t.minutes;
        } while(t.minutes < 0 || t.minutes >= 60);

        return s;
    }

    ostream& operator<<(ostream& s, const Time& t)
    {
        if(t.hours > 9 && t.minutes > 9)
        {
            s << t.hours << "h" << t.minutes << endl;
        }
        else if(t.hours < 10 && t.minutes > 9)
        {
            s << "0" << t.hours << "h" << t.minutes << endl;
        }
        else if(t.hours > 9 && t.minutes < 9)
        {
            s << t.hours << "h" << "0" << t.minutes << endl;
        }
        else if(t.hours < 9 && t.minutes < 9)
        {
            s << "0" << t.hours << "h" << "0" << t.minutes << endl;
        }
        return s;
    }
} 