#include <iostream>
#include "../header/ianimal.h"
#include "../header/poule.h"

using namespace std;

Poule::Poule(string name, string race, float food, int age)
    :IAnimal(name)
{
        IAnimal::SetRace(race);
        IAnimal::SetAge(age);
        IAnimal::SetFood(food);
        IAnimal::SetMaladeOnce(0);
        IAnimal::SetMalade(0, 1);
}
Poule::~Poule()
{

}

string Poule::getName()
{
    return IAnimal::getName();
}

string Poule::getRace()
{
    return IAnimal::getRace();
}

int Poule::getAge()
{
    return IAnimal::getAge();
}

string Poule::getGender()
{
    return IAnimal::getGender();
}

void Poule::UpdateAge()
{
    IAnimal::UpdateAge();
}

float Poule::getMeat()
{
    return IAnimal::getMeat();
}