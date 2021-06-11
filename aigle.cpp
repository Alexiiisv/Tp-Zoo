#include "ianimal.h"
#include "aigle.h"
#include <iostream>
using namespace std;
Aigle::Aigle(string name, string race, string gender, float food, int age)
    :IAnimal(name)
{
    IAnimal::SetRace(race);
    IAnimal::SetAge(age);
    IAnimal::SetGender(gender);
    IAnimal::SetFood(food);
}

string Aigle::getName()
{
    return IAnimal::getName();
}

string Aigle::getRace()
{
    return IAnimal::getRace();
}

int Aigle::getAge()
{
    return IAnimal::getAge();
}

string Aigle::getGender()
{
    return IAnimal::getGender();
}

void Aigle::UpdateAge()
{
    IAnimal::UpdateAge();
}

float Aigle::getFood()
{
    return IAnimal::getFood();
}