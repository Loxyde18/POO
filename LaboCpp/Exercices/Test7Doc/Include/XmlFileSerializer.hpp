#ifndef XMLFILESERIALIZER_H
#define XMLFILESERIALIZER_H

#include <fstream>
#include <string>

template<typename T>
class XmlFileSerializer{
    private:
    fstream file;
    string filename;
    char mode;
    string collectionName;

    public:
    static const char READ;
    static const char WRITE;
    //on met delete psk ils peuvent aller se faire foutre on en a pas besoin donc vous allez pas vous créer automatiquement bande de fdp
    XmlFileSerializer() = delete;
    XmlFileSerializer(const XmlFileSerializer&) = delete;
    //on met delete psk ils peuvent aller se faire foutre on en a pas besoin donc vous allez pas vous créer automatiquement bande de fdp
    XmlFileSerializer(const string &fn, char m, const string& cn = "entities");
    ~XmlFileSerializer();

    bool isReadable(); //ça lit ou pas fdp?
    bool isWritable(); //t'écris ou pas j'comprends pas la gros fdp?
    string getFilename(); //on veut le nom de ce gros connard de fichier, si c'est time/event etc
    string getCollectionName(); //On veut le nom de la premiere balise de con

    void write(const T&); //j'écris :nerd: :pointing_hands:
    T read();//je lis ou quoi fdp ?
};
#include "XmlFileSerializer.ipp"
#endif