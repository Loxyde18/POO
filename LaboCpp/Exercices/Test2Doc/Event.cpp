#include <cstring>
#include <iostream>
#include "Event.h"
#include "Time.h"
#include "Timing.h"

using namespace std;

Event::Event() {
    setCode(1);
    title = nullptr;
    setTitle("default");
    timing->setDay("Aucun");
    timing->setStart(Time(0,0));
    timing->setDuration(Time(0,0));
}

Event::Event(int c, const char* t, const Timing &temp) {
    setCode(c);
    title = nullptr;
    setTitle(t);
    timing->setDay(temp.getDay());
    timing->setStart(temp.getStart());
    timing->setDuration(temp.getDuration());
}

Event::Event(const Event& e)
{
    setCode(e.getCode());
    title = nullptr;
    setTitle(e.getTitle());
}

Event::~Event()
{
    delete title;
    delete timing;
}

void Event::display() const{
    cout << "title = " << title << endl;
    cout << "code = " << code << endl;
    timing->display();
}

int Event::getCode() const {
    return code;
}

const char* Event::getTitle() const {
    return title;
}

void Event::setTitle(const char * t) {
    if (title != nullptr) delete title;
    title = new char [strlen(t)+ 1];
    strcpy(title, t);
}

void Event::setCode(int c) {
    if (c < 0) return;
    code = c;
}

void Event::setTiming(const Timing& temp) {
    timing->setDay(temp.getDay());
    timing->setDay(temp.getDay());
    timing->setDay(temp.getDay());
}

Timing Event::getTiming() const {
    cout << "feur" << endl;
}