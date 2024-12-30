#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;
#include "Professor.h"



Professor::Professor():Schedulable()
{
    setFirstName("-----");
    setLastName("-----");
};

Professor::Professor(int id,string Nom,string Prenom):Schedulable(id)
{
    setFirstName(Prenom);
    setLastName(Nom);
};


void Professor::setFirstName(string name)
{
    if(name.empty())
        return;
    firstName = name;
}

void Professor::setLastName(string name)
{
    if(name.empty())
        return;
    lastName = name;
}

string Professor::getFirstName() const{
    return firstName;
}

string Professor::getLastName() const{
    return lastName;
}


ostream &operator<<(ostream& s, const Professor &x)
{
    s << x.toString();
    return s;
};


string Professor::toString() const{
    return lastName + " " + firstName;
};

string Professor::tuple() const{
    return to_string(id) + ";" + lastName + ";" + firstName;

};