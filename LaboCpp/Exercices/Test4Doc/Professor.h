#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
#include <string>
#include "Schedulable.h"

using namespace std;

class Professor : public Schedulable {
        friend ostream& operator<<(ostream&, const Professor&);
    private:
        string firstName;
        string lastName;
    public:
        Professor();
        ~Professor() = default;
        Professor(int, const string, const string);
        Professor(const Professor&) = default;
        string getLastName() const;
        string getFirstName() const;
        void setFirstName(const string);
        void setLastName(const string);
        string toString() const;
        string tuple() const;
        Professor& operator=(const Professor&);
};

#endif