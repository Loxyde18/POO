#include "Exception.h"

Exception::Exception(){
    message = "vide";
}

Exception::Exception(string msg){
    message = msg;
}

string Exception::getMsg() const{
    return message;
}

void Exception::setMsg(string m){
    message = m;
}