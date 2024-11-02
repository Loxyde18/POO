#include "Schedulable.h"

Schedulable::Schedulable(){
    id = 0;
}

Schedulable::Schedulable(int h){
    id = h;
}

int Schedulable::getId() const{
    return id;
}

void Schedulable::setId(int d){
    id = d;
}