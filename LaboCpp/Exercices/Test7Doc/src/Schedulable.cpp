#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;
#include "Schedulable.h"



Schedulable::Schedulable()
{
    setId(0);
};

Schedulable::Schedulable(int x)
{
    setId(x);
};


void Schedulable::setId(int x)
{
    if( x < 0)
        return;
    id = x;
}

int Schedulable::getId() const
{
    return this->id;
};