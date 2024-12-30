#include <stdlib.h>
#include <iostream>
#include <cstring>
using namespace std;

#include "Event.h"
#include "Timing.h"
#include "time.h"
#include "TimingException.h"
namespace planning
{
  int Event::currentCode = 1;

  Event::Event() // Constructeur d'initilisation
  {
    
    setCode(1);
    title = nullptr;
    setTitle("default");
    timing = nullptr;
  };

  Event::Event(int c, const char *t) // constructeur par défaut
  {
  
    setCode(c);
    title = nullptr;
    setTitle(t);
    timing = nullptr;
  };

  Event::Event(const Event &e) //constructeur de copie

  {
    
    setCode(e.getCode());
    title = nullptr;
    setTitle(e.getTitle());
    timing = new Timing(*(e.timing));
  };
  Event::~Event()
  { //destructeur
    
    delete title;
    if (timing != nullptr)
      delete timing;

  };

  const char *Event::getTitle() const
  {
    return title;
  }

  int Event::getCode() const
  {
    return code;
  }

  Timing Event::getTiming() const
  {

    if (timing == nullptr) 
      throw TimingException(TimingException::NO_TIMING, "Pas de TIMING !");
    return *timing;
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

  void Event::display() const
  {
    
    cout << "title = " << title << endl;
    cout << "code = " << code << endl;
    if (timing != nullptr)
      timing->display();
  }

  ostream &operator<<(ostream &s, const Event &x)
  {
    s << "<Event>" << endl;

    s << "<code>" << endl;
    s << x.code << endl;
    s << "</code>" << endl;

    s << "<title>" << endl;
    s << x.title << endl;
    s << "</title>" << endl;

    if (x.timing != nullptr) {
      s << "<timing>" << endl;
      s << *(x.timing); // Déférencement du pointeur pour accéder à l'objet Timing
      s << endl;
      s << "</timing>"<< endl;
    }
    s << "</Event>";

    return s;
  }

  istream &operator>>(istream &s, Event &x)
  {
    string line;

    getline(s, line); // <Event>

    getline(s, line);      //   <code>
    getline(s, line);      //     <variable>
    x.setCode(stoi(line)); // Convertit la ligne en int pour le code
    getline(s, line);      //   </code>

    getline(s, line);         //   <title>
    getline(s, line);         //     <variable>
    x.setTitle(line.c_str()); // Assigne le titre
    getline(s, line);         //   </title>
    getline(s, line);

    if (line == "<timing>")
    {  
      cout << "Lecture de Timing..." << endl;
      Timing tmp;
      s >> tmp;
      x.setTiming(tmp);

      getline(s, line);
      getline(s, line);
      
    }

    return s;
  }
  
  string Event::toString()
  {

    if (this->timing)
      return " | " + to_string(this->code) + " | " + this->title + " | " + this->timing->toString();
    else
      return " | " + to_string(this->code) + " | " + this->title + " | " " No Timing";
  }
}