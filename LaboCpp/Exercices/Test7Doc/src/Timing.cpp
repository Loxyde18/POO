#include <stdlib.h>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

#include "Timing.h"
#include "Time.h"
#include "TimingException.h"

namespace planning
{

    const string Timing::MONDAY = "Lundi";
    const string Timing::TUESDAY = "Mardi";
    const string Timing::WEDNESDAY = "Mercredi";
    const string Timing::THURSDAY = "Jeudi";
    const string Timing::FRIDAY = "Vendredi";
    const string Timing::SATURDAY = "Samedi";
    const string Timing::SUNDAY = "Dimanche";

    Timing::Timing()
    {

        setDay("Lundi");
        setStart(0);
        setDuration(0);
    };

    Timing::Timing(string d, Time str, Time dur)
    {
        setDay(d);
        setStart(str);
        setDuration(dur);
    };

    Timing::Timing(const Timing &x)
    {
        setDay(x.getDay());
        setStart(x.getStart());
        setDuration(x.getDuration());
    };

    Timing::~Timing(){
        //cout << "Destructeur" << endl;
    };

    void Timing::setDay(string jour)
    {
        if (jour.empty())
            throw TimingException(TimingException::INVALID_DAY, "Jour invalide !");

        if (jour == Timing::MONDAY)
        {
            day = "Lundi";
        }
        else if (jour == Timing::TUESDAY)
        {
            day = "Mardi";
        }
        else if (jour == Timing::WEDNESDAY)
        {
            day = "Mercredi";
        }
        else if (jour == Timing::THURSDAY)
        {
            day = "Jeudi";
        }
        else if (jour == Timing::FRIDAY)
        {
            day = "Vendredi";
        }
        else if (jour == Timing::SATURDAY)
        {
            day = "Samedi";
        }
        else if (jour == Timing::SUNDAY)
        {
            day = "Dimanche";
        }
        else
        {
            throw TimingException(TimingException::INVALID_DAY, "Jour invalide !");
            cout << "Jour non valide." << endl;
        }
    }

    void Timing::setStart(Time str)
    {
        start.setHour(str.getHour());
        start.setMinute(str.getMinute());
    }

    void Timing::setDuration(Time dur)
    {
        duration.setHour(dur.getHour());
        duration.setMinute(dur.getMinute());
    }

    const string Timing::getDay() const
    {
        return day;
    }

    Time Timing::getStart() const
    {
        return start;
    }

    Time Timing::getDuration() const
    {
        return duration;
    }

    void Timing::display() const
    {
        cout << endl
             << " Date :" << day << endl;
        cout << " Le début de l'évenement est à " << start.getHour() << ":" << start.getMinute() << "Heure" << endl;
        cout << " Le durée de l'évenement est de " << duration.getHour() << ":" << duration.getMinute() << "Heure" << endl;
    }

    int Timing::operator>(const Timing &x)
    {
        return compTiming(x) == -1;
    }
    int Timing::operator<(const Timing &x)
    {
        return compTiming(x) == 1;
    }
    int Timing::operator==(const Timing &x)
    {
        return compTiming(x) == 0;
    }
    int Timing::compTiming(const Timing &x)
    {
        //les jours

        if (dayToInt(*this) < dayToInt(x))
            return 1;
        if (day > x.day)
            return -1;

        // le debut
        if (start < x.start)
            return 1;
        if (start > x.start)
            return -1;

        //la durée
        if (duration < x.duration)
            return 1;
        if (duration > x.duration)
            return -1;

        //tt pareille
        return 0;
    }

    int Timing::dayToInt(const Timing &x)
    {
        if (x.day == "Lundi")
            return 1;
        if (x.day == "Mardi")
            return 2;
        if (x.day == "Mercredi")
            return 3;
        if (x.day == "Jeudi")
            return 4;
        if (x.day == "Vendredi")
            return 5;
        if (x.day == "Samedi")
            return 6;
        if (x.day == "Dimanche")
            return 7;
        return -1; //erreur
    }

    ostream &operator<<(ostream &s, const Timing &t)
    {
        s << "<Timing>" << endl;

        s << "<day>" << endl;
        s << t.day << endl;
        s << "</day>" << endl;

        s << "<start>" << endl;
        s << t.start << endl;
        s << "</start>" << endl;

        s << "<duration>" << endl;
        s << t.duration << endl;
        s << "</duration>" << endl;

        s << "</Timing>";

        return s;
    }

    istream &operator>>(istream &s, Timing &x)
    {
        string line;
        getline(s, line); // <timing>
        getline(s, line); //   <day>
        getline(s, line); //     <variable>
        x.setDay(line);
        getline(s, line); //   </day>
        getline(s, line); //   <start>
        s >> x.start;
        getline(s, line); //   </start>
        getline(s, line); //   <duration>
        s >> x.duration;
        getline(s, line); //  </duratin>
        getline(s, line); // </timing>

        return s;
    }

    string Timing::toString()
    {
        return " | " + day + " | " + "start " + start.toString() + " | " +"duration " + duration.toString();
    }
}