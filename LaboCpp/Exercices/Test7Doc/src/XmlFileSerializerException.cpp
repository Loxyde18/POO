#include "XmlFileSerializerException.h"

int XmlFileSerializerException::NOT_ALLOWED = 30;
int XmlFileSerializerException::FILE_NOT_FOUND = 40;
int XmlFileSerializerException::END_OF_FILE = 50;

XmlFileSerializerException::XmlFileSerializerException()
{
    code = 0;
}

XmlFileSerializerException::XmlFileSerializerException(int c, string msg): Exception(msg)
{
    code = c;
}

void XmlFileSerializerException::setCode(int co)
{
    code = co;
}

int XmlFileSerializerException::getCode() const
{
    return code;
}