#include "Exception.h"

Exception::Exception(){
    setMessage("jsp");
}

Exception::Exception(string msg){
    setMessage(msg);
}

string Exception::getMessage() const{
    return message;
}

void Exception::setMessage(string m){
    message = m;
}