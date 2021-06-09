#include "ianimal.h"
#include "aigle.h"
#include <iostream>
using namespace std;
Aigle::Aigle()
{

}

Aigle::Aigle(string name, string race, string gender)
    :IAnimal(name)
{
    IAnimal::SetRace(race);
    IAnimal::SetAge(6);
    IAnimal::SetGender(gender);
}

string Aigle::getName()
{
    cout << IAnimal::getName() << endl;
    return "";
}

string Aigle::getRace()
{
    cout << IAnimal::getRace() << endl;
    return "";
}

int Aigle::getAge()
{
    cout << IAnimal::getAge() << endl;
    return 0;
}

string Aigle::getGender()
{
    cout << IAnimal::getGender() << endl;
    return "";
}

void Aigle::UpdateAge()
{
    IAnimal::UpdateAge();
}