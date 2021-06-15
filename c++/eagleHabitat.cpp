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

// void EagleHabitat::delAnimal(int qtt)
// {
//     cout << "coucou" << endl;
//     if (EagleHabitat::getCapacity() < IHabitat::getnbrAnimals())
//     {
//         cout << "test" << endl;
//     }
    
//     IHabitat::delAnimal(qtt);
// }
void EagleHabitat::UpdateAge()
{
    IHabitat::UpdateAge();
}
float EagleHabitat::getFood()
{
    return IHabitat::getFood();
}