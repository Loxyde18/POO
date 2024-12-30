#ifndef GROUP_H
#define GROUP_H
#include <cstring>
#include "Schedulable.h"

using namespace std;

class Group : public Schedulable
{
    friend ostream &operator<<(ostream&, const Group&);
private:
    string name;

public:
    Group();
    Group(int, string);
    Group(const Group &) = default;
    ~Group() = default;

    string toString() const override;
    string tuple() const override;

    void setName(string);
    string getName() const;
};

#endif
