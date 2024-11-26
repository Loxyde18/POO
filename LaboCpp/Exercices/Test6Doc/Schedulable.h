#ifndef SCHEDULABLE_H
#define SCHEDULABLE_H
#include <iostream>
#include <string>


using namespace std;

class Schedulable {
    protected:
        int id;
    public:
        Schedulable();
        ~Schedulable() = default;
        Schedulable(int);
        Schedulable(const Schedulable&) = default;
        int getId() const;
        void setId(int);

        virtual string toString() const = 0;
        virtual string tuple() const = 0;
};
#endif