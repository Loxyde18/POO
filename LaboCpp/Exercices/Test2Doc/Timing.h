#include <string>
#ifndef TIMING_H
#define TIMING_H
#include "Time.h"
using namespace std;

class Timing
{
    private :
        string day;
        Time start;
        Time duration;
    
    public :
        Timing();
        void setDay(const std::string d);
        void setStart(const Time s);
        void setDuration(const Time du);
        Timing(const string d,const Time s, const Time du);
        Timing(const Timing& t);
        void display() const;
        string getDay() const;
        Time getStart() const;
        Time getDuration() const;
};
#endif