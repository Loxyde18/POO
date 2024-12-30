#ifndef TIMING_H
#define TIMING_H

#include <string>
#include "Time.h"
using namespace std;

namespace planning
{

    class Timing
    {

        friend ostream &operator<<(ostream &, const Timing &);
        friend istream &operator>>(istream &, Timing &);

    private:
        string day;
        Time start;
        Time duration;

        int compTiming(const Timing &);

    public:
        static const string MONDAY;
        static const string TUESDAY;
        static const string WEDNESDAY;
        static const string THURSDAY;
        static const string FRIDAY;
        static const string SATURDAY;
        static const string SUNDAY;

        Timing();

        Timing(string d, Time str, Time dur);

        Timing(const Timing &x);

        ~Timing();

        void setDay(string jour);

        void setStart(Time str);

        void setDuration(Time dur);

        const string getDay() const;

        Time getStart() const;

        Time getDuration() const;

        void display() const;

        int operator>(const Timing &);
        int operator<(const Timing &);
        int operator==(const Timing &);

        //utile
        int dayToInt(const Timing &);
        string toString();
    };
}
#endif
