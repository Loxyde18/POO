#ifndef TIMING_H
#define TIMING_H
#include <string>
#include <iostream>
#include "Time.h"
using namespace std;

namespace planning{
    class Timing
    {
    private :
        string day;
        Time start;
        Time duration;
    public :
        static const string MONDAY;
        static const string TUESDAY;
        static const string WEDNESDAY;
        static const string THURSDAY;
        static const string FRIDAY;
        static const string SATURDAY;
        static const string SUNDAY;
        Timing();
        ~Timing();
        void setDay(const string d);
        void setStart(const Time s);
        void setDuration(const Time du);
        Timing(const string d,const Time s, const Time du);
        Timing(const Timing& t);
        void display() const;
        string getDay() const;
        Time getStart() const;
        Time getDuration() const;
    };
}

#endif
