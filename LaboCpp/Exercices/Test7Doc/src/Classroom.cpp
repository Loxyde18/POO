#include "Classroom.h"
#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

Classroom::Classroom() : Schedulable()
{
    setName("----");
    setSeatingCapacity(0);
};

Classroom::Classroom(int id, string name, int place):Schedulable(id)
{
    setName(name);
    setSeatingCapacity(place);
};

void Classroom::setSeatingCapacity(int x)
{
    if (x < 0)
        return;
    seatingCapacity = x;
    
}
void Classroom::setName(string name)
{
    if (name.empty())
        return;
    this->name = name;
    
}

int Classroom::getSeatingCapacity() const{
    return this->seatingCapacity;
}
string Classroom::getName() const{
    return this->name;
}

ostream& operator<<(ostream& s,const Classroom& x)
{
 
    s << "<Classroom>" << endl;
    s << "<id>" << endl;
    s << x.id  << endl;
    s << "</id>" << endl;
    s << "<name>" << endl;
    s << x.name << endl;
    s << "</name>" << endl;
    s << "<seatingCapacity>" << endl;
    s << x.seatingCapacity << endl;
    s << "</seatingCapacity>" << endl;
    s << "</Classroom>";
    return s;
}

istream &operator>>(istream &s, Classroom &x)
    {
        string line;

        getline(s,line); // <Classromm>
        getline(s,line); //   <id>
        getline(s,line); //     <variable>
        x.setId(stoi(line));
        getline(s,line); //   </id>
        getline(s,line); //   <name>
        getline(s,line); //    <variable>
        x.setName(line);
        getline(s,line); //   </name>
        getline(s,line); //   <seatingCapacity>
        getline(s,line); //   <variable>
        x.setSeatingCapacity(stoi(line));
        getline(s,line); //  </SeatingCapacity>
        getline(s,line); // </Classromm>

        return s;
    }

    string Classroom::toString() const {
        return this->name + "(" + to_string(this->seatingCapacity) + ")";

    }
    string Classroom::tuple() const {
        return to_string(id) + ";" + this->name + "(" +to_string(this->seatingCapacity) + ")";
        
    }