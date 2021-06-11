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

void EagleHabitat::getAnimal()
{
    IHabitat::getAnimal();
}

string EagleHabitat::getType()
{
    return IHabitat::getType();
}

void EagleHabitat::addAnimal(IAnimal *animal)
{
    IHabitat::addAnimal(animal);
}
