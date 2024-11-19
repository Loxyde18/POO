#include "Event.h"

namespace planning{
    int Event::currentCode = 1;

    Event::Event() {
        setCode(1);
        title = nullptr;
        setTitle("default");
        timing = nullptr;
    }

    Event::Event(int c, const char* t) {
        setCode(c);
        title = nullptr;
        setTitle(t);
        timing = nullptr;
    }

    Event::Event(const Event& e)
    {
        setCode(e.getCode());
        title = nullptr;
        setTitle(e.getTitle());
        timing = nullptr;
        if (e.timing != nullptr) timing = new Timing(*(e.timing));
    }

    Event::~Event()
    {
        delete title;
        delete timing;
    }

    void Event::display() const{
        cout << "title = " << title << endl;
        cout << "code = " << code << endl;
        if (timing != nullptr) timing->display();
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
        if(timing != nullptr) delete timing;
        timing = new Timing(temp);
    }

    Timing Event::getTiming() const {
        if(timing == nullptr)
        {
            throw TimingException(TimingException::NO_TIMING, "PAS DE TIMING");
        }
        return *timing;
    }
}