#include "../header/ihabitat.h"
#include "../header/eagleHabitat.h"
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

void EagleHabitat::UpdateAge(int Id)
{
    IHabitat::UpdateAge(Id);
}
float EagleHabitat::getMeat()
{
    return IHabitat::getMeat();
}