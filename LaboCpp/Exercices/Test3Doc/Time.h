#ifndef TIME_H
#define TIME_H

namespace planning{
    class Time {
    friend Time operator+(int, const Time&);
    friend Time operator+(const Time&, const Time&);
    private :
        int hours;
        int minutes;
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
        Time& operator=(const Time&);
        Time operator+(int) const;
    };

}

#endif