#include "XmlFileSerializerException.h"
#include <cstring>
using namespace std;

template <typename T>
const char XmlFileSerializer<T>::READ = 'R';

template <typename T>
const char XmlFileSerializer<T>::WRITE = 'W';

template <typename T>
XmlFileSerializer<T>::XmlFileSerializer(const string &fn, char m, const string &cn)
{
    filename = fn;
    mode = m;
    collectionName = cn;
    string line;

    if(isWritable())
    {
        file.open(getFilename(), ios::out);
        file << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
        file << "<" << getCollectionName() << ">" << endl;
    }

    if(isReadable())
    {
        file.open(getFilename(), ios::in);
        if(!file.is_open())
            throw XmlFileSerializerException(XmlFileSerializerException::FILE_NOT_FOUND, "Fichié pas trouvé");
        getline(file, line);
        cout << line << endl;
        getline(file, line);
        line = line.substr(1,line.length() - 2);
        collectionName = line;
        cout << line << endl;
    }
}

template <typename T>
bool XmlFileSerializer<T>::isReadable(){
    if(mode == READ)
        return true;
    return false;
}

template <typename T>
bool XmlFileSerializer<T>::isWritable(){
    if(mode == WRITE)
        return true;
    return false;
}

template <typename T>
string XmlFileSerializer<T>::getFilename(){
    return filename;
}

template <typename T>
string XmlFileSerializer<T>::getCollectionName(){
    return collectionName;
}

template <typename T>
void XmlFileSerializer<T>::write(const T& val){
    if(mode == READ)
        throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Mode Read");
    file << val << endl;
}

template <typename T>
T XmlFileSerializer<T>::read(){
    string line;
    streampos posi;
    if(mode == WRITE)
        throw XmlFileSerializerException(XmlFileSerializerException::NOT_ALLOWED, "Mode Write");

    posi = file.tellg();

    file >> line;
    string collectionNameEnd = "</" + collectionName + ">";
    if(line == collectionNameEnd)
        throw XmlFileSerializerException(XmlFileSerializerException::END_OF_FILE, "Fin de ligne");
    
    file.seekg(posi);
    T obj;

    file >> obj;

    return obj;
}

template <typename T>
XmlFileSerializer<T>::~XmlFileSerializer(){
    file << "</" << getCollectionName() << ">" << endl;
    file.close();
}