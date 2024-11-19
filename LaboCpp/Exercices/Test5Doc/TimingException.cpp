#include "TimingException.h"

int TimingException::INVALID_DAY = 4;
int TimingException::NO_TIMING = 5;

TimingException::TimingException() : Exception(){
    code = 0;
}

TimingException::TimingException(int c, string msg) : Exception(msg){
    code = c;
}

void TimingException::setCode(int co){
    code = co;
}

int TimingException::getCode(){
    return code;
}