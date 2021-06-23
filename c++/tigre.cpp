#include <iostream>
#include "../header/ianimal.h"
#include "../header/tigre.h"

using namespace std;

Tigre::Tigre(string name, string race, string gender, float food, int age)
    : IAnimal(name)
{
    IAnimal::SetRace(race);
    IAnimal::SetAge(age);
    IAnimal::SetGender(gender);
    IAnimal::SetFood(food);
    IAnimal::SetMaladeOnce(0);
    if ((gender == "Male" && age < 48) || age >= 168 || age < 48)
    {
        IAnimal::SetMalade(0, 0);
    }
    else
    {
        IAnimal::SetMalade(0, 1);
    }
}
Tigre::~Tigre()
{
}

string Tigre::getName()
{
    return IAnimal::getName();
}

string Tigre::getRace()
{
    return IAnimal::getRace();
}

int Tigre::getAge()
{
    return IAnimal::getAge();
}

string Tigre::getGender()
{
    return IAnimal::getGender();
}

void Tigre::UpdateAge()
{
    IAnimal::UpdateAge();
}

float Tigre::getMeat()
{
    return IAnimal::getMeat();
}