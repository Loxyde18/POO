#include "Classroom.h"

Classroom::Classroom() : Schedulable(){
    name = "0";
    seatingCapacity = 0;
}

Classroom::Classroom(int id, const string nom, int place) : Schedulable(id){
    name = nom;
    seatingCapacity = place;
}

string Classroom::getName() const{
    return name;
}

int Classroom::getSeatingCapacity(){
    return seatingCapacity;
}

void Classroom::setName(const string nom){
    name = nom;
}

void Classroom::setSeatingCapacity(int place){
    seatingCapacity = place;
}

ostream& operator<<(ostream& s, const Classroom& c){
    s << "\n" << "Name : " << c.name << "\n"  << "Place max : " << c.seatingCapacity << "\n" << "Id : " << c.id;
    return s;
}

string Classroom::toString() const {
    return "Classroom: id : " + to_string(id) + ", Name : " + name + ", Place max : " + to_string(seatingCapacity);
}

string Classroom::tuple() const {
    return "(" + to_string(id) + ", '" + name + "', " + to_string(seatingCapacity) + ")";
}

Classroom& Classroom::operator=(const Classroom& c){
    name = c.name;
    seatingCapacity = c.seatingCapacity;
    id = c.id;
    return(*this);
}