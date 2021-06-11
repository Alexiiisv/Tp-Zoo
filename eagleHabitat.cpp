#include "ihabitat.h"
#include "eagleHabitat.h"
#include <iostream>
using namespace std;
EagleHabitat::EagleHabitat()
{

}

EagleHabitat::EagleHabitat(string type)
    :IHabitat(type)
{
    IHabitat::SetCapacity(4);
}

int EagleHabitat::getCapacity()
{
    return IHabitat::getCapacity();
}

string EagleHabitat::getType()
{
    return IHabitat::getType();
}
