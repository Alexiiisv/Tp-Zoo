#include "ianimal.h"

IAnimal::IAnimal()
    :m_name("Animal sans Nom")
{

}

IAnimal::IAnimal(string name)
    :m_name(name)
{

}

IAnimal::~IAnimal()
{

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

void IAnimal::SetRace(string race)
{
    m_race = race;
}

void IAnimal::SetAge(int Age)
{
    m_age = Age;
}


void IAnimal::UpdateAge()
{
    m_age += 1;
}