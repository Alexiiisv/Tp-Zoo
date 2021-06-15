#include "../header/ianimal.h"
#include <iostream>
using namespace std;

IAnimal::IAnimal(string name)
    : m_name(name)
{
}

IAnimal::~IAnimal()
{
    cout << "tamer" << endl;
}

string IAnimal::getName()
{
    return m_name;
}

string IAnimal::getRace()
{
    return m_race;
}

int IAnimal::getAge()
{
    return m_age;
}

float IAnimal::getFood()
{
    return m_food;
}

string IAnimal::getGender()
{
    return m_gender;
}

void IAnimal::SetFood(float food)
{
    m_food = food;
}
void IAnimal::SetRace(string race)
{
    m_race = race;
}

void IAnimal::SetAge(int Age)
{
    m_age = Age;
}

void IAnimal::SetGender(string gender)
{
    m_gender = gender;
}

void IAnimal::UpdateAge()
{
    m_age += 1;
}