#include "Professor.h"

Professor::Professor() : Schedulable() {
    firstName = "Default";
    lastName = "Default";
}

Professor::Professor(int id, const string First, const string Last) : Schedulable(id) {
    firstName = First;
    lastName = Last;
}

string Professor::getFirstName() const{
    return firstName;
}

string Professor::getLastName() const{
    return lastName;
}

void Professor::setFirstName(const string f){
    firstName = f;
}

void Professor::setLastName(const string l){
    lastName = l;
}

ostream& operator<<(ostream& s, const Professor& p){
    s << "\n" << "First Name : " << p.firstName << "\n" << "Last Name : " << p.lastName << "\n" << "Id : " << p.id;
    return s;
}

string Professor::toString() const {
    return "Professor: id : " + to_string(id) + ", First Name : " + firstName + ", Last Name : " + lastName;
}

string Professor::tuple() const {
    return "(" + to_string(id) + ", '" + firstName + "', '" + lastName + "')";
}

Professor& Professor::operator=(const Professor& p){
    firstName = p.firstName;
    lastName = p.lastName;
    id = p.id;

    return(*this);
}