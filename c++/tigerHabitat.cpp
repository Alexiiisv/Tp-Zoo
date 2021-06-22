#include "../header/ihabitat.h"
#include "../header/tigerHabitat.h"
#include <iostream>
using namespace std;
TigerHabitat::TigerHabitat()
{

}

TigerHabitat::TigerHabitat(string type)
    :IHabitat(type)
{
    IHabitat::SetCapacity(2);
}

int TigerHabitat::getCapacity()
{
    return IHabitat::getCapacity();
}

void TigerHabitat::getAnimal()
{
    IHabitat::getAnimal();
}

string TigerHabitat::getType()
{
    return IHabitat::getType();
}

void TigerHabitat::addAnimal(IAnimal *animal)
{
    IHabitat::addAnimal(animal);
}

void TigerHabitat::UpdateAge(int Id)
{
    IHabitat::UpdateAge(Id);
}
float TigerHabitat::getMeat()
{
    return IHabitat::getMeat();
}