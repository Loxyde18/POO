#ifndef EVENT_H
#define EVENT_H
#include "Timing.h"

namespace planning
{
  class Event
  {

    friend ostream &operator<<(ostream &, const Event &);
    friend istream &operator>>(istream &, Event &);

  private:
    int code;
    char *title;
    Timing *timing;

  public:
    static int currentCode;
    Event(); // Constructeur d'initilisation

    Event(int c, const char *t); // constructeur par défaut

    Event(const Event &x); //constructeur de copie

    ~Event(); //destructeur

    //LES SET

    void setCode(int c);

    void setTitle(const char *t);

    void setTiming(const Timing &a);

    //LES GET

    int getCode() const;

    const char *getTitle() const;

    Timing getTiming() const;

    void display() const;
    string toString();
  };
}
#endif