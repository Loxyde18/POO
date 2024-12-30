#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H

#include <cstring>
using namespace std;
class Schedulable
{
protected:
    int id;

public:
    Schedulable();
    Schedulable(int);
    Schedulable(const Schedulable&) = default;
    virtual ~Schedulable() = default;

    
    virtual string toString() const = 0;
    virtual string tuple() const = 0;


    void setId(int);
    int getId() const;


    void display() const;

};

#endif