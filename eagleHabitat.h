#ifndef EAGLEHABITAT_H
#define EAGLEHABITAT_H
#include <string>
#include "ihabitat.h"

using namespace std;

class EagleHabitat:public IHabitat
{
public:
    EagleHabitat();
    EagleHabitat(string type, int capa);
    virtual int getCapacity();
};

#endif // EAGLEHABITAT_H
