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

    Timing::Timing() {
        setDay("Lundi");
        setStart(Time(15, 0));
        setDuration(Time(0, 25));
    }

    Timing::Timing(const Timing& t){
        setDay(t.getDay()); 
        setStart(t.getStart());
        setDuration(t.getDuration());
    }

    Timing::Timing(const string d,const Time s, const Time du)
    {
        setDay(d);
        setStart(s);
        setDuration(du);
    }

    Timing::~Timing(){

    }
    
    void Timing::display() const {
        cout << "Jour: " << day << endl;
        cout << "Start: ";
        start.display();
        cout << "Duration: ";
        duration.display();

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

    void Timing::setDay(const string d){
        day = d;
    }

    void Timing::setStart(const Time s){
        start.setHour(s.getHour());
        start.setMinute(s.getMinute());
    }

    void Timing::setDuration(const Time du){
        duration.setHour(du.getHour());
        duration.setMinute(du.getMinute());
    }

    string Timing::getDay() const {
        return day;
    }

    Time Timing::getStart() const {
        return start;
    }

    Time Timing::getDuration() const {
        return duration;
    }
}
