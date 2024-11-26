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
    s << "<Classrom>" << endl;
    s << "   <id>" << endl;
    s << "     " << c.id << endl;
    s << "   </id>" << endl;
    s << "   <name>" << endl;
    s << "     " << c.name << endl;
    s << "   </name>" << endl;
    s << "   <seatingCapacity>" << endl;
    s << "     "<< c.seatingCapacity << endl;
    s << "   </seatingCapacity>" << endl;
    s << "</Classroom>" << endl; //11
    return s;
}

istream& operator>>(istream& s, Classroom& c){
    string line;

    getline(s, line); //1
    getline(s, line); //2
    getline(s, line); //3
    c.id = stoi(line);
    getline(s, line); //4

    getline(s, line); //5
    getline(s, line); //6
    c.name;
    getline(s,line); //7

    getline(s, line); //8
    getline(s, line); //9
    c.seatingCapacity = stoi(line);
    getline(s, line); //10

    getline(s, line); //11
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