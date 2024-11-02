#ifndef GROUP_H
#define GROUP_H
#include <iostream>
#include <string>
#include "Schedulable.h"

using namespace std;

class Group : public Schedulable {
        friend ostream& operator<<(ostream&, const Group&);
    private:
        string name;
    public:
        Group();
        ~Group() = default;
        Group(int, const string);
        Group(const Group&) = default;
        string getName() const;
        void setName(const string);
        string toString() const;
        string tuple() const;
        Group& operator=(const Group&);
};

#endif