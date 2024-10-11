#ifndef TIME_H
#define TIME_H

class Time {
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
};
#endif