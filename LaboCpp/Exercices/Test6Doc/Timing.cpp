#include "Timing.h"

namespace planning
{
    const string Timing::MONDAY = "lundi";
    const string Timing::TUESDAY = "mardi";
    const string Timing::WEDNESDAY = "mercredi";
    const string Timing::THURSDAY = "jeudi";
    const string Timing::FRIDAY = "vendredi";
    const string Timing::SATURDAY = "samedi";
    const string Timing::SUNDAY = "dimanche";

    int Timing::jour() const
    {
        if (day == MONDAY)
            return 1;
        if (day == TUESDAY)
            return 2;
        if (day == WEDNESDAY)
            return 3;
        if (day == THURSDAY)
            return 4;
        if (day == FRIDAY)
            return 5;
        if (day == SATURDAY)
            return 6;
        if (day == SUNDAY)
            return 7;
        return -1;
    }

    Timing::Timing()
    {
        setDay("lundi");
        setStart(Time(15, 0));
        setDuration(Time(0, 25));
    }

    Timing::Timing(const Timing &t)
    {
        setDay(t.getDay());
        setStart(t.getStart());
        setDuration(t.getDuration());
    }

    Timing::Timing(const string d, const Time s, const Time du)
    {
        setDay(d);
        setStart(s);
        setDuration(du);
    }

    Timing::~Timing()
    {
    }

    void Timing::display() const
    {
        cout << "\nJour: " << day << endl;
        cout << "Start: ";
        start.display();
        cout << "\n";
        cout << "Duration: ";
        duration.display();
        cout << "\n";

        /*        if(start.getHour() > 9 && start.getMinute() > 9)
        {
            cout << "Start: " << start.getHour() << "h" << start.getMinute() << endl;
        }
        if(start.getHour() < 10 && start.getMinute() > 9)
        {
            cout << "Start: " << "0" << start.getHour() << "h" << start.getMinute() << endl;
        }
        else if(start.getHour() > 9 && start.getMinute() < 9)
        {
            cout << "Start: " << start.getHour() << "h" << start.getMinute() << "0" << endl;
        }
        else if(start.getHour() < 9 && start.getMinute() < 9)
        {
            cout << "Start: " << "0" << start.getHour() << "h" << start.getMinute() << "0" << endl;
        }


        if(duration.getHour() > 9 && duration.getMinute() > 9)
        {
            cout << "Durée: " << duration.getHour() << "h" << duration.getMinute() << endl;
        }
        if(duration.getHour() < 10 && duration.getMinute() > 9)
        {
            cout << "Durée: " << "0" << duration.getHour() << "h" << duration.getMinute() << endl;
        }
        else if(duration.getHour() > 9 && duration.getMinute() < 9)
        {
            cout << "Durée: " << duration.getHour() << "h" << duration.getMinute() << "0" << endl;
        }
        else if(duration.getHour() < 9 && duration.getMinute() < 9)
        {
            cout << "Durée: " << "0" << duration.getHour() << "h" << duration.getMinute() << "0" << endl;
        }*/
    }

    void Timing::setDay(const string d)
    {
        day = d;
    }

    void Timing::setStart(const Time s)
    {
        start.setHour(s.getHour());
        start.setMinute(s.getMinute());
    }

    void Timing::setDuration(const Time du)
    {
        duration.setHour(du.getHour());
        duration.setMinute(du.getMinute());
    }

    string Timing::getDay() const
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

    int Timing::operator>(const Timing &t)
    {
        return compH(t) == -1;
    }

    int Timing::operator<(const Timing &t)
    {
        return compH(t) == 1;
    }

    int Timing::operator==(const Timing &t)
    {
        return compH(t) == 0;
    }

    int Timing::compH(const Timing &t)
    {
        if (jour() < t.jour())
            return 1;
        if (jour() > t.jour())
            return -1;
        if (jour() == t.jour())
        {
            if (start < t.start)
                return 1;
            if (start > t.start)
                return -1;
            if (start == t.start)
            {
                if (duration < t.duration)
                    return 1;
                if (duration > t.duration)
                    return -1;
            }
        }
        return 0;
    }

    ostream &operator<<(ostream &s, const Timing &timing)
    {
        s << "<Timing>" << endl;
        s << "   <day>" << endl;
        s << "     " << timing.day << endl;
        s << "   </day>" << endl;
        s << "   <start>" << endl;
        s << "     " << timing.start << endl;
        s << "   </start>" << endl;
        s << "   <duration>" << endl;
        s << "     " << timing.duration << endl;
        s << "   </duration>" << endl;
        s << "</Timing>" << endl; //11
        return s;
    }

    istream &operator>>(istream &s, Timing &timing)
    {
        string line;

        getline(s, line); //1
        getline(s, line); //2
        getline(s, line); //3
        timing.day = line;
        getline(s, line); //4

        getline(s, line); //5
        getline(s, line); //6
        s >> timing.start;
        getline(s, line); //7

        getline(s, line); //8
        getline(s, line); //9
        s >> timing.duration;
        getline(s, line); //10

        getline(s, line); //11
        return s;
    }
}