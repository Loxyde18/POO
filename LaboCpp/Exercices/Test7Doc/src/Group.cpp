#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;
#include "Group.h"

Group::Group():Schedulable()
{
    setName("---");
}
Group::Group(int id, string name):Schedulable(id)
{
    setName(name);
}

void Group::setName(string name)
{
    if(name.empty())
        return;
    this->name = name;
}

string Group::getName() const
 {
     return this->name;
 }

ostream& operator<<(ostream &s,const Group &x )
{
    return s << x.toString();
}
string Group::toString() const
{
    return name;
}

string Group::tuple() const
{
    return to_string(id) + ";" + name;
}
