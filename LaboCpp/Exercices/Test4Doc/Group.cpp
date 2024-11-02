#include "Group.h"

Group::Group() : Schedulable(){
    name = "0";
}

Group::Group(int id, const string groupe) : Schedulable(id){
    name = groupe;
}

string Group::getName() const{
    return name;
}

void Group::setName(const string n){
    name = n;
}

ostream& operator<<(ostream& s, const Group& g){
    s << "\n" << "Name : " << g.name << "\n" << "Id : " << g.id;
    return s;
}

string Group::toString() const {
    return "Group: id : " + to_string(id) + ", Name : " + name;
}

string Group::tuple() const {
    return "(" + to_string(id) + ", '" + name + "' )";
}

Group& Group::operator=(const Group& g){
    name = g.name;
    id = g.id;
    return(*this);
}