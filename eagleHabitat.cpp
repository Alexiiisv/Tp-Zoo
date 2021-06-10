#include "ihabitat.h"
#include "eagleHabitat.h"
#include <iostream>
using namespace std;
EagleHabitat::EagleHabitat()
{

}

EagleHabitat::EagleHabitat(string type, int capa)
    :IHabitat(type)
{
    IHabitat::SetCapacity(capa);
}

int EagleHabitat::getCapacity()
{
    cout << IHabitat::getCapacity() << endl;
    return 0;
}
