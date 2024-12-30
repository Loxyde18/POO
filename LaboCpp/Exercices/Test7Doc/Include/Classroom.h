#ifndef CLASSROOM_H
#define CLASSROOM_H

#include<iostream>
#include <cstring>
#include "Schedulable.h"

using namespace std;


class Classroom : public Schedulable
{
    friend ostream& operator<<(ostream &, const Classroom&);
    friend istream& operator>>(istream&,Classroom&);

    

private:
    string name;
    int seatingCapacity;

public:
    Classroom();
    Classroom(int, string, int);
    Classroom(const Classroom &) = default;
    ~Classroom() = default;

    string toString() const override;
    string tuple() const override;

    void setSeatingCapacity(int);
    void setName(string);

    int getSeatingCapacity() const;
    string getName() const;
};

#endif