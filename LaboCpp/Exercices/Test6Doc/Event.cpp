#include "Event.h"

namespace planning
{
    int Event::currentCode = 1;

    Event::Event()
    {
        setCode(1);
        title = nullptr;
        setTitle("default");
        timing = nullptr;
    }

    Event::Event(int c, const char *t)
    {
        setCode(c);
        title = nullptr;
        setTitle(t);
        timing = nullptr;
    }

    Event::Event(const Event &e)
    {
        setCode(e.getCode());
        title = nullptr;
        setTitle(e.getTitle());
        timing = nullptr;
        if (e.timing != nullptr)
            timing = new Timing(*(e.timing));
    }

    Event::~Event()
    {
        delete title;
        delete timing;
    }

    void Event::display() const
    {
        cout << "title = " << title << endl;
        cout << "code = " << code << endl;
        if (timing != nullptr)
            timing->display();
    }

    int Event::getCode() const
    {
        return code;
    }

    const char *Event::getTitle() const
    {
        return title;
    }

    void Event::setTitle(const char *t)
    {
        if (title != nullptr)
            delete title;
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }

    void Event::setCode(int c)
    {
        if (c < 0)
            return;
        code = c;
    }

    void Event::setTiming(const Timing &temp)
    {
        if (timing != nullptr)
            delete timing;
        timing = new Timing(temp);
    }

    Timing Event::getTiming() const
    {
        return *timing;
    }

    ostream &operator<<(ostream &s, const Event &e)
    {
        s << "<Event>" << endl;
        s << "<code>" << endl;
        s << "" << e.code << endl;
        s << "</code>" << endl;
        s << "<title>" << endl;
        s << "" << e.title << endl;
        s << "</title>" << endl;
        if (e.timing != nullptr) 
        {
            s << "<timing>" << endl;
            s << *(e.timing); // Déférencement du pointeur pour accéder à l'objet Timing
            s << "</timing>" << endl;
        }
        s << "</Event>" << endl;
        return s;
    }

    istream &operator>>(istream &s, Event &e)
    {
        string line;
        getline(s, line); // <Event>
        
        getline(s, line); // <code>
        
        getline(s, line); // valeur de code
        
        e.code = stoi(line); // Convertit la ligne en entier

        getline(s, line); // </code>
        
        getline(s, line); // <title>
        
        getline(s, line); // valeur de title
        
        strcpy(e.title, line.c_str()); // donne la valeur de title du fichier dans la variable
        getline(s, line);              // </title>
        getline(s, line); //Si timing existe il va dans le if en dessous sinon il fait juste le getline du </Event>
        if (line == "<timing>")
        {
            Timing tmp;       // Temporaire pour lecture sécurisée
            s >> tmp;         // Lecture dans tmp
            e.setTiming(tmp); // Copie sécurisée dans l'objet `timing`
        }
        getline(s, line); // </Event>
        return s;
    }
}