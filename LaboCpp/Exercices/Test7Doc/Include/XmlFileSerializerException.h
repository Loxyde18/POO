#ifndef XMLFILESERIALIZEREXCEPTION_H
#define XMLFILESERIALIZEREXCEPTION_H

#include "Exception.h"


class XmlFileSerializerException : public Exception
{
    private:
        int code;
    public:
        static int NOT_ALLOWED;
        static int FILE_NOT_FOUND;
        static int END_OF_FILE;
        
        XmlFileSerializerException();
        XmlFileSerializerException(int, string);
        XmlFileSerializerException(const XmlFileSerializerException&) = default;
        int getCode() const;
        void setCode(int); 

};

#endif