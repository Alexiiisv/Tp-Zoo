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
    cout << IHabitat::getCapacity() << endl;
    return 0;
}
