#ifndef EVENT_H
#define EVENT_H
#include "Timing.h"

class Event{
    private :
        int code;
        char* title;
        Timing* timing;
    public :
        Event();
        Event (int c, const char* t);
        Event (const Event& e);
        void display() const;
        int getCode() const;
        const char* getTitle() const;
        void setTitle(const char * t);
        void setCode (int c);
        void setTiming(Timing* t) const;
        void getTiming() const;
        ~Event();
};
#endif