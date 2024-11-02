#ifndef CLASSROOM_H
#define CLASSROOM_H
#include <iostream>
#include <string>
#include "Schedulable.h"

using namespace std;

class Classroom : public Schedulable {
        friend ostream& operator<<(ostream&, const Classroom&);
    private:
        string name;
        int seatingCapacity;
    public:
        Classroom();
        ~Classroom() = default;
        Classroom(int, const string, int);
        Classroom(const Classroom&) = default;
        string getName() const;
        int getSeatingCapacity();
        void setName(const string);
        void setSeatingCapacity(int);
        string toString() const;
        string tuple() const;
        Classroom& operator=(const Classroom&);
};

#endif