#include <cstring>
#include <iostream>
#include "Timing.h"
#include "Time.h"

using namespace std;

Timing::Timing() {
    setDay("Lundi");
    setStart(Time(15, 0));
    setDuration(Time(0, 25));
}

Timing::Timing(const Timing& t){
    setDay(t.getDay()); 

    setStart(t.getStart());
    setDuration(t.getDuration());
}

Timing::Timing(const string d,const Time s, const Time du)
{
    setDay(d);
    setStart(s);
    setDuration(du);
}

void Timing::display() const {
    cout << "Jour: " << day << endl;
    cout << "Start: " << start.getHour() << "h" << start.getMinute() << endl;
    cout << "Duration: " << duration.getHour() << "h" << duration.getMinute() << endl;
}

void Timing::setDay(const string d){
    day = d;
}

void Timing::setStart(const Time s){
    start.setHour(s.getHour());
    start.setMinute(s.getMinute());
}

void Timing::setDuration(const Time du){
    duration.setHour(du.getHour());
    duration.setMinute(du.getMinute());
}

string Timing::getDay() const {
    return day;
}

Time Timing::getStart() const {
    return start;
}

Time Timing::getDuration() const {
    return duration;
}