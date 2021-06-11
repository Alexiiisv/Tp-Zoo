#ifndef EAGLEHABITAT_H
#define EAGLEHABITAT_H
#include <string>
#include "ihabitat.h"

using namespace std;

class EagleHabitat:public IHabitat
{
public:
    EagleHabitat();
    EagleHabitat(string type);
    virtual int getCapacity();
    virtual string getType();
};

#endif // EAGLEHABITAT_H
