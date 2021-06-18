#include "../header/ihabitat.h"
#include "../header/chickenHabitat.h"
#include <iostream>
using namespace std;
ChickenHabitat::ChickenHabitat()
{

}

ChickenHabitat::ChickenHabitat(string type)
    :IHabitat(type)
{
    IHabitat::SetCapacity(10);
}

int ChickenHabitat::getCapacity()
{
    return IHabitat::getCapacity();
}

void ChickenHabitat::getAnimal()
{
    IHabitat::getAnimal();
}

string ChickenHabitat::getType()
{
    return IHabitat::getType();
}

void ChickenHabitat::addAnimal(IAnimal *animal)
{
    IHabitat::addAnimal(animal);
}

void ChickenHabitat::UpdateAge(int Id)
{
    IHabitat::UpdateAge(Id);
}
float ChickenHabitat::getMeat()
{
    return IHabitat::getMeat();
}