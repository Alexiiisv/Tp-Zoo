#include <iostream>
#include "../header/ianimal.h"
#include "../header/coq.h"

using namespace std;

Coq::Coq(string name, string race, float food, int age)
    :IAnimal(name)
{
        IAnimal::SetRace(race);
        IAnimal::SetAge(age);
        IAnimal::SetFood(food);
        IAnimal::SetMaladeOnce(0);
        IAnimal::SetMalade(0, 1);
}
Coq::~Coq()
{

}

string Coq::getName()
{
    return IAnimal::getName();
}

string Coq::getRace()
{
    return IAnimal::getRace();
}

int Coq::getAge()
{
    return IAnimal::getAge();
}

string Coq::getGender()
{
    return IAnimal::getGender();
}

void Coq::UpdateAge()
{
    IAnimal::UpdateAge();
}

float Coq::getMeat()
{
    return IAnimal::getMeat();
}