#ifndef EVENT_H
#define EVENT_H
#include "Timing.h"
#include <iostream>
#include <string.h>
using namespace std;

namespace planning{
    class Event{
        friend ostream& operator<<(ostream&, const Event&);
        friend istream& operator>>(istream&, Event&);
    private:
        int code;
        char* title;
        Timing* timing;
    public:
        static int currentCode;
        Event();
        Event (int c, const char* t);
        Event (const Event& e);
        void display() const;
        int getCode() const;
        const char* getTitle() const;
        void setTitle(const char * t);
        void setCode (int c);
        void setTiming(const Timing& t);
        Timing getTiming() const;
        ~Event();
    };
}
#endif
